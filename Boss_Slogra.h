#pragma once
#include "Monster.h"

struct SLOGRAANI
{
	animation*  leftIdle;
	animation*  rightIdle;
	animation*  leftMove;
	animation*  rightMove;
	animation*  leftAttack;
	animation*  rightAttack;
	animation*  attack2;
	animation*  attack3;
};
class Boss_Slogra : public Monster
{
private:
	SLOGRAANI _ani;

	int _count;

public:
	Boss_Slogra();
	~Boss_Slogra();

	virtual HRESULT init(float x, float y, int monstertype, bool gravity);
	virtual void update();
	virtual void release();
	virtual void render();

	void SlograState();
	void StateTest();
	void attackCount();
};

