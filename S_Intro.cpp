#include "S_Intro.h"
#include "Director.h"


S_Intro::S_Intro()
{
}


S_Intro::~S_Intro()
{
	delete _teamLogo;
	delete _backGround;
}

bool S_Intro::Init()
{
	_backGround = new CSprite();
	_backGround->Init("resources/image/white.png");
	_backGround->setAcp(0, 0);
	addChild(_backGround);
	_teamLogo = new CSprite();
	_teamLogo->Init("resources/image/teamlogo.png");
	_teamLogo->setPos(1280 / 2, 720 / 2);
	_teamLogo->setCol(D3DXCOLOR(1, 1, 1, 0));
	addChild(_teamLogo, 1);

	_pressAnyKey = new S_PressAnyKey();
	_pressAnyKey->Init();

	_curState = FADEIN;

	_alpha = 0;

	_now = 0;
	_old = 0;

	return true;
}
void S_Intro::Update()
{
	_teamLogo->setCol(D3DXCOLOR(1, 1, 1, _alpha));

	_now = timeGetTime();

	switch (_curState)
	{
	case IntroState::NONE:
		_alpha = 0;
		break;
	case IntroState::FADEIN:
		_alpha += 0.02;

		if (_alpha >= 1)
			_curState = APPEAR;
		
		break;
	case IntroState::APPEAR:
		if (_old == 0)
			_old = timeGetTime();

		if (_now - _old >= 2000)
		{
			_curState = FADEOUT;
			_old = 0;
		}
		break;
	case IntroState::FADEOUT:
		_alpha -= 0.02;

		if (_alpha <= 0)
			_curState = DISAPPEAR;
		break;
	case IntroState::DISAPPEAR:
		if (_old == 0)
			_old = timeGetTime();

		if (_now - _old >= 100)
			_curState = NEXTSCENE;
		break;
	case IntroState::NEXTSCENE:
		CSceneMgr->setNextScene(_pressAnyKey);
		break;
	}

}

void S_Intro::KeyDown(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	
}
void S_Intro::KeyUp(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{

}