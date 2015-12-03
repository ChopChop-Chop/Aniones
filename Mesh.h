#pragma once
#include "Node.h"
#include "Texture.h"

class CMesh : public CNode
{
public:

	bool Init(const char* a_sFileName);
	void UpdateMatrix();
	void Render();
	void Release();

	void setPos(D3DXVECTOR3 a_Pos);
	void setAcp(D3DXVECTOR3 a_Acp);
	void setScale(D3DXVECTOR3 a_Scale);
	void setMat(D3DXMATRIX a_Mat);
	void setColor(D3DXCOLOR a_Col);
	void setDegreeX(float a_DegreeX) { _degreeX = a_DegreeX; }
	void setDegreeY(float a_DegreeY) { _degreeY = a_DegreeY; }
	void setDegreeZ(float a_DegreeZ) { _degreeZ = a_DegreeZ; }

	D3DXVECTOR3 getPos(); // 위치
	D3DXVECTOR3 getAcp(); // 앵커포인트
	D3DXVECTOR3 getScale();	// 크기
	D3DXMATRIX getMat(); // 매트릭스
	D3DXCOLOR getColor();
	float getDegreeX() { return _degreeX; }
	float getDegreeY() { return _degreeY; }
	float getDegreeZ() { return _degreeZ; }

	CMesh();
	virtual ~CMesh();
private:
	D3DMATERIAL9* _materials; // 메쉬의 재질
	CTexture** _textures; // 매쉬의 텍스쳐
	DWORD _numMaterials; // 메쉬의 재질 개수

	D3DXVECTOR3 _pos; // 위치
	D3DXVECTOR3 _acp; // 앵커포인트
	D3DXVECTOR3 _scale;	// 크기
	D3DXMATRIX _mat; // 매트릭스
	D3DXCOLOR _col;
	D3DXQUATERNION _qut;
	LPD3DXBUFFER _mtrlBuffer;
	D3DXMATERIAL* _d3dxMaterials;

	float _degreeX;
	float _degreeY;
	float _degreeZ;
};

