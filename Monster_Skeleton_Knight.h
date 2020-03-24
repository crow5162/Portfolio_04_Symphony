#pragma once
#include "Monster.h"

#define SKELETONKNIGHTSPEED		2.5f
#define SKELETONKNIGHTWIDTH		60
#define SKELETONKNIGHTHEIGHT	118

class Monster_Skeleton_Knight : public Monster
{
private:

	int _moveFrameX, _moveFrameY;
	int _attackFrameX, _attackFrameY;

	int _frameCount;

	image* _moveImage;
	image* _attackImage;

public:
	Monster_Skeleton_Knight();
	~Monster_Skeleton_Knight();

	//Skeleton Spawn Position x, y, gravityIsActive
	virtual HRESULT init(float x, float y, int monstertype, bool GravityisActive);
	virtual void update();
	virtual void release();
	virtual void render();
	
	void SkeletonState();
	void SkelBehavior();
	
	//test Attack
	void SkeletonAttackRectMake();
	void LeftMoveFrame();
	void RightMoveFrame();
	void LeftAttackFrame();
	void RightAttackFrame();
};

