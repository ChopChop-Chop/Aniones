#include "S_Intro.h"
#include "Director.h"


S_Intro::S_Intro()
{
}


S_Intro::~S_Intro()
{
}

bool S_Intro::Init()
{
	m_pBackGround = new CSprite();
	m_pBackGround->Init("Resources/bg.png");
	//addChild(m_pBackGround, -1);

	_mesh = new CMesh();
	_mesh->Init("Resources/tiger.x");
	addChild(_mesh, 0);

	CDrawMgr->m_pCurCamera->setActive(true);
	CDrawMgr->m_pCurCamera->setPos(D3DXVECTOR3(0, 0, -25));
	CDrawMgr->m_pCurCamera->setLookat(D3DXVECTOR3(0,0,0));

	return true;
}
void S_Intro::Update()
{
	CDrawMgr->m_pCurCamera->Update();

}

void S_Intro::KeyDown(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (wParam)
	{
	case VK_RIGHT:
		_mesh->setPos(D3DXVECTOR3(_mesh->getPos().x + 1, _mesh->getPos().y, _mesh->getPos().z));
		break;
	case VK_LEFT:
		_mesh->setPos(D3DXVECTOR3(_mesh->getPos().x - 1, _mesh->getPos().y, _mesh->getPos().z));
		break;
	}
}
void S_Intro::KeyUp(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{

}