#pragma once
#include "Header.h"
#include "Node.h"

class CBoundingBox : public CNode 
{
public:
	bool Init() override;
	void GetMinMax(LPD3DXMESH mesh);
	void CreateBox();
	void Render() override;

	DWORD getFVF() { return _fvf; }
	D3DXVECTOR3 getMax() { return _max; }
	float getMaxX() { return _max.x; }
	float getMaxY() { return _max.y; }
	float getMaxZ() { return _max.z; }
	D3DXVECTOR3 getMin() { return _min; }
	float getMinX() { return _min.x; }
	float getMinY() { return _min.y; }
	float getMinZ() { return _min.z; }
	D3DXVECTOR3* getVertices() { return _boxVertices; }
	D3DXVECTOR3 getVertices(int i) { return _boxVertices[i]; }

	void setFVF(DWORD fvf) { _fvf = fvf; }
	void setMin(D3DXVECTOR3 min) { _min = min; }
	void setMin(float x, float y, float z) { _min.x = x; _min.y = y; _min.z = z; }
	void setMinX(float x) { _min.x = x; }
	void setMinY(float y) { _min.y = y; }
	void setMinZ(float z) { _min.z = z; }
	void setMax(D3DXVECTOR3 max) { _max = max; }
	void setMax(float x, float y, float z) { _max.x = x; _max.y = y; _max.z = z; }
	void setMaxX(float x) { _max.x = x; }
	void setMaxY(float y) { _max.y = y; }
	void setMaxZ(float z) { _max.z = z; }
	

	CBoundingBox();
	~CBoundingBox();
private:
	D3DXVECTOR3 _pos;
	DWORD _fvf;
	D3DXVECTOR3 _min;
	D3DXVECTOR3 _max;
	D3DXVECTOR3 _boxVertices[8];
	int _boxIndex[24];
};

