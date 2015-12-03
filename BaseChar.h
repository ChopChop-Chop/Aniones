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
	float getSpeed() { return _speed; }
	float getPower() { return _power; }
	float getHP() { return _hp; }
	float getHorizontal() { return _h; }
	float getVertical() { return _v; }
	CharInfo* getCharInfo() { return _info; }
	bool IsJump() { return _isJump; }
	bool IsMove() { return _isMove; }
	bool IsHorizontalMove() { return _isHorizontalMove; }
	bool IsVerticalMove() { return _isVerticalMove; }
	bool IsAttack() { return _isAttack; }
	bool IsHurt() { return _isHurt; }

	void setModel(CMesh* a_model) { _model = a_model; }
	void setSpeed(float a_speed) { _speed = a_speed; }
	void setPower(float a_power) { _power = a_power; }
	void setHP(float a_hp) { _hp = a_hp; }
	void setHorizontal(float a_h) { _h = a_h; }			// 외부에서 조작
	void setVertical(float a_v) { _v = a_v; }			// 외부에서 조작
	void moveRight() {
		if (_h < 1) _h += 0.1; _isMove = true; _isHorizontalMove = true;
	}
	void moveLeft() { if (_h > -1) _h -= 0.1; _isMove = true; _isHorizontalMove = true; }
	void moveForword() { if (_v < 1) _v += 1; _isMove = true; _isVerticalMove = true; }
	void moveBack() { if (_v > 1) _v -= 1; _isMove = true; _isVerticalMove = true; }
	void setCharInfo(CharInfo* a_Info) { _info = a_Info; }
	void setIsJump(bool a_isJump) { _isJump = a_isJump; }
	void setIsMove(bool a_isMove) { _isMove = a_isMove; }
	void setIsHorizontalMove(bool a_isHorizontalMove) { _isHorizontalMove = a_isHorizontalMove; }
	void setIsVerticalMove(bool a_isVerticalMove) { _isVerticalMove = a_isVerticalMove; }
	void setIsAttack(bool a_isAttack) { _isAttack = a_isAttack; }
	void setIsHurt(bool a_isHurt) { _isHurt = a_isHurt; }
	
	CBaseChar();
	virtual ~CBaseChar();

protected:
	CMesh* _model;

	float _speed;		// 이동속도
	float _power;		// 공격력
	float _hp;			// hp

	float _h;
	float _v;
	
	CharInfo* _info;

	bool _isJump;
	bool _isMove;
	bool _isHorizontalMove;
	bool _isVerticalMove;
	bool _isAttack;
	bool _isHurt;
};

