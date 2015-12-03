#pragma once
#include "Scene.h"


class CSceneManager
{
private:
	CScene* _nextScene;
	CScene* _curScene;

	bool _isExistNextScene;
public:
	void setNextScene(CScene* a_pNextScene);
	void setCurScene(CScene* a_pCurScene);

	CScene* getNextScene();
	CScene* getCurScene();

	void sceneUpdate();

	CSceneManager();
	~CSceneManager();
};

