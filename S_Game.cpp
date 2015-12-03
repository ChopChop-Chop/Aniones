#include "S_Game.h"
#include "Director.h"


S_Game::S_Game()
{
}


S_Game::~S_Game()
{
}

bool S_Game::Init()
{
	_player = new CBaseChar();
	_player->Init(1);
	_player->getModel()->setDegreeY(180);
	addChild(_player , 0);

	CDrawMgr->m_pCurCamera->setActive(true);
	CDrawMgr->m_pCurCamera->setPos(D3DXVECTOR3(0, 70, -200));
	CDrawMgr->m_pCurCamera->setLookatY(50);

	_degree = 0;

	return true;
}
void S_Game::Update()
{
	//CDrawMgr->m_pCurCamera->setPosX(_player->getModel()->getPosX());
	//CDrawMgr->m_pCurCamera->setPosZ(_player->getModel()->getPosZ() - 200);
	CDrawMgr->m_pCurCamera->setLookat(_player->getModel()->getPos());
	CDrawMgr->m_pCurCamera->setLookatY(50);
	CDrawMgr->m_pCurCamera->Update();
	_player->Update();
	CameraUpdate();
}

void S_Game::CameraUpdate()
{
	POINT _pos;

	GetCursorPos(&_pos);
	_curMousePos.x = _pos.x;
	_curMousePos.y = _pos.y;

	if (_curMousePos != _oldMousePos)
	{
		if (_curMousePos.x > _oldMousePos.x)
			_mouseState = MOVERIGHT;
		else if (_curMousePos.x < _oldMousePos.x)
			_mouseState = MOVELEFT;

		_oldMousePos = _curMousePos;
	}
	else
		_mouseState = IDLE;

	switch (_mouseState)
	{
	case IDLE:
		break;
	case MOVERIGHT:
		_degree += 1;
		break;
	case MOVELEFT:
		_degree -= 1;
		break;
	}


	CDrawMgr->m_pCurCamera->setPosX((cos(_degree* 3.14159265 / 180)) * 100);
	CDrawMgr->m_pCurCamera->setPosZ((sin(_degree * 3.14159265 / 180)) * 100);
	
}
void S_Game::KeyDown(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (wParam)
	{
	case VK_LEFT:
		_player->moveLeft();
		break;
	case VK_RIGHT:
		_player->moveRight();
		break;
	case VK_UP:
		_player->moveForword();
		break;
	case VK_DOWN:
		_player->moveBack();
		break;

	}
}
void S_Game::KeyUp(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (wParam)
	{
	case VK_LEFT:
	case VK_RIGHT:
		_player->setIsMove(false);
		_player->setIsHorizontalMove(false);
		break;
	case VK_UP:
	case VK_DOWN:
		_player->setIsMove(false);
		_player->setIsVerticalMove(false);
		break;
	}
}