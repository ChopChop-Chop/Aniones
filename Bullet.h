#pragma once
#include "Mesh.h"

enum BulletType
{
	ARC,
	LINEAR,
};

class CBullet : public CNode
{
public:
	bool Init();
	void Create(D3DXVECTOR3 pos, D3DXVECTOR3 target, float speed, float distance);
	void Update();
	
	void setTarget(D3DXVECTOR3 target) { _targetDirection = target; }
	void setSpeed(float speed) { _speed = speed; }
	void setDistance(float distance) { _distance = distance; }
	void setMesh(CMesh* model) { _model = model; }

	D3DXVECTOR3 getTarget() { return _targetDirection; }
	float getSpeed() { return _speed; }
	float getDistance() { return _distance; }
	CMesh* getMesh() { return _model; }

	CBullet();
	~CBullet();
private:
	CMesh* _model;

	D3DXVECTOR3 _targetDirection;
	float _speed;
	float _movedDistance;
	float _distance;
};

