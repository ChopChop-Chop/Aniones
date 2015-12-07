#pragma once
#include "Bullet.h"
#include "Node.h"

enum BulletOwner
{
	Friend,
	Gas,
};

class CBulletManager : public CNode
{
public:
	bool Init();
	void Create(D3DXVECTOR3 pos, D3DXVECTOR3 target, float speed, float distance, BulletOwner bulletowner);
	void Update();

	CBullet** getBulletIndex1() { return _bulletIndex1; }
	CBullet** getBulletIndex2() { return _bulletIndex2; }
	CBullet* getBulletIndex1(int index) { return _bulletIndex1[index]; }
	CBullet* getBulletIndex2(int index) { return _bulletIndex2[index]; }
	int getBulletCount1() { return _bulletCount1; }
	int getBulletCount2() { return _bulletCount2; }
	int getMAXBULLET() { return _MAXBULLET; }

	void setBulletIndex1(CBullet** bullet) { _bulletIndex1 = bullet; }
	void setBulletIndex2(CBullet** bullet) { _bulletIndex2 = bullet; }
	void setBulletCount1(int bulletCount) { _bulletCount1 = bulletCount; }
	void setBulletCount2(int bulletCount) { _bulletCount2 = bulletCount; }


	CBulletManager();
	~CBulletManager();

private:
	CBullet** _bulletIndex1;		// 模备评
	CBullet** _bulletIndex2;		// 规备评

	int _bulletCount1;
	int _bulletCount2;

	const int _MAXBULLET;
};

