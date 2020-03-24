#pragma once
#include "Monster.h"
#include <time.h>

#define MERMANSPEED		2.0f
#define MERMANSWIMSPEED 0.5f
#define MERMANJUMPPOWER	4.5f
#define MERMANWIDTH		50
#define MERMANHEIGHT	103

class Monster_Merman : public Monster
{
private:
	//random Move Count
	int _randomMove;

	//State Frame Set
	int _moveFrameX, _moveFrameY;
	int _swimFrameX, _swimFrameY;
	int _divingFrameX, _divingFrameY;
	int _fireFrameX, _fireFrameY;
	int _deathFrameX, _deathFrameY;
	int _frameCount;

public:
	Monster_Merman();
	~Monster_Merman();

	virtual HRESULT init(float x, float y, int monstertype, bool gravityAcvite);
	virtual void update();
	virtual void release();
	virtual void render();

	void MerManState();
	void MerManBehavior();

	void LeftMoveFrame();
	void RightMoveFrame();
	void LeftSwimFrame();
	void RightSwimFrame();
	void DivingFrame();
	void LeftFireFrame();
	void RightFireFrame();
	void DeathFrame();
};

