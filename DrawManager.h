#pragma once
#include "Header.h"
#include "Camera.h"

class CDrawManager
{
public:	
	bool Init();
	bool InitWin();
	bool InitD3D();
	void SetMetrices();
	void PreRender();
	void Draw2D(LPDIRECT3DTEXTURE9 a_lpTexture, RECT a_rtSrc, D3DXVECTOR3 a_vCenter, D3DXVECTOR3 a_vPos, D3DCOLOR a_Color);
	void Draw3D(LPDIRECT3DTEXTURE9 a_Tex, D3DXMATERIAL a_Mat);
	void PostRender();
	void Release();

	LPDIRECT3D9 getD3D() { return _D3D; }
	LPDIRECT3DDEVICE9 getDevice() { return _device; }
	LPD3DXSPRITE getSprite() { return _sprite; }
	LPD3DXMESH* getMesh() { return &_mesh; }
	HWND getHWND() { return _hWND; }

	
	void setCamera(CCamera* a_pCamera);
	CCamera* m_pCurCamera;
	

	CDrawManager();
	~CDrawManager();
private:
	LPDIRECT3D9         _D3D;
	LPDIRECT3DDEVICE9    _device;
	LPD3DXSPRITE		   _sprite;
	LPD3DXMESH          _mesh;
	HWND				   _hWND;

	RECT				   _rtScreen;

};
