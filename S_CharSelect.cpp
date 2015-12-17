#include "S_CharSelect.h"
#include "Director.h"


S_CharSelect::S_CharSelect()
{
}


S_CharSelect::~S_CharSelect()
{
}

bool S_CharSelect::Init()
{
	_backGround = new CCharSelectBackGround();
	_backGround->Init();
	addChild(_backGround, -1);

	_charImage = new CSprite();
	_charImage->Init("resources/image/s_charselect/1.png");
	_charImage->addTexture("resources/image/s_charselect/2.png");
	_charImage->addTexture("resources/image/s_charselect/3.png");
	_charImage->addTexture("resources/image/s_charselect/4.png");
	_charImage->addTexture("resources/image/s_charselect/5.png");
	_charImage->addTexture("resources/image/s_charselect/6.png");
	_charImage->addTexture("resources/image/s_charselect/7.png");
	_charImage->setPos(978, 462);
	addChild(_charImage);
	
	_cursor = new CSprite();
	_cursor->Init("resources/image/ui/cursor_off.png");
	_cursor->addTexture("resources/image/ui/cursor_on.png");
	addChild(_cursor);
	
	_charModel = new CMesh();
	_charModel->Init("resources/mesh/character/1.X");
	_charModel->setPos(-30, -30, 0);
	addChild(_charModel);

	CDrawMgr->m_pCurCamera->setActive(true);
	CDrawMgr->m_pCurCamera->setPos(D3DXVECTOR3(0, 0, -150));
	CDrawMgr->m_pCurCamera->setLookatY(0);

	_selectCharID = 1;
	

	return true;
}
void S_CharSelect::Update()
{
	_cursor->setPos(CDIRECTOR->getMouseX(), CDIRECTOR->getMouseY());
	CDrawMgr->m_pCurCamera->Update();

	_charModel->setDegreeY(_charModel->getDegreeY() + 1);

}
void S_CharSelect::ChangeModel()
{
	if (_changeModel)
		return;

	switch (_selectCharID)
	{
	case 1:
		_charModel->Init("resources/mesh/character/1.x");
		_charImage->setNowAni(0);
		break;
	case 2:
		_charModel->Init("resources/mesh/character/2.x");
		_charImage->setNowAni(1);
		break;
	case 3:
		_charModel->Init("resources/mesh/character/3.x");
		_charImage->setNowAni(2);
		break;
	case 4:
		_charModel->Init("resources/mesh/character/4.x");
		_charImage->setNowAni(3);
		break;
	case 5:
		_charModel->Init("resources/mesh/character/5.x");
		_charImage->setNowAni(4);
		break;
	case 6:
		_charModel->Init("resources/mesh/character/6.x");
		_charImage->setNowAni(5);
		break;
	case 7:
		_charModel->Init("resources/mesh/character/7.x");
		_charImage->setNowAni(6);
		break;
	}


	_changeModel = true;
}

void S_CharSelect::LButtonDown(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	_cursor->setNowAni(1);
}
void S_CharSelect::LButtonUp(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	_cursor->setNowAni(0);
}

void S_CharSelect::KeyDown(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	
}
void S_CharSelect::KeyUp(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (wParam)
	{
	case 'a':
	case 'A':
		_selectCharID--;

		if (_selectCharID < 1)
			_selectCharID = 7;

		_changeModel = false;
		ChangeModel();
		break;
	case 'd':
	case 'D':
		_selectCharID++;

		if (_selectCharID > 7)
			_selectCharID = 1;

		_changeModel = false;
		ChangeModel();
		break;
	}
}