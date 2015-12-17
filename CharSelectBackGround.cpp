#include "CharSelectBackGround.h"
#include "Director.h"


CCharSelectBackGround::CCharSelectBackGround()
{
}


CCharSelectBackGround::~CCharSelectBackGround()
{
}

bool CCharSelectBackGround::Init()
{
	_sprite = new CSprite();
	_sprite->Init("resources/image/s_charselect/bg.png");
	_sprite->setAcp(0, 0);

	return true;
}
void CCharSelectBackGround::Render()
{
	CDrawMgr->getDevice()->SetRenderState(D3DRS_ZENABLE, FALSE);
	_sprite->Render();
	CDrawMgr->getDevice()->SetRenderState(D3DRS_ZENABLE, TRUE);
}