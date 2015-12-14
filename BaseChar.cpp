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
		_info->_name = "������";
		_info->_desc = "Ŀ�ٶ� ���븦 ������ �ִ�.";
		_info->_meshDirectory = "resources/mesh/character/1.x"; 
		_attackDelay = 1000;
		_speed = 1.f;		// �̵��ӵ�
		_power = 2;		// ���ݷ�
		_hp = 10;			// hp
		break;
	case 2:
		_info->_id = 2;
		_info->_name = "���ֿ�";
		_info->_desc = "���� ���븦 ������ �ִ�.";
		_info->_meshDirectory = "resources/mesh/character/2.x";
		_attackDelay = 500;
		_speed = 0.5f;		// �̵��ӵ�
		_power = 1;		// ���ݷ�
		_hp = 5;			// hp
		break;
	case 3:
		_info->_id = 3;
		_info->_name = "����ȣ";
		_info->_desc = "�عٶ��!";
		_info->_meshDirectory = "resources/mesh/character/3.x";
		_attackDelay = 750;
		_speed = 0.2f;		// �̵��ӵ�
		_power = 1;		// ���ݷ�
		_hp = 7;			// hp
		break;
	case 4:
		_info->_id = 4;
		_info->_name = "������";
		_info->_desc = "�ִϿ��� ���̱� ������";
		_info->_meshDirectory = "resources/mesh/character/4.x";
		_attackDelay = 800;
		_speed = 0.1f;		// �̵��ӵ�
		_power = 2;		// ���ݷ�
		_hp = 8;			// hp
		break;
	case 5:
		_info->_id = 5;
		_info->_name = "������";
		_info->_desc = "������ ���븦 ������ �ִ�.";
		_info->_meshDirectory = "resources/mesh/character/5.x";
		_attackDelay = 850;
		_speed = 0.1f;		// �̵��ӵ�
		_power = 2;		// ���ݷ�
		_hp = 8;			// hp
		break;
	case 6:
		_info->_id = 6;
		_info->_name = "��α�";
		_info->_desc = "������ ���븦 ������ �ִ�22";
		_info->_meshDirectory = "resources/mesh/character/6.x";
		_attackDelay = 600;
		_speed = 0.3f;		// �̵��ӵ�
		_power = 2;		// ���ݷ�
		_hp = 10;			// hp
		break;
	case 7:
		_info->_id = 7;
		_info->_name = "�����";
		_info->_desc = "�����";
		_info->_meshDirectory = "resources/mesh/character/7.x";
		_attackDelay = 700;
		_speed = 0.2f;		// �̵��ӵ�
		_power = 1;		// ���ݷ�
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