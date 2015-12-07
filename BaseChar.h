#pragma once
#include <string>
#include "Mesh.h"
#include "Node.h"

struct CharInfo				// 나중에 클래스로 돌리고 JSON 연동
{
	int _id;
	std::string _name;
	std::string _desc;
	std::string _meshDirectory;
};

class CBaseChar : public CNode
{
public:
	void Init(int id);
	void Update();

	CMesh* getModel() { return _model; }
	float getAttackDelay() { return _attackDelay; }
	float getSpeed() { return _speed; }
	float getPower() { return _power; }
	float getHP() { return _hp; }
	int getHorizontal() { return _h; }
	int getVertical() { return _v; }
	CharInfo* getCharInfo() { return _info; }
	D3DXVECTOR3 getLookDirection() { return _lookDirection; }
	float getLookDirectionX() { return _lookDirection.x; }
	float getLookDirectionZ() { return _lookDirection.z; }
	D3DXVECTOR3 getMoveDirection() { return _moveDirection; }
	float getMoveDirectionX() { return _moveDirection.x; }
	float getMoveDirectionZ() { return _moveDirection.z; }
	bool IsMove() { return _isMove; }
	bool IsAttack() { return _isAttack; }
	bool IsHurt() { return _isHurt; }

	void setAttackDelay(float delay) { _attackDelay = delay; }
	void setLookDirection(float x, float z) { _lookDirection.x = x; _lookDirection.z = z; }
	void setLookDirection(D3DXVECTOR3 look) { _lookDirection = look; }
	void setLookDirectionX(float x) { _lookDirection.x = x; }
	void setLookDirectionZ(float z) { _lookDirection.z = z; }
	void setMoveDirection(float x, float z) { _moveDirection.x = x; _moveDirection.z = z; }
	void setMoveDirection(D3DXVECTOR3 dir) { _moveDirection = dir; }
	void setModel(CMesh* a_model) { _model = a_model; }
	void setSpeed(float a_speed) { _speed = a_speed; }
	void setPower(float a_power) { _power = a_power; }
	void setHP(float a_hp) { _hp = a_hp; }
	void setCharInfo(CharInfo* a_Info) { _info = a_Info; }
	void setIsMove(bool a_isMove) { _isMove = a_isMove; }
	void setIsAttack(bool a_isAttack) { _isAttack = a_isAttack; }
	void setIsHurt(bool a_isHurt) { _isHurt = a_isHurt; }
	void setHorizontal(int h) { _h = h; }
	void setVertical(int v) { _v = v; }
	
	CBaseChar();
	virtual ~CBaseChar();

protected:
	CMesh* _model;

	float _attackDelay;	// 공격 간격 
	float _speed;		// 이동속도
	float _power;		// 공격력
	float _hp;			// hp


	int _h;		// 수평
	int _v;		// 수직
	
	CharInfo* _info;

	bool _isMove;
	bool _isAttack;
	bool _isHurt;

	D3DXVECTOR3 _moveDirection;
	D3DXVECTOR3 _lookDirection;
};

