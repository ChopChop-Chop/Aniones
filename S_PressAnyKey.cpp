#include "S_PressAnyKey.h"
#include "Director.h"

S_PressAnyKey::S_PressAnyKey()
{
}


S_PressAnyKey::~S_PressAnyKey()
{
}


bool S_PressAnyKey::Init()
{
	_backGround = new CSprite();
	_backGround->Init("resources/image/s_pressanykey/bg.png");
	_backGround->setAcp(0, 0);
	addChild(_backGround);

	//_mainMenu = new S_MainMenu();
	//_mainMenu->Init();

	return true;
}

void S_PressAnyKey::KeyUp(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	//CSceneMgr->setNextScene(_mainMenu);
}
void S_PressAnyKey::LButtonUp(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	//CSceneMgr->setNextScene(_mainMenu);
}