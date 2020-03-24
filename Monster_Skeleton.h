#pragma once
#include "Monster.h"
#include <time.h>

#define SKELETONSPEED	2.5f
#define SKELETONWIDTH	67
#define SKELETONHEIGHT	118

class Monster_Skeleton : public Monster
{
private:

	int _frameCount;

	int _moveFrameX, _moveFrameY;
	int _deathFrameX, _deathFrameY;

public:
	Monster_Skeleton();
	~Monster_Skeleton();
	
	virtual HRESULT init(float x, float y, bool gravityisActive, int monstertype);
	virtual void update();
	virtual void release();
	virtual void render();

	void SkeletonState();
	void SkeletonBehavior();

	void LeftMoveFrame();
	void RightMoveFrame();
	void DeathFrame();

};

