#include "S_Game.h"
#include "Director.h"


S_Game::S_Game()
{
}


S_Game::~S_Game()
{
	delete _crosshair;
	delete _map;
	delete _enemy;
	delete _player;
}

bool S_Game::Init()
{
	_player = new CBaseChar();
	_player->Init(1);
	_player->getModel()->setDegreeY(180);
	addChild(_player , 0);

	_enemy = new CBaseChar();
	_enemy->Init(6);
	_enemy->getModel()->setPos(0, 0, 100);
	addChild(_enemy);

	_map = new CMesh();
	_map->Init("resources/mesh/map.x");
	_map->setPos(0, 0, 0);
	addChild(_map);

	_crosshair = new CSprite();
	_crosshair->Init("resources/image/ui/crosshair_0.png");
	_crosshair->addTexture("resources/image/ui/crosshair_1.png");
	_crosshair->setPos(1280 / 2, 420 / 2);
	addChild(_crosshair);


	CDrawMgr->m_pCurCamera->setActive(true);
	CDrawMgr->m_pCurCamera->setPos(D3DXVECTOR3(0, 70, -200));
	CDrawMgr->m_pCurCamera->setLookatY(50);

	_degree = -90;		// 앞을 보는 default 각도

	_nowTime = 0;

	addChild(CBulletMgr);

	return true;
}
void S_Game::Update()
{
	_nowTime = timeGetTime();

	CDrawMgr->m_pCurCamera->setLookat(_player->getModel()->getPos());
	CDrawMgr->m_pCurCamera->setLookatY(50);
	CameraUpdate();
	CDrawMgr->m_pCurCamera->Update();


	_player->Update();
	CBulletMgr->Update();
	BoundUpdate();
}
void S_Game::BoundUpdate()
{
	for (int i = 0; i < CBulletMgr->getMAXBULLET(); i++)
	{
		if (CBulletMgr->getBulletIndex1(i)->isVisible())
		{
			if (CColMgr->PointToPoint(&CBulletMgr->getBulletIndex1(i)->getMesh()->getPos(),
				&_enemy->getModel()->getPos(), 5))		// enemy-> enemy 배열로
			{
				std::cout << "충돌 ! " << std::endl;
				_enemy->setHP(_enemy->getHP() - _player->getPower());
				CBulletMgr->getBulletIndex1(i)->setVisible(false);
			}
		}
	}
}
void S_Game::CameraUpdate()
{
	POINT _pos;

	GetCursorPos(&_pos);
	_curMousePos.x = _pos.x;
	_curMousePos.y = _pos.y;

	/*if (_curMousePos != _oldMousePos)
	{
		if (_curMousePos.x > _oldMousePos.x)
			_mouseState = MOVERIGHT;
		else if (_curMousePos.x < _oldMousePos.x)
			_mouseState = MOVELEFT;

		_oldMousePos = _curMousePos;
	}
	else
		_mouseState = IDLE;*/

	if (_curMousePos.x > 1280 - 300)
	{
		_mouseState = MOVERIGHT;
	}
	else if (_curMousePos.x < 1280 - 300
		&& _curMousePos.x > 300)
	{
		_mouseState = IDLE;
	}
	else if (_curMousePos.x < 300)
	{
		_mouseState = MOVELEFT;
	}

	switch (_mouseState)
	{
	case IDLE:
		break;
	case MOVERIGHT:
		_degree -= 1;
		_player->getModel()->setDegreeY(_player->getModel()->getDegreeY() + 1);
		break;
	case MOVELEFT:
		_degree += 1;
		_player->getModel()->setDegreeY(_player->getModel()->getDegreeY() - 1);
		break;
	}


	CDrawMgr->m_pCurCamera->setPosX(_player->getModel()->getPosX() + (cos(_degree * 3.14159265 / 180)) * 100);
	CDrawMgr->m_pCurCamera->setPosZ(_player->getModel()->getPosZ() + (sin(_degree * 3.14159265 / 180)) * 100);

	D3DXVECTOR3 __look = _player->getModel()->getPos() - CDrawMgr->m_pCurCamera->getPos(); 
	__look.y = 0;
	D3DXVec3Normalize(&__look, &__look);

	_player->setLookDirection(__look);
	
}
void S_Game::KeyDown(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (wParam)
	{
	case VK_LEFT:
	case 'a':
	case 'A':
		_player->setIsMove(true);
		_player->setHorizontal(-1);
		break;
	case VK_RIGHT:
	case 'd':
	case 'D':
		_player->setIsMove(true);
		_player->setHorizontal(1);
		break;
	case VK_UP:
	case 'w':
	case 'W':
		_player->setIsMove(true);
		_player->setVertical(1);
		break;
	case VK_DOWN:
	case 's':
	case 'S':
		_player->setIsMove(true);
		_player->setVertical(-1);
		break;
	case VK_SHIFT:
		break;
	}
}
void S_Game::KeyUp(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (wParam)
	{
	case VK_LEFT:
	case VK_RIGHT:
		_player->setHorizontal(0);
		break;
	case VK_UP:
	case VK_DOWN:
		_player->setVertical(0);
		break;
	}
}

void S_Game::LButtonDown(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	_crosshair->setNowAni(1);
	
	if (_nowTime - _oldTime >= _player->getAttackDelay())
	{
		_oldTime = timeGetTime();

		CBulletMgr->Create(_player->getModel()->getPos(), 
			_player->getLookDirection(), 10, 500, BulletOwner::Friend);
	}
}
void S_Game::LButtonUp(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	_crosshair->setNowAni(0);

	std::cout << "MousePos : " << "[" << CDIRECTOR->getMouseX() << ", " << CDIRECTOR->getMouseY() << "]" << std::endl;

}