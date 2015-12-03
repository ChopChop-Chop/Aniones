#pragma once
#include "Header.h"
class CCamera
{
public:
	void Init();
	void Update();
	
	void setEye(D3DXVECTOR3 a_Eye);
	void setUp(D3DXVECTOR3 a_Up);
	void setLookat(D3DXVECTOR3 a_LookAt);
	void setProj(D3DXMATRIX a_Proj);
	void setView(D3DXMATRIX a_View);
	void setActive(bool a_Active);

	D3DXVECTOR3 getEye();
	D3DXVECTOR3 getUp();
	D3DXVECTOR3 getLookAt();
	D3DXMATRIX getProj();
	D3DXMATRIX getView();
	bool IsActive();


	CCamera();
	~CCamera();
private:
	D3DXVECTOR3 _eye;
	D3DXVECTOR3 _up;
	D3DXVECTOR3 _lookAt;

	D3DXMATRIX _proj;
	D3DXMATRIX _view;
	
	bool _isActive;
	

};

