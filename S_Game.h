#pragma once
#include "Scene.h"
#include "BaseChar.h"
#include "Mesh.h"
#include "Camera.h"
#include "Sprite.h"

enum MouseState
{
	IDLE,
	MOVERIGHT,
	MOVELEFT,
};

class S_Game : public CScene
{
public:
	bool Init();
	void Update();

	void CameraUpdate();
	void BoundUpdate();

	void KeyDown(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	void KeyUp(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	void LButtonDown(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	void LButtonUp(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

	S_Game();
	~S_Game();
private:
	CBaseChar* _player;
	CBaseChar* _enemy;
	CMesh* _map;
	CSprite* _crosshair;

	D3DXVECTOR2 _oldMousePos;
	D3DXVECTOR2 _curMousePos;
	D3DXVECTOR2 _distance;

	MouseState _mouseState;

	float _degree;
	float _nowTime;
	float _oldTime;

};

