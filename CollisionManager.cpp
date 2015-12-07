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

bool CCollisionManager::AABB(CMesh _mesh1, CMesh _mesh2)
{
	D3DXVECTOR3 mesh1Max = D3DXVECTOR3(FLT_MAX, FLT_MAX, FLT_MAX);
	D3DXVECTOR3 mesh1Min = D3DXVECTOR3(-FLT_MAX, -FLT_MAX, -FLT_MAX);
	D3DXVECTOR3 mesh2Max = D3DXVECTOR3(FLT_MAX, FLT_MAX, FLT_MAX);
	D3DXVECTOR3 mesh2Min = D3DXVECTOR3(-FLT_MAX, -FLT_MAX, -FLT_MAX);

	DWORD mesh1FVF = _mesh1.getMesh()->GetFVF();
	D3DXVECTOR3* tempHighVertex1 = 0;
	_mesh1.getMesh()->LockVertexBuffer(0, (void**)&tempHighVertex1);
	for (DWORD i = 0; i < _mesh1.getMesh()->GetNumVertices(); ++i)
	{
		if (tempHighVertex1[i].x > mesh1Max.x) mesh1Max.x = tempHighVertex1[i].x;
		if (tempHighVertex1[i].y > mesh1Max.y) mesh1Max.y = tempHighVertex1[i].y;
		if (tempHighVertex1[i].z > mesh1Max.z) mesh1Max.z = tempHighVertex1[i].z;
		if (tempHighVertex1[i].x < mesh1Min.x) mesh1Min.x = tempHighVertex1[i].x;
		if (tempHighVertex1[i].y < mesh1Min.y) mesh1Min.y = tempHighVertex1[i].y;
		if (tempHighVertex1[i].z < mesh1Min.z) mesh1Min.z = tempHighVertex1[i].z;

	}

	_mesh1.getMesh()->UnlockVertexBuffer();

	DWORD mesh2FVF = _mesh2.getMesh()->GetFVF();
	D3DXVECTOR3* tempHighVertex2 = 0;
	_mesh2.getMesh()->LockVertexBuffer(0, (void**)&tempHighVertex2);
	for (DWORD i = 0; i < _mesh2.getMesh()->GetNumVertices(); ++i)
	{
		if (tempHighVertex2[i].x > mesh2Max.x) mesh2Max.x = tempHighVertex2[i].x;
		if (tempHighVertex2[i].y > mesh2Max.y) mesh2Max.y = tempHighVertex2[i].y;
		if (tempHighVertex2[i].z > mesh2Max.z) mesh2Max.z = tempHighVertex2[i].z;
		if (tempHighVertex2[i].x < mesh2Min.x) mesh2Min.x = tempHighVertex2[i].x;
		if (tempHighVertex2[i].y < mesh2Min.y) mesh2Min.y = tempHighVertex2[i].y;
		if (tempHighVertex2[i].z < mesh2Min.z) mesh2Min.z = tempHighVertex2[i].z;

	}

	_mesh2.getMesh()->UnlockVertexBuffer();

	D3DXVECTOR3 mesh1boundingBox[8];
	D3DXVECTOR3 mesh2boundingBox[8];

	// mesh1 ===============================================================
	// ¾Õ¸é
	mesh1boundingBox[0] = D3DXVECTOR3(mesh1Min.x, mesh1Max.y, mesh1Min.z);
	mesh1boundingBox[1] = D3DXVECTOR3(mesh1Max.x, mesh1Max.y, mesh1Min.z);
	mesh1boundingBox[2] = D3DXVECTOR3(mesh1Min.x, mesh1Min.y, mesh1Min.z);
	mesh1boundingBox[3] = D3DXVECTOR3(mesh1Max.x, mesh1Min.y, mesh1Min.z);

	//µÞ¸é
	mesh1boundingBox[4] = D3DXVECTOR3(mesh1Min.x, mesh1Max.y, mesh1Max.z);
	mesh1boundingBox[5] = D3DXVECTOR3(mesh1Max.x, mesh1Max.y, mesh1Max.z);
	mesh1boundingBox[6] = D3DXVECTOR3(mesh1Min.x, mesh1Min.y, mesh1Max.z);
	mesh1boundingBox[7] = D3DXVECTOR3(mesh1Max.x, mesh1Min.y, mesh1Max.z);
	// =====================================================================


	// mesh2 ===============================================================
	// ¾Õ¸é
	mesh2boundingBox[0] = D3DXVECTOR3(mesh2Min.x, mesh2Max.y, mesh2Min.z);
	mesh2boundingBox[1] = D3DXVECTOR3(mesh2Max.x, mesh2Max.y, mesh2Min.z);
	mesh2boundingBox[2] = D3DXVECTOR3(mesh2Min.x, mesh2Min.y, mesh2Min.z);
	mesh2boundingBox[3] = D3DXVECTOR3(mesh2Max.x, mesh2Min.y, mesh2Min.z);

	//µÞ¸é
	mesh2boundingBox[4] = D3DXVECTOR3(mesh2Min.x, mesh2Max.y, mesh2Max.z);
	mesh2boundingBox[5] = D3DXVECTOR3(mesh2Max.x, mesh2Max.y, mesh2Max.z);
	mesh2boundingBox[6] = D3DXVECTOR3(mesh2Min.x, mesh2Min.y, mesh2Max.z);
	mesh2boundingBox[7] = D3DXVECTOR3(mesh2Max.x, mesh2Min.y, mesh2Max.z);
	// =====================================================================
/*
	mesh1Max += _mesh1.getPos();
	mesh1Min += _mesh1.getPos();
	mesh2Max += _mesh2.getPos();
	mesh2Min += _mesh2.getPos();*/

	if (mesh1Max.x < mesh2Min.x ||
		mesh1Min.x < mesh2Max.x)
		return false;

	if (mesh1Max.y < mesh2Min.y ||
		mesh1Min.y < mesh2Max.y)
		return false;

	if (mesh1Max.z < mesh2Min.z ||
		mesh1Min.z < mesh2Max.z)
		return false;

	return true;

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