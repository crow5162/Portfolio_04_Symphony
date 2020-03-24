#pragma once
#include "Monster.h"

struct GARGOYLEANI
{
	animation*  leftIdle;
	animation*  rightIdle;
	animation*  leftFire;
	animation*  rightFire;
	animation*  leftGround;
	animation*  rightGround;
	animation*  leftGroundFire;
	animation*  rightGroundFire;
	animation*  leftCarryOn;
	animation*  rightCarryOn;
	animation*  death;
};

class Boss_Gargoyle : public Monster
{
private:
	GARGOYLEANI _ani;

	int _count;
	int _random;

public:
	Boss_Gargoyle();
	~Boss_Gargoyle();

	virtual HRESULT init(float x, float y, int monstertype, bool gravity);
	virtual void update();
	virtual void release();
	virtual void render();

	void GargoyleState();
	void GargoyleBehavior();
};

