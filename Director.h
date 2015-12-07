#pragma once
#include "Header.h"
#include "Define.h"
#include "CollisionManager.h"
#include "DrawManager.h"
#include "ObjectManager.h"
#include "TextureManager.h"
#include "SceneManager.h"
#include "SoundManager.h"
#include "BulletManager.h"

class CDirector
{
public:
	bool Init();	// Manager Init
	void Update();	 
	void Render();	
	void Run();	// Main Loop
	void Release();	// Manager Release

	CCollisionManager* getCollisionManager() { return _collisionMgr; }
	CDrawManager* getDrawManager() { return _drawMgr; }
	CObjectManager* getObjectManager() { return _objectMgr; }
	CTextureManager* getTextureManager() { return _textureMgr; }
	CSceneManager* getSceneManager() { return _sceneMgr; }
	CSoundManager* getSoundManager() { return _soundMgr; }
	CBulletManager* getBulletManager() { return _bulletMgr; }

	double getMouseX() { return _mouseX; }
	double getMouseY() { return _mouseY; }
	void setMouseX(double a_mouseX) { _mouseX = a_mouseX; }
	void setMouseY(double a_mouseY) { _mouseY = a_mouseY; }
	void setMousePos(double a_mouseX, double a_mouseY) { _mouseX = a_mouseX; _mouseY = a_mouseY; }
	
	static CDirector* getInstance()
	{
		static CDirector* Inst;
		if (Inst == NULL)
		{
			Inst = new CDirector();
		}

		return Inst;
	}

	~CDirector();
private:
	CCollisionManager* _collisionMgr;
	CDrawManager* _drawMgr;
	CObjectManager* _objectMgr;
	CTextureManager* _textureMgr;
	CSceneManager* _sceneMgr;
	CSoundManager* _soundMgr;
	CBulletManager* _bulletMgr;

	double _mouseX;
	double _mouseY;

	bool _isActive;

	CDirector();

};
LRESULT WINAPI MsgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
