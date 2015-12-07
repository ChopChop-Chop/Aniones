#pragma once
#include "Header.h"
#include "Scene.h"
#include "Sprite.h"
#include "S_PressAnyKey.h"

enum IntroState
{
	NONE= 0,
	FADEIN,
	APPEAR,
	FADEOUT,
	DISAPPEAR,
	NEXTSCENE,
};

class S_Intro : public CScene
{
public:
	bool Init();
	void Update();
	
	void KeyDown(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	void KeyUp(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	
	S_Intro();
	~S_Intro();
private:
	CSprite* _backGround;
	CSprite* _teamLogo;

	int _curState;
	float _alpha;

	float _now;
	float _old;

	S_PressAnyKey* _pressAnyKey;

};

