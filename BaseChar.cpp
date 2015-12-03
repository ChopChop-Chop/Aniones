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
		_info->_name = "김종민";
		_info->_desc = "커다란 떡대를 가지고 있다.";
		_info->_meshDirectory = "resources/mesh/character/1.x"; 
		_speed = 0.1f;		// 이동속도
		_power = 2;		// 공격력
		_hp = 10;			// hp
		break;
	case 2:
		_info->_id = 2;
		_info->_name = "서주원";
		_info->_desc = "작은 떡대를 가지고 있다.";
		_info->_meshDirectory = "resources/mesh/character/2.x";
		_speed = 0.5f;		// 이동속도
		_power = 1;		// 공격력
		_hp = 5;			// hp
		break;
	case 3:
		_info->_id = 3;
		_info->_name = "조해호";
		_info->_desc = "해바라기!";
		_info->_meshDirectory = "resources/mesh/character/3.x";
		_speed = 0.2f;		// 이동속도
		_power = 1;		// 공격력
		_hp = 7;			// hp
		break;
	case 4:
		_info->_id = 4;
		_info->_name = "윤진근";
		_info->_desc = "애니원고 십이기 윤진근";
		_info->_meshDirectory = "resources/mesh/character/4.x";
		_speed = 0.1f;		// 이동속도
		_power = 2;		// 공격력
		_hp = 8;			// hp
		break;
	case 5:
		_info->_id = 5;
		_info->_name = "김정우";
		_info->_desc = "빡빡한 떡대를 가지고 있다.";
		_info->_meshDirectory = "resources/mesh/character/5.x";
		_speed = 0.1f;		// 이동속도
		_power = 2;		// 공격력
		_hp = 8;			// hp
		break;
	case 6:
		_info->_id = 6;
		_info->_name = "김민규";
		_info->_desc = "빡빡한 떡대를 가지고 있다22";
		_info->_meshDirectory = "resources/mesh/character/6.x";
		_speed = 0.3f;		// 이동속도
		_power = 2;		// 공격력
		_hp = 10;			// hp
		break;
	case 7:
		_info->_id = 7;
		_info->_name = "조경수";
		_info->_desc = "경수다";
		_info->_meshDirectory = "resources/mesh/character/7.x";
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