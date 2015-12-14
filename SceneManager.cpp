#include "SceneManager.h"
#include "Node.h"
#include "Director.h"


CSceneManager::CSceneManager()
{
	_curScene = nullptr;
	_nextScene = nullptr;
	_isExistNextScene = false;
}


CSceneManager::~CSceneManager()
{
	if (_curScene != NULL)
	{
		delete _curScene;
		_curScene = nullptr;
	}
}


void CSceneManager::setNextScene(CScene* a_pNextScene)
{
	this->_nextScene = a_pNextScene;

	_isExistNextScene = true;
}

void CSceneManager::setCurScene(CScene* a_pCurScene)
{
	_curScene = a_pCurScene;
}
CScene* CSceneManager::getNextScene()
{
	if (_nextScene == NULL)
	{
		MessageBox(CDIRECTOR->getDrawManager()->getHWND(), "NextSceneNullException", "NextSceneNullException", MB_OK);
		std::cout << "NextSceneNullException" << std::endl;

		return NULL;
	}

	return _nextScene;
}
CScene* CSceneManager::getCurScene()
{
	if (_curScene == NULL)
	{
		MessageBox(CDIRECTOR->getDrawManager()->getHWND(), "CurSceneNullException", "CurSceneNullException", MB_OK);
		std::cout << "CurSceneNullException" << std::endl;

		return NULL;
	}

	return _curScene;
}
void CSceneManager::sceneUpdate()
{
	if (!_isExistNextScene)
		return;

	_curScene->Release();
	delete _curScene;
	_curScene = nullptr;
	_curScene = _nextScene;
	_curScene->Init();

	_isExistNextScene = false;
}