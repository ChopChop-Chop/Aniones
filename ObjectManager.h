#pragma once
#include <vector>

class CNode;

class CObjectManager
{
public:
	void addObject(CNode* a_Ref);
	void removeObjectByTag(char* a_sTag);
	void removeObject(CNode* a_Ref);
	void clearPool();

	CNode* getObjectByTag(char* a_sTag);
	CNode* getObjectByIndex(int a_nIndex);

	CObjectManager();
	~CObjectManager();

private:
	std::vector<CNode*> _objectPool;
};

