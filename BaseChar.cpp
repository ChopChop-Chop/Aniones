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

	_isJump = false;
	_isMove = false;
	_isHorizontalMove = false;
	_isVerticalMove = false;
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
		_speed = 0.1f;		// �̵��ӵ�
		_power = 2;		// ���ݷ�
		_hp = 10;			// hp
		break;
	case 2:
		_info->_id = 2;
		_info->_name = "���ֿ�";
		_info->_desc = "���� ���븦 ������ �ִ�.";
		_info->_meshDirectory = "resources/mesh/character/2.x";
		_speed = 0.5f;		// �̵��ӵ�
		_power = 1;		// ���ݷ�
		_hp = 5;			// hp
		break;
	case 3:
		_info->_id = 3;
		_info->_name = "����ȣ";
		_info->_desc = "�عٶ��!";
		_info->_meshDirectory = "resources/mesh/character/3.x";
		_speed = 0.2f;		// �̵��ӵ�
		_power = 1;		// ���ݷ�
		_hp = 7;			// hp
		break;
	case 4:
		_info->_id = 4;
		_info->_name = "������";
		_info->_desc = "�ִϿ��� ���̱� ������";
		_info->_meshDirectory = "resources/mesh/character/4.x";
		_speed = 0.1f;		// �̵��ӵ�
		_power = 2;		// ���ݷ�
		_hp = 8;			// hp
		break;
	case 5:
		_info->_id = 5;
		_info->_name = "������";
		_info->_desc = "������ ���븦 ������ �ִ�.";
		_info->_meshDirectory = "resources/mesh/character/5.x";
		_speed = 0.1f;		// �̵��ӵ�
		_power = 2;		// ���ݷ�
		_hp = 8;			// hp
		break;
	case 6:
		_info->_id = 6;
		_info->_name = "��α�";
		_info->_desc = "������ ���븦 ������ �ִ�22";
		_info->_meshDirectory = "resources/mesh/character/6.x";
		_speed = 0.3f;		// �̵��ӵ�
		_power = 2;		// ���ݷ�
		_hp = 10;			// hp
		break;
	case 7:
		_info->_id = 7;
		_info->_name = "�����";
		_info->_desc = "�����";
		_info->_meshDirectory = "resources/mesh/character/7.x";
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
	if (_isMove)
	{
		if (_isHorizontalMove)
			_model->setPosX(_model->getPosX() + (_h * _speed));
		if (_isVerticalMove)
			_model->setPosY(_model->getPosZ() + (_v * _speed));
	}

	if (!_isHorizontalMove)
	{
		if (_h > 0)
			_h -= 0.1;
		else if (_h < 0)
			_h += 0.1;
	}
	if (!_isVerticalMove)
	{
		if (_v > 0)
			_v -= 0.1;
		else if (_v < 0)
			_v += 0.1;
	}
}