#include "Sprite.h"
#include "Director.h"



CSprite::CSprite()
{
	_texture = new CTexture(); // 텍스쳐

	_pos = D3DXVECTOR2(0,0); // 위치
	_acp = D3DXVECTOR2(0.5,0.5); // 앵커포인트
	_scale = D3DXVECTOR2(1,1);	// 크기
	D3DXMatrixIdentity(&_mat);
	_col = D3DXCOLOR(1, 1, 1, 1);

	_degree = 0.f;
}


CSprite::~CSprite()
{
	delete _texture;
}

bool CSprite::Init(const char* a_sFilename)
{
	_texture->createTexture(a_sFilename);

	return true;
}
void CSprite::UpdateMatrix()
{
	D3DXVECTOR2 Pt;
	Pt.x = _pos.x - (_texture->getImgInfo().Width * _acp.x);
	Pt.y = _pos.y - (_texture->getImgInfo().Height * _acp.y);

	float radian = _degree * 3.141592f / 180.0f;

	D3DXMatrixTransformation2D(&_mat, &_acp, NULL, &_scale, &_acp, radian, &Pt);
}
void CSprite::Render()
{
	CDrawMgr->getSprite()->SetTransform(&_mat);
	CDrawMgr->Draw2D(_texture->getTexture(), _texture->getRect(), D3DXVECTOR3(_acp.x, _acp.y, 0), D3DXVECTOR3(_pos.x, _pos.y, 0), _col);
}
void CSprite::Release()
{
	
}


void CSprite::setTexture(CTexture* a_Tex)
{
	_texture = a_Tex;
	UpdateMatrix();
}
void CSprite::setPos(float x, float y)
{
	_pos.x = x;
	_pos.y = y;
	UpdateMatrix();
}
void CSprite::setPosX(float x)
{
	_pos.x = x;
	UpdateMatrix();
}
void CSprite::setPosY(float y)
{
	_pos.y = y;
	UpdateMatrix();
}
void CSprite::setPos(D3DXVECTOR2 a_vPos)
{
	_pos = a_vPos;
	UpdateMatrix();
}
void CSprite::setAcp(float x, float y)
{
	_acp.x = x;
	_acp.y = y;
	UpdateMatrix();
}
void CSprite::setAcpX(float x)
{
	_acp.x = x;
	UpdateMatrix();
}
void CSprite::setAcpY(float y)
{
	_acp.y = y;
	UpdateMatrix();
}
void CSprite::setAcp(D3DXVECTOR2 a_vAcp)
{
	_acp = a_vAcp;
	UpdateMatrix();
}
void CSprite::setScale(float x, float y)
{
	_scale.x = x;
	_scale.y = y;
	UpdateMatrix();
}
void CSprite::setScaleX(float x)
{
	_scale.x = x;
	UpdateMatrix();
}
void CSprite::setScaleY(float y)
{
	_scale.y = y;
	UpdateMatrix();
}
void CSprite::setScale(D3DXVECTOR2 a_vScale)
{
	_scale = a_vScale;
	UpdateMatrix();
}
void CSprite::setMat(D3DXMATRIX a_mMat)
{
	_mat = a_mMat;
	UpdateMatrix();
}
void CSprite::setDegree(float a_fDegree)
{
	_degree = a_fDegree;
	UpdateMatrix();
}
void CSprite::setCol(D3DXCOLOR a_Col)
{
	_col = a_Col;
	UpdateMatrix();
}
CTexture* CSprite::getTexture()
{
	return _texture;
}
float CSprite::getPosX()
{
	return _pos.x;
}
float CSprite::getPosY()
{
	return _pos.y;
}
D3DXVECTOR2 CSprite::getPos()
{
	return _pos;
}
float CSprite::getAcpX()
{
	return _acp.x;
}
float CSprite::getAcpY()
{
	return _acp.y;
}
D3DXVECTOR2 CSprite::getAcp()
{
	return _acp;
}
float CSprite::getScaleX()
{
	return _scale.x;
}
float CSprite::getScaleY()
{
	return _scale.y;
}
D3DXVECTOR2 CSprite::getScale()
{
	return _scale;
}
D3DXMATRIX CSprite::getMat()
{
	return _mat;
}
float CSprite::getDegree()
{
	return _degree;
}
D3DXCOLOR CSprite::getCol()
{
	return _col;
}