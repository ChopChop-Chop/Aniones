#pragma once
#include "Node.h"
#include "Texture.h"
#include <vector>

class CSprite : public CNode
{
private:
	std::vector<CTexture*> _texVector;

	int _nowAni;
	int _beginAni;
	int _endAni;
	float _frameRate;
	float _nowTime;
	float _oldTime;

	D3DXVECTOR2 _pos; // 위치
	D3DXVECTOR2 _acp; // 앵커포인트
	D3DXVECTOR2 _scale;	// 크기
	D3DXMATRIX _mat; // 매트릭스
	D3DXCOLOR _col;
	
	float _degree;
public:
	bool Init(const char* a_Filename);
	void UpdateMatrix();
	void AniUpdate();
	bool AniUpdateOnce();
	void Render() override;
	void Release() override;

	void addTexture(CTexture* a_Tex);
	void addTexture(const char* a_Filename);
	void setNowAni(int a_NowAni);
	void setBeginAni(int a_BeginAni);
	void setEndAni(int a_EndAni);
	void setFrameRate(int a_FrameRate);
	void setAniScope(int begin, int end, float framerate);
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
	
	CTexture* getTexture(int index);
	int getNowAni();
	int getBeginAni();
	int getEndAni();
	float getFrameRate();
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

