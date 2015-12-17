#pragma once
#include "Scene.h"
#include "Sprite.h"
#include "Mesh.h"
#include "CharSelectBackGround.h"




class S_CharSelect : public CScene
{
public:
	bool Init();
	void Update();
	void ChangeModel();

	void LButtonDown(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	void LButtonUp(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	void KeyDown(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	void KeyUp(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

	S_CharSelect();
	~S_CharSelect();

private:
	CCharSelectBackGround* _backGround;
	CSprite* _charImage;
	CSprite* _cursor;
	CMesh* _charModel;
	
	bool _changeModel;

	int _selectCharID;
};

