#pragma once
#include "Header.h"

class CTexture
{
public:
	bool createTexture(const char* a_sFileName);

	__inline LPDIRECT3DTEXTURE9 getTexture();
	__inline char* getFileName();
	__inline RECT getRect();
	__inline D3DXIMAGE_INFO getImgInfo();
	

	__inline void setTexture(LPDIRECT3DTEXTURE9 a_pTexture);
	__inline void setFileName(const char* a_sFileName);
	__inline void setRect(RECT a_rRect);
	__inline void setImgInfo(D3DXIMAGE_INFO a_sImgInfo);

	CTexture();
	virtual ~CTexture();
private:
	LPDIRECT3DTEXTURE9 _texture;
	char* _fileName;
	RECT _rect;
	D3DXIMAGE_INFO _imgInfo;

};
__inline LPDIRECT3DTEXTURE9 CTexture::getTexture()
{
	return _texture;
}
__inline char* CTexture::getFileName()
{
	return _fileName;
}
__inline RECT CTexture::getRect()
{
	return _rect;
}
__inline D3DXIMAGE_INFO CTexture::getImgInfo()
{
	return _imgInfo;
}

__inline void CTexture::setTexture(LPDIRECT3DTEXTURE9 a_pTexture)
{
	_texture = a_pTexture;
}
__inline void CTexture::setFileName(const char* a_sFileName)
{
	_fileName = new char(sizeof(a_sFileName));

	strcpy(_fileName, a_sFileName);
}
__inline void CTexture::setRect(RECT a_rRect)
{
	_rect = a_rRect;
}
__inline void CTexture::setImgInfo(D3DXIMAGE_INFO a_ImgInfo)
{
	_imgInfo = a_ImgInfo;
}