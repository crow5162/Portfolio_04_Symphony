#pragma once
#include "Monster.h"

#define DEATHWIDTH 80
#define DEATHHEIGHT 180

struct DEATHANI
{
	animation* leftIdle;
	animation* rightIdle;
	animation* leftAttack;
	animation* rightAttack;
	animation* leftAttack2;
	animation* rightAttack2;
	animation* leftAttack3;
	animation* rightAttack3;
};

class Boss_Death : public Monster
{
private:
	DEATHANI _ani;
	int _count;

public:
	Boss_Death();
	~Boss_Death();

	virtual HRESULT init(float x, float y, int monstertype, bool gravity);
	virtual void update();
	virtual void release();
	virtual void render();

	void DeathState();
	void DeathBehavior();
};

