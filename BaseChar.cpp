#include "BaseChar.h"


CBaseChar::CBaseChar()
{
	_model = new CMesh();
	_info = new CharInfo();

	_speed = 0;		
	_power = 0;	
	_hp = 0;			

	_h = 0;
	_v = 0;

	_isMove = false;
	_isAttack = false;
	_isHurt = false;
}


CBaseChar::~CBaseChar()
{
}

void CBaseChar::Init(int id)
{
	
	switch (id)
	{
	case 1:
		_info->_id = 1;
		_info->_name = "김종민";
		_info->_desc = "커다란 떡대를 가지고 있다.";
		_info->_meshDirectory = "resources/mesh/character/1.x"; 
		_attackDelay = 1000;
		_speed = 1.f;		// 이동속도
		_power = 2;		// 공격력
		_hp = 10;			// hp
		break;
	case 2:
		_info->_id = 2;
		_info->_name = "서주원";
		_info->_desc = "작은 떡대를 가지고 있다.";
		_info->_meshDirectory = "resources/mesh/character/2.x";
		_attackDelay = 500;
		_speed = 0.5f;		// 이동속도
		_power = 1;		// 공격력
		_hp = 5;			// hp
		break;
	case 3:
		_info->_id = 3;
		_info->_name = "조해호";
		_info->_desc = "해바라기!";
		_info->_meshDirectory = "resources/mesh/character/3.x";
		_attackDelay = 750;
		_speed = 0.2f;		// 이동속도
		_power = 1;		// 공격력
		_hp = 7;			// hp
		break;
	case 4:
		_info->_id = 4;
		_info->_name = "윤진근";
		_info->_desc = "애니원고 십이기 윤진근";
		_info->_meshDirectory = "resources/mesh/character/4.x";
		_attackDelay = 800;
		_speed = 0.1f;		// 이동속도
		_power = 2;		// 공격력
		_hp = 8;			// hp
		break;
	case 5:
		_info->_id = 5;
		_info->_name = "김정우";
		_info->_desc = "빡빡한 떡대를 가지고 있다.";
		_info->_meshDirectory = "resources/mesh/character/5.x";
		_attackDelay = 850;
		_speed = 0.1f;		// 이동속도
		_power = 2;		// 공격력
		_hp = 8;			// hp
		break;
	case 6:
		_info->_id = 6;
		_info->_name = "김민규";
		_info->_desc = "빡빡한 떡대를 가지고 있다22";
		_info->_meshDirectory = "resources/mesh/character/6.x";
		_attackDelay = 600;
		_speed = 0.3f;		// 이동속도
		_power = 2;		// 공격력
		_hp = 10;			// hp
		break;
	case 7:
		_info->_id = 7;
		_info->_name = "조경수";
		_info->_desc = "경수다";
		_info->_meshDirectory = "resources/mesh/character/7.x";
		_attackDelay = 700;
		_speed = 0.2f;		// 이동속도
		_power = 1;		// 공격력
		_hp = 7;			// hp
		break;
	default:
		MessageBox(NULL, "Error", "UndefinedID", MB_OK);
		break;
	}
	_model->Init(_info->_meshDirectory.c_str());

	addChild(_model);
}
void CBaseChar::Update()
{
	D3DXVECTOR3 front = _lookDirection;
	D3DXVECTOR3 back = -_lookDirection;
	D3DXVECTOR3 left = D3DXVECTOR3(-_lookDirection.z, 0, _lookDirection.x);
	D3DXVECTOR3 right = -left;
	
	D3DXVec3Normalize(&front, &front);
	D3DXVec3Normalize(&back, &back);
	D3DXVec3Normalize(&right, &right);
	D3DXVec3Normalize(&left, &left);
	if (_isMove)
	{
		if (_h == 1)
			_model->setPos(_model->getPos() + (right * _speed));

		else if (_h == -1)
			_model->setPos(_model->getPos() + (left * _speed));

		if (_v == 1)
			_model->setPos(_model->getPos() + (front * _speed));

		else if (_v == -1)
			_model->setPos(_model->getPos() + (back * _speed));
	}
	if (_hp <= 0)
	{
		_visible = false;
	}

}