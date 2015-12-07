#include "BulletManager.h"


CBulletManager::CBulletManager()
: _MAXBULLET(70)
{
	_bulletIndex1 = new CBullet*[_MAXBULLET];
	_bulletIndex2 = new CBullet*[_MAXBULLET];

	for (int i = 0; i < _MAXBULLET; i++)
	{
		_bulletIndex1[i] = new CBullet();
	}
	for (int i = 0; i < _MAXBULLET; i++)
	{
		_bulletIndex2[i] = new CBullet();
	}

}


CBulletManager::~CBulletManager()
{
	for (int i = _MAXBULLET - 1; i >= 0; i--)
	{
		delete _bulletIndex1[i];
	}
	for (int i = _MAXBULLET - 1; i >= 0; i--)
	{
		delete _bulletIndex2[i];
	}
}
bool CBulletManager::Init()
{
	
	for (int i = 0; i < _MAXBULLET; i++)
	{
		_bulletIndex1[i]->Init();
	}
	for (int i = 0; i < _MAXBULLET; i++)
	{
		_bulletIndex2[i]->Init();
	}

	_bulletCount1 = 0;
	_bulletCount2 = 0;

	for (int i = 0; i < _MAXBULLET; i++)
	{
		addChild(_bulletIndex1[i]);
		addChild(_bulletIndex2[i]);
	}

	return true;
}
void CBulletManager::Create(D3DXVECTOR3 pos, D3DXVECTOR3 target, float speed, float distance, BulletOwner bulletowner)
{
	if (_bulletCount1 >= _MAXBULLET)
	{
		_bulletCount1 = 0;
	}
	if (_bulletCount2 >= _MAXBULLET)
	{
		_bulletCount2 = 0;
	}

	switch (bulletowner)
	{
	case BulletOwner::Friend:
		_bulletIndex1[_bulletCount1]->Create(pos, target, speed, distance);
		_bulletCount1++;
		break;
	case BulletOwner::Gas:
		_bulletIndex2[_bulletCount2]->Create(pos, target, speed, distance);
		_bulletCount2++;
		break;
	}
}
void CBulletManager::Update()
{
	for (int i = 0; i < _MAXBULLET; i++)
	{
		_bulletIndex1[i]->Update();
		_bulletIndex2[i]->Update();
	}

	// TODO : 충돌처리
}