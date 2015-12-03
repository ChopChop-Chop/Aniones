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
	void setPosX(float x) { _pos.x = x; }
	void setPosY(float y) { _pos.y = y; }
	void setPosZ(float z) { _pos.z = z; }
	void setPos(float x, float y, float z) {
		_pos.x = x; _pos.y = y; _pos.z = z;
	}
	void setAcp(D3DXVECTOR3 a_Acp);
	void setAcpX(float x) { _acp.x = x; }
	void setAcpY(float y) { _acp.y = y; }
	void setAcpZ(float z) { _acp.z = z; }
	void setAcp(float x, float y, float z) { _acp.x = x; _acp.y = y; _acp.z = z; }
	void setScale(D3DXVECTOR3 a_Scale);
	void setScale(float x, float y, float z) { _scale.x = x; _scale.y = y; _scale.z = z; }
	void setScaleX(float x) { _scale.x = x; }
	void setScaleY(float y) { _scale.y = y; }
	void setScaleZ(float z) { _scale.z = z; }
	void setMat(D3DXMATRIX a_Mat);
	void setColor(D3DXCOLOR a_Col);
	void setDegreeX(float a_DegreeX) { _degreeX = a_DegreeX; }
	void setDegreeY(float a_DegreeY) { _degreeY = a_DegreeY; }
	void setDegreeZ(float a_DegreeZ) { _degreeZ = a_DegreeZ; }

	D3DXVECTOR3 getPos(); // 위치
	float getPosX() { return _pos.x; }
	float getPosY() { return _pos.y; }
	float getPosZ() { return _pos.z; }
	D3DXVECTOR3 getAcp(); // 앵커포인트
	float getAcpX() { return _acp.x; }
	float getAcpY() { return _acp.y; }
	float getAcpZ() { return _acp.z; }
	D3DXVECTOR3 getScale();	// 크기
	float getScaleX() { return _scale.x; }
	float getScaleY() { return _scale.y; }
	float getScaleZ() { return _scale.z; }
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

