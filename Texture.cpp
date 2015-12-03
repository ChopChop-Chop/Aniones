#include "Texture.h"
#include "Define.h"



CTexture::CTexture()
{
	_texture = NULL;
	_fileName= NULL;
	_rect.bottom = 0;
	_rect.left = 0; 
	_rect.right = 0; 
	_rect.top = 0;

	_imgInfo = { 0, };
}


CTexture::~CTexture()
{
}


bool CTexture::createTexture(const char* a_sFileName)
{
	CTexture* temp = CTexMgr->createTexture(a_sFileName);

	if (temp == NULL)
		return false;

	this->_fileName = temp->getFileName();
	this->_imgInfo = temp->getImgInfo();
	this->_rect = temp->getRect();
	this->_texture = temp->getTexture();

	return true;
	
}