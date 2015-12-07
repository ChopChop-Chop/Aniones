#pragma once
#include "Scene.h"
//#include "S_MainMenu.h"
#include "Sprite.h"

class S_PressAnyKey : public CScene
{
public:
	bool Init();

	void KeyUp(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	void LButtonUp(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

	S_PressAnyKey();
	~S_PressAnyKey();

private:
	CSprite* _backGround;

	//S_MainMenu* _mainMenu;
};

