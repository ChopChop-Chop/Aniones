#pragma once
#include "Header.h"
#include "Scene.h"
#include "Sprite.h"
#include "Mesh.h"

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
	CSprite* m_pBackGround;
	CMesh* _mesh;
};

