#pragma once
#include "Header.h"
class CCamera
{
public:
	void Init();
	void Update();
	
	void setPos(D3DXVECTOR3 a_Eye);
	void setPosX(float x) { _eye.x = x; }
	void setPosY(float y) { _eye.y = y; }
	void setPosZ(float z) { _eye.z = z; }
	void setPos(float x, float y, float z) { _eye.x; _eye.y; _eye.z; }
	void setUp(D3DXVECTOR3 a_Up);
	void setUpX(float x) { _up.x = x; }
	void setUpY(float y) { _up.y = y; }
	void setUpZ(float z) { _up.z = z; }
	void setUp(float x, float y, float z) { _up.x = x; _up.y = y; _up.z = z; }
	void setLookat(D3DXVECTOR3 a_LookAt);
	void setLookatX(float x) { _lookAt.x = x; }
	void setLookatY(float y) { _lookAt.y = y; }
	void setLookatZ(float z) { _lookAt.z = z; }
	void setLookat(float x, float y, float z) { _lookAt.x = x; _lookAt.y = y; _lookAt.z = z; }
	void setProj(D3DXMATRIX a_Proj);
	void setView(D3DXMATRIX a_View);
	void setActive(bool a_Active);
	void setDegreeX(float x) { _degreeX = x; }
	void setDegreeY(float y) { _degreeY = y; }
	void setDegreeZ(float z) { _degreeZ = z; }
	void setQuaternion(D3DXQUATERNION a_qut) { _qut = a_qut; }

	D3DXVECTOR3 getPos();
	float getPosX() { return _eye.x; }
	float getPosY() { return _eye.y; }
	float getPosZ() { return _eye.z; }
	D3DXVECTOR3 getUp();
	float getUpX() { return _up.x; }
	float getUpY() { return _up.y; }
	float getUpZ() { return _up.z; }
	D3DXVECTOR3 getLookAt();
	float getLookAtX() { return _lookAt.x; }
	float getLookAtY() { return _lookAt.y; }
	float getLookAtZ() { return _lookAt.z; }
	D3DXMATRIX getProj();
	D3DXMATRIX getView();
	bool IsActive();
	float getDegreeX() { return _degreeX; }
	float getDegreeY() { return _degreeY; }
	float getDegreeZ() { return _degreeZ; }
	D3DXQUATERNION getQuternion() { return _qut; }


	CCamera();
	~CCamera();
private:
	D3DXVECTOR3 _eye;
	D3DXVECTOR3 _up;
	D3DXVECTOR3 _lookAt;

	float _degreeX;
	float _degreeY;
	float _degreeZ;

	D3DXQUATERNION _qut;

	D3DXMATRIX _proj;
	D3DXMATRIX _view;
	
	bool _isActive;
	

};

