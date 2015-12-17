#include "S_PressAnyKey.h"
#include "Director.h"

S_PressAnyKey::S_PressAnyKey()
{
}


S_PressAnyKey::~S_PressAnyKey()
{
	delete _cursor;
	delete _backGround;
}


bool S_PressAnyKey::Init()
{
	_backGround = new CSprite();
	_backGround->Init("resources/image/s_pressanykey/bg.png");
	_backGround->setAcp(0, 0);
	addChild(_backGround);
	
	_cursor = new CSprite();
	_cursor->Init("resources/image/ui/cursor_off.png");
	_cursor->addTexture("resources/image/ui/cursor_on.png");
	_cursor->setPos(-500, -500);
	addChild(_cursor, 1);

	//CSoundMgr->playSound(CSoundMgr->getFMOD_SOUND("bg.mp3", true));
	mciSendString("play bgm.mp3 repeat", 0, 0, 0);

	_menu = new S_Menu();
	_menu->Init();

	return true;
}
void S_PressAnyKey::Update()
{
	_cursor->setPos(CDIRECTOR->getMouseX(), CDIRECTOR->getMouseY());
}

void S_PressAnyKey::KeyUp(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	CSceneMgr->setNextScene(_menu);
}
void S_PressAnyKey::LButtonDown(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	_cursor->setNowAni(1);
}
void S_PressAnyKey::LButtonUp(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	_cursor->setNowAni(0);
	CSceneMgr->setNextScene(_menu);
}