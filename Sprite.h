#pragma once
#include "Node.h"
#include "Texture.h"

class CSprite : public CNode
{
private:
	CTexture* _texture; // 텍스쳐

	D3DXVECTOR2 _pos; // 위치
	D3DXVECTOR2 _acp; // 앵커포인트
	D3DXVECTOR2 _scale;	// 크기
	D3DXMATRIX _mat; // 매트릭스
	D3DXCOLOR _col;
	
	float _degree;
public:
	bool Init(const char* a_sFilename);
	void UpdateMatrix();
	void Render() override;
	void Release() override;

	void setTexture(CTexture* a_Tex);
	void setPos(float x, float y);
	void setPosX(float x);
	void setPosY(float y);
	void setPos(D3DXVECTOR2 a_vPos);
	void setAcp(float x, float y);
	void setAcpX(float x);
	void setAcpY(float y);
	void setAcp(D3DXVECTOR2 a_vAcp);
	void setScale(float x, float y);
	void setScaleX(float x);
	void setScaleY(float y);
	void setScale(D3DXVECTOR2 a_vScale);
	void setMat(D3DXMATRIX a_mMat);
	void setDegree(float a_fDegree);
	void setCol(D3DXCOLOR a_Col);
	
	CTexture* getTexture();
	float getPosX();
	float getPosY();
	D3DXVECTOR2 getPos();
	float getAcpX();
	float getAcpY();
	D3DXVECTOR2 getAcp();
	float getScaleX();
	float getScaleY();
	D3DXVECTOR2 getScale();
	D3DXMATRIX getMat();
	float getDegree();
	D3DXCOLOR getCol();

	CSprite();
	virtual ~CSprite();
};

