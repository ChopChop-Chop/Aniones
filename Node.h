#pragma once
#include "Header.h"


class CNode
{
public:
	virtual bool Init();
	virtual void Render();
	virtual void Release();

	void setTag(char* a_sTag);
	void setZorder(int a_Zorder);
	void addChild(CNode* a_Ref, int a_Zorder = 1);
	void removeChild(CNode* a_Ref);
	void removeChildByTag(char* a_sTag);
	char* getTag();
	int getZorder();

	CNode();
	virtual ~CNode();
protected:
	std::vector<CNode*> _childs;

	char _tag[256];
	int _zorder;
};

