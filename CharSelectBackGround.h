#pragma once
#include "Node.h"
#include "Sprite.h"

class CCharSelectBackGround : public CNode
{
public:
	bool Init();
	void Render();
	
	CCharSelectBackGround();
	~CCharSelectBackGround();

private:
	CSprite* _sprite;

};

