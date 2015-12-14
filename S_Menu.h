#pragma once
#include "Scene.h"
#include "Sprite.h"

class S_Menu : public CScene
{
public:
	bool Init();
	void Update();

	void LButtonDown(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	void LButtonUp(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

	S_Menu();
	~S_Menu();
private:
	CSprite* _backGround;
	CSprite* _start;
	CSprite* _credit;
	CSprite* _exit;
	CSprite* _cursor;

};

