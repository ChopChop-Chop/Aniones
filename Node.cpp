#include "Node.h"
#include "Director.h"


CNode::CNode()
{
	_visible = true;
	_zorder = 0;
	_childs.clear();
}


CNode::~CNode()
{
}

bool CNode::Init()
{
	return true;
}
void CNode::Render()
{
	if (!_visible)
		return;
	for (auto p : _childs)
	{
		if (p->isVisible())
			p->Render();
	}
}
void CNode::Release()
{
	for (int i = _childs.size() - 1; i >= 0; i--)
	{
		_childs.at(i)->Release();
	}
}
void CNode::setZorder(int Zorder)
{
	_zorder = Zorder;
}

void CNode::setTag(char* a_sTag)
{
	strcpy(_tag, a_sTag);

}

void CNode::addChild(CNode* a_Ref, int a_Zorder)
{
	for(auto p : _childs)
	{
		if (p == a_Ref)
		{
			MessageBox(CDIRECTOR->getDrawManager()->getHWND(), "AddChild Duplication", "AddChild Duplication", MB_OK);
			std::cout << "addChild Duplication Error - " << a_Ref->getTag()  << "is Already Exist" << std::endl;
			return;
		}
	}

	a_Ref->setZorder(a_Zorder);

	_childs.push_back(a_Ref);

	for (UINT i = 0; i < _childs.size(); i++)
	{
		for (UINT j = 0; j < _childs.size() - (i + 1); j++)
		{
			if (_childs.at(j)->getZorder() > _childs.at(j + 1)->getZorder())
			{
				auto temp = _childs.at(j + 1);
				_childs.at(j + 1) = _childs.at(j);
				_childs.at(j) = temp;
			}
		}
	}
}

char* CNode::getTag()
{
	return _tag;
}
int CNode::getZorder()
{
	return _zorder;
}


void CNode::removeChild(CNode* a_Ref)
{
	for (auto p : _childs)
	{
		if (p == a_Ref)
		{
			p->Release();
			delete p;
			return;
		}
	}
	MessageBox(CDIRECTOR->getDrawManager()->getHWND(), "removeChild NullException", "removeChild NullException", MB_OK);
	std::cout << "removeChild NullException - " << a_Ref->getTag() << " is not exist" << std::endl;
}
void CNode::removeChildByTag(char* a_sTag)
{
	for (auto p : _childs)
	{
		if (p->getTag() == a_sTag)
		{
			p->Release();
			delete p;
			p = nullptr;
			return;
		}
	}
	MessageBox(CDIRECTOR->getDrawManager()->getHWND(), "removeChildByTag NullException", "removeChildByTag NullException", MB_OK);
	std::cout << "removeChildByTag NullException - " << a_sTag << " is not exist" << std::endl;
}
