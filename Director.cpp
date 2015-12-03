#include "Director.h"
#include "S_Intro.h"
#include "S_Game.h"


CDirector::CDirector()
{
	_isActive = true;

	_collisionMgr = nullptr;
	_drawMgr = nullptr;
	_objectMgr = nullptr;
	_textureMgr = nullptr;
	_sceneMgr = nullptr;
	_soundMgr = nullptr;
}


CDirector::~CDirector()
{
	Release();
}

bool CDirector::Init()
{
	_drawMgr = new CDrawManager();
	_drawMgr->Init();
	
	_collisionMgr = new CCollisionManager();
	_objectMgr = new CObjectManager();
	_textureMgr = new CTextureManager();
	_sceneMgr = new CSceneManager();
	_soundMgr = new CSoundManager();
	
	_sceneMgr->setCurScene(new S_Game());
	_sceneMgr->getCurScene()->Init();

	return true;
}
void CDirector::Update()
{
	_sceneMgr->sceneUpdate();
	_sceneMgr->getCurScene()->Update();
}
void CDirector::Render()
{
	CDrawMgr->PreRender();
	_sceneMgr->getCurScene()->Render();
	CDrawMgr->PostRender();
}
void CDirector::Run()
{
	MSG msg;
	ZeroMemory(&msg, sizeof(msg));
	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else if (CDIRECTOR->_isActive)
		{
			Update();
			Render();
		}
	}
}
void CDirector::Release()
{
	SAFE_DELETE(_soundMgr);
	SAFE_DELETE(_sceneMgr);
	SAFE_DELETE(_textureMgr);
	SAFE_DELETE(_objectMgr);
	SAFE_DELETE(_drawMgr);
	SAFE_DELETE(_collisionMgr);
}
LRESULT WINAPI MsgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_KEYDOWN:
		CSceneMgr->getCurScene()->KeyDown(hWnd, msg, wParam, lParam);
		break;
	case WM_KEYUP:
		CSceneMgr->getCurScene()->KeyUp(hWnd, msg, wParam, lParam);
		break;
	case WM_LBUTTONDBLCLK:
		CSceneMgr->getCurScene()->LButtonDBClick(hWnd, msg, wParam, lParam);
		break;
	case WM_LBUTTONDOWN:
		CSceneMgr->getCurScene()->LButtonDown(hWnd, msg, wParam, lParam);
		break;
	case WM_LBUTTONUP:
		CSceneMgr->getCurScene()->LButtonUp(hWnd, msg, wParam, lParam);
		break;
	case WM_RBUTTONDBLCLK:
		CSceneMgr->getCurScene()->RButtonDBClick(hWnd, msg, wParam, lParam);
		break;
	case WM_RBUTTONDOWN:
		CSceneMgr->getCurScene()->RButtonDown(hWnd, msg, wParam, lParam);
		break;
	case WM_RBUTTONUP:
		CSceneMgr->getCurScene()->RButtonUp(hWnd, msg, wParam, lParam);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}