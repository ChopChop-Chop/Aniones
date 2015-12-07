#pragma once

#include "Director.h"


#define SAFE_RELEASE(REF) {if(REF != NULL) {REF->Release(); REF = NULL;} }
#define SAFE_DELETE(REF) {if(REF != NULL) {delete REF; REF = NULL;}}

#define WINWIDTH 1280
#define WINHEIGHT 720


#define CDIRECTOR CDirector::getInstance()
#define CColMgr CDirector::getInstance()->getCollisionManager()
#define CDrawMgr CDirector::getInstance()->getDrawManager()
#define CInputMgr CDirector::getInstance()->getInputManager()
#define CObjMgr CDirector::getInstance()->getObjectManager()
#define CTexMgr CDirector::getInstance()->getTextureManager()
#define CSceneMgr CDirector::getInstance()->getSceneManager()
#define CSoundMgr CDirector::getInstance()->getSoundManager()
#define CBulletMgr CDirector::getInstance()->getBulletManager()