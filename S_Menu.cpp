#include "S_Menu.h"
#include "Director.h"


S_Menu::S_Menu()
{
}


S_Menu::~S_Menu()
{
	delete _cursor;
	delete _exit;
	delete _credit;
	delete _start;
	delete _backGround;
}

bool S_Menu::Init()
{
	_backGround = new CSprite();
	_backGround->Init("resources/image/s_menu/bg.png");
	_backGround->setAcp(0, 0);
	_backGround->setPos(0, 0);
	addChild(_backGround, -1);

	_start = new CSprite();
	_start->Init("resources/image/s_menu/start_off.png");
	_start->addTexture("resources/image/s_menu/start_on.png");
	_start->setPos(1600, 300);
	addChild(_start);

	_credit = new CSprite();
	_credit->Init("resources/image/s_menu/credit_off.png");
	_credit->addTexture("resources/image/s_menu/credit_on.png");
	_credit->setPos(1600, 410);
	addChild(_credit);

	_exit = new CSprite();
	_exit->Init("resources/image/s_menu/exit_off.png");
	_exit->addTexture("resources/image/s_menu/exit_on.png");
	_exit->setPos(1600, 520);
	addChild(_exit);

	_cursor = new CSprite();
	_cursor->Init("resources/image/ui/cursor_off.png");
	_cursor->addTexture("resources/image/ui/cursor_on.png");
	_cursor->setPos(-1280 / 2, -720 / 2);
	addChild(_cursor, 1);

	return true;
}
void S_Menu::Update()
{
	_cursor->setPos(CDIRECTOR->getMouseX(), CDIRECTOR->getMouseY());

	if (_start->getPosX() > 1000)
	{
		_start->setPosX(_start->getPosX() - 10);
	}
	if (_credit->getPosX() > 1000)
	{
		_credit->setPosX(_credit->getPosX() - 9);
	}
	if (_exit->getPosX() > 1000)
	{
		_exit->setPosX(_exit->getPosX() - 8);
	}
}

void S_Menu::LButtonDown(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	_cursor->setNowAni(1);

	if (CColMgr->PointToSprite(_cursor->getPos(), _start))
	{
		_start->setNowAni(1);
	}
	if (CColMgr->PointToSprite(_cursor->getPos(), _credit))
	{
		_credit->setNowAni(1);
	}
	if (CColMgr->PointToSprite(_cursor->getPos(), _exit))
	{
		_exit->setNowAni(1);
	}
}
void S_Menu::LButtonUp(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	_cursor->setNowAni(0);
	_start->setNowAni(0);
	_credit->setNowAni(0);
	_exit->setNowAni(0);
	if (CColMgr->PointToSprite(_cursor->getPos(), _start))
	{
		// TODO : ¾À ÀÌµ¿
	}
	if (CColMgr->PointToSprite(_cursor->getPos(), _credit))
	{
		// TODO : ¾À ÀÌµ¿
	}
	if (CColMgr->PointToSprite(_cursor->getPos(), _exit))
	{
		PostQuitMessage(0);
	}
}