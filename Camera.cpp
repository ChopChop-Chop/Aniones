#include "Camera.h"
#include "Director.h"


CCamera::CCamera()
{
	
}


CCamera::~CCamera()
{
}

void CCamera::Init()
{
	_eye = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	_up = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	_lookAt = D3DXVECTOR3(0.0f,0.0f,0.0f);

	D3DXMatrixIdentity(&_proj);
	D3DXMatrixIdentity(&_view);
	D3DXQuaternionIdentity(&_qut);

	_degreeX = 0;
	_degreeY = 0;
	_degreeZ = 0;

	_isActive = false;
}
void CCamera::Update()
{
	if (_isActive)
	{
		D3DXQuaternionRotationYawPitchRoll(&_qut, D3DXToRadian(_degreeY), D3DXToRadian(_degreeX), D3DXToRadian(_degreeZ));
		D3DXMatrixRotationQuaternion(&_view, &_qut);

		D3DXMatrixLookAtLH(&_view, &_eye, &_lookAt, &_up);
		CDrawMgr->getDevice()->SetTransform(D3DTS_VIEW, &_view);				// 요건 카메라

		D3DXMatrixPerspectiveFovLH(&_proj, D3DX_PI / 4, 1280 / 720, 0.5f, 1000.0f);
		CDrawMgr->getDevice()->SetTransform(D3DTS_PROJECTION, &_proj);				// 퍼스펙티브
	}
}
void CCamera::setPos(D3DXVECTOR3 a_Eye)
{
	_eye = a_Eye;
}
void CCamera::setUp(D3DXVECTOR3 a_Up)
{
	_up = a_Up;
}
void CCamera::setLookat(D3DXVECTOR3 a_LookAt)
{
	_lookAt = a_LookAt;
}
void CCamera::setProj(D3DXMATRIX a_Proj)
{
	_proj = a_Proj;
}
void CCamera::setView(D3DXMATRIX a_View)
{
	_view = a_View;
}
void CCamera::setActive(bool a_Active)
{
	_isActive = a_Active;
}

D3DXVECTOR3 CCamera::getPos()
{
	return _eye;
}
D3DXVECTOR3 CCamera::getUp()
{
	return _up;
}
D3DXVECTOR3 CCamera::getLookAt()
{
	return _lookAt;
}
D3DXMATRIX CCamera::getProj()
{
	return _proj;
}
D3DXMATRIX CCamera::getView()
{
	return _view;
}
bool CCamera::IsActive()
{
	return _isActive;
}