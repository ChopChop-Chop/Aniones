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
	_eye = D3DXVECTOR3(0.0f, 0.0f, -150.0f);
	_up = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	_lookAt = D3DXVECTOR3(0.0f,0.0f,0.0f);

	D3DXMatrixIdentity(&_proj);
	D3DXMatrixIdentity(&_view);

	_isActive = false;
}
void CCamera::Update()
{
	if (_isActive)
	{

		D3DXMatrixLookAtLH(&_view, &_eye, &_lookAt, &_up);
		CDrawMgr->getDevice()->SetTransform(D3DTS_VIEW, &_view);				// 요건 카메라

		D3DXMatrixPerspectiveFovLH(&_proj, D3DX_PI / 4, 16 / 9, 1.0f, 1000.0f);
		CDrawMgr->getDevice()->SetTransform(D3DTS_PROJECTION, &_proj);				// 퍼스펙티브
	}
}
void CCamera::setEye(D3DXVECTOR3 a_Eye)
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

D3DXVECTOR3 CCamera::getEye()
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