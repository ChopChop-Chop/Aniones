#pragma once
#include <d3dx9.h>


class CCollisionManager
{
public:
	bool PointToPoint(D3DXVECTOR3* a_vPt1, D3DXVECTOR3* a_vPt2, float fEpsilon = 0.0001);
	bool PointToLine(const D3DXVECTOR3* V, const D3DXVECTOR3* a_vPt1, const D3DXVECTOR3* a_vPt2, float fEpsilon = 0.0001);
	bool PointToPlane(const D3DXVECTOR3* P, const D3DXVECTOR3* N, float D, float fEpsilon = 0.0001);
	bool PointToRect(const D3DXVECTOR3 a_vPt, RECT a_Rect);
	bool SphereToSphere(const D3DXVECTOR3* SphereCenter1, float SphereRadius1, const D3DXVECTOR3* SphereCenter2, float SphereRadius2);
	bool SphereToLine(const D3DXVECTOR3* SphereCenter, float SphereRadius, const D3DXVECTOR3* LineBegin, const D3DXVECTOR3* LineDirection);


	CCollisionManager();
	~CCollisionManager();
};

