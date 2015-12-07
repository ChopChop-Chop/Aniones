#include "Sprite.h"
#include "Director.h"



CSprite::CSprite()
{

	_nowAni = 0;
	_beginAni = 0;
	_endAni = 0;
	_frameRate = 0;
	_nowTime = 0;
	_oldTime = 0;

	_pos = D3DXVECTOR2(0,0); // 위치
	_acp = D3DXVECTOR2(0.5,0.5); // 앵커포인트
	_scale = D3DXVECTOR2(1,1);	// 크기
	D3DXMatrixIdentity(&_mat);
	_col = D3DXCOLOR(1, 1, 1, 1);

	_degree = 0.f;
}


CSprite::~CSprite()
{
	for (int i = _texVector.size() - 1; i > 0; i--)
	{
		delete _texVector.at(i);
	}
}



bool CSprite::Init(const char* a_sFilename)
{
	CTexture* temp = new CTexture();
	temp->createTexture(a_sFilename);
	_texVector.push_back(temp);

	return true;
}
void CSprite::UpdateMatrix()
{
	D3DXVECTOR2 Pt;
	Pt.x = _pos.x - (_texVector.at(_nowAni)->getRect().right * _acp.x);
	Pt.y = _pos.y - (_texVector.at(_nowAni)->getRect().bottom * _acp.y);

	float radian = _degree * 3.141592f / 180.0f;

	D3DXMatrixTransformation2D(&_mat, &_acp, NULL, &_scale, &_acp, radian, &Pt);
}
void CSprite::AniUpdate()
{
	if (_oldTime == 0)
		_oldTime = timeGetTime();

	_nowTime = timeGetTime();

	if (_nowAni < _beginAni)
	{
		_nowAni = _beginAni;
	}
	if (_nowAni > _endAni)
	{
		_nowAni = _beginAni;
	}

	if (_nowTime - _oldTime >= _frameRate)
	{
		_oldTime = timeGetTime();

		_nowAni++;

		if (_nowAni > _endAni)
			_nowAni = _beginAni;
		
	}
}
bool CSprite::AniUpdateOnce()
{
	if (_oldTime == 0)
		_oldTime = timeGetTime();

	_nowTime = timeGetTime();

	if (_nowAni < _beginAni)
	{
		_nowAni = _beginAni;
	}
	if (_nowAni > _endAni)
	{
		_nowAni = _beginAni;
	}

	if (_nowTime - _oldTime >= _frameRate)
	{
		_nowAni++;

		if (_nowAni > _endAni)
			return true;

	}

	return false;
}
void CSprite::Render()
{
	CDrawMgr->getSprite()->SetTransform(&_mat);
	CDrawMgr->Draw2D(_texVector.at(_nowAni)->getTexture(), _texVector.at(_nowAni)->getRect(), D3DXVECTOR3(_acp.x, _acp.y, _zorder), D3DXVECTOR3(_pos.x, _pos.y, _zorder), _col);
}
void CSprite::Release()
{
	
}

void CSprite::addTexture(CTexture* a_Tex)
{
	_texVector.push_back(a_Tex);
}
void CSprite::addTexture(const char* a_FileName)
{
	CTexture* temp = new CTexture();
	temp->createTexture(a_FileName);

	_texVector.push_back(temp);
}
void CSprite::setNowAni(int a_NowAni)
{
	_nowAni = a_NowAni;
}
void CSprite::setBeginAni(int a_BeginAni)
{
	_beginAni = a_BeginAni;
}
void CSprite::setEndAni(int a_EndAni)
{
	_endAni = a_EndAni;
}
void CSprite::setFrameRate(int a_FrameRate)
{
	_frameRate = a_FrameRate;
}
void CSprite::setAniScope(int begin, int end, float framerate)
{
	_beginAni = begin;
	_endAni = end;
	_frameRate = framerate;
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
CTexture* CSprite::getTexture(int index)
{
	return _texVector.at(index);
}
int CSprite::getNowAni()
{
	return _nowAni;
}
int CSprite::getBeginAni()
{
	return _beginAni;
}
int CSprite::getEndAni()
{
	return _endAni;
}
float CSprite::getFrameRate()
{
	return _frameRate;
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