#include "Bullet.h"


CBullet::CBullet()
{
	_model = new CMesh();

	_targetDirection = D3DXVECTOR3(0, 0, 0);
	_speed = 5.0f;
	_visible = false;
	_distance = 50;
}


CBullet::~CBullet()
{
}

bool CBullet::Init()
{
	_model->Init("resources/mesh/snow.x");
	_model->setPosY(50);
	addChild(_model);
	return true;
}
void CBullet::Create(D3DXVECTOR3 pos, D3DXVECTOR3 target, float speed, float distance)
{
	if (_visible)
	{
		MessageBox(NULL, "I'm Already Created", "yes", MB_OK);
		return;
	}

	//float __targetZ = 0;
	//float __targetX = 0;

	///*if (target.z > pos.z)
	//{
	//	__targetZ = target.z - pos.z;
	//}
	//else if (target.z < pos.z)
	//{
	//	__targetZ = pos.z - target.z;
	//}
	//if (target.x > pos.x)
	//{
	//	__targetX = target.x - pos.x;
	//}
	//else if (target.x < pos.x)
	//{
	//	__targetX = pos.x - target.x;
	//}*/
	//_targetDirection = D3DXVECTOR3(__targetX, 0, __targetZ);

	_targetDirection = target;

	_model->setPos(pos);
	_model->setPosY(50);
	D3DXVec3Normalize(&_targetDirection, &_targetDirection);
	_speed = speed;
	_distance = distance;
	_movedDistance = 0;
	_visible = true;

}
void CBullet::Update()
{
	if (!_visible)
	{
		return;
	}

	_model->setPos(_model->getPos() + (_targetDirection * _speed));

	_movedDistance += _speed;

	if (_movedDistance > _distance)
	{
		_visible = false;
	}

}