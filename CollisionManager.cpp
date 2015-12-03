#include "CollisionManager.h"
#include <cmath>


CCollisionManager::CCollisionManager()
{
}


CCollisionManager::~CCollisionManager()
{
}

bool CCollisionManager::PointToPoint(D3DXVECTOR3* a_vPt1, D3DXVECTOR3* a_vPt2, float fEpsilon)
{
	if(fabsf(a_vPt2->x - a_vPt1->x) <= fEpsilon
		&& fabsf(a_vPt2->y - a_vPt1->y <= fEpsilon)
		&& fabsf(a_vPt2->z - a_vPt1->z <= fEpsilon))
	{
		return true;
	}
	return false;
}
bool CCollisionManager::PointToLine(const D3DXVECTOR3* V, const D3DXVECTOR3* a_vPt1, const D3DXVECTOR3* a_vPt2, FLOAT fEpsilon)
{
	bool hr = false;

	float fHsq;
	D3DXVECTOR3 vcT = *V - *a_vPt1;
	D3DXVECTOR3 vcL = *a_vPt2 - *a_vPt1;

	D3DXVECTOR3 vcH;
	D3DXVec3Cross(&vcH, &vcT, &vcL);
	fHsq = D3DXVec3LengthSq(&vcH);

	if (fHsq > fEpsilon)
		return hr;

	float L = fabsf(a_vPt2->x - a_vPt1->x) +
		fabsf(a_vPt2->y - a_vPt1->y) +
		fabsf(a_vPt2->z - a_vPt1->z);
	float L1 = fabsf(V->x - a_vPt1->x) +
		fabsf(V->y - a_vPt1->y) +
		fabsf(V->z - a_vPt1->z);
	float L2 = fabsf(V->x - a_vPt2->x) +
		fabsf(V->y - a_vPt2->y) +
		fabsf(V->z - a_vPt2->z);

	if ((L1 + L2) < (L + fEpsilon))
		hr = true;

	return hr;
}
bool CCollisionManager::PointToPlane(const D3DXVECTOR3* P, const D3DXVECTOR3* N, float D, float fEpsilon)
{
	bool hr = false;

	float d = D3DXVec3Dot(N, P) - D;

	if (d < fEpsilon)
		hr = 0;

	return hr;
}
bool CCollisionManager::PointToRect(const D3DXVECTOR3 a_vPt, RECT a_Rect)
{
	if (a_Rect.top <= a_vPt.y
		&& a_Rect.bottom >= a_vPt.y
		&& a_Rect.left <= a_vPt.x
		&& a_Rect.right >= a_vPt.x)
	{
		return true;
	}

	return false;
}

bool CCollisionManager::SphereToSphere(const D3DXVECTOR3* SphereCenter1, float SphereRadius1, const D3DXVECTOR3* SphereCenter2, float SphereRadius2)
{
	bool hr = false;

	float fDistance;
	D3DXVECTOR3 vcTemp = *SphereCenter1 - *SphereCenter2;

	fDistance = D3DXVec3Length(&vcTemp);

	if (fDistance <= (SphereRadius1 + SphereRadius2))
		hr = true;

	return hr;
}
bool CCollisionManager::SphereToLine(const D3DXVECTOR3* SphereCenter, float SphereRadius, const D3DXVECTOR3* LineBegin, const D3DXVECTOR3* LineDirection)
{
	bool hr = false;

	FLOAT fHsq;
	D3DXVECTOR3 vcT = *SphereCenter - *LineBegin;
	D3DXVECTOR3 vcL = *LineDirection;

	// float fDot = D3DXVec3Dot(&vcT, &vcL);
	// fDot *= fDot;
	// fHsq = D3DXVec3LengthSq(&vcT) - fDot;

	D3DXVECTOR3 vcH;
	D3DXVec3Cross(&vcH, &vcT, &vcL);
	fHsq = D3DXVec3LengthSq(&vcH);

	if (fHsq <= SphereRadius * SphereRadius)
		hr = true;

	return hr;
}