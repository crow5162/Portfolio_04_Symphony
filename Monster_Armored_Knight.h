#pragma once
#include "Monster.h"

#define KNIGHTWIDTH			80
#define KNIGHTHEIGHT		200
#define KNIGHTSPEED			1.5f
#define KNIGHTGEAVITY		3.5f
#define KNIGHTATTACKSPEED	16.5f

class Monster_Armored_Knight : public Monster
{
private:

	int _moveFrameX,	 _moveFrameY;
	int _deathFrameX,	 _deathFrameY;
	int _attackFrameX,	 _attackFrameY;
	int _attack2FrameX,  _attack2FrameY;
	int _attack3FrameX,  _attack3FrameY;
	int _frameCount;

	int _stabCount;

	image* _moveImage;
	image* _deathImage;
	image* _attackImage;
	image* _attack2Image;
	image* _attack3Image;

public:
	Monster_Armored_Knight();
	~Monster_Armored_Knight();

	virtual HRESULT init(float posx, float posy, int monstertype, bool gravityActive);
	virtual void update();
	virtual void release();
	virtual void render();

	//갑옷기사의 상태
	void ArmoredKnightState();
	//갑옷기사의 행동패턴
	void ArmoredKnightBehavior();
	//공격렉트 생성 테스트
	void AttackRectMakeTest();
	

	//갑옷기사 프레임 카운터
	void leftMoveFrame();
	void rightMoveFrame();
	void LeftAttackFrame();
	void RightAttackFrame();
	void LeftAttack2Frame();
	void RightAttack2Frame();
	void LeftAttack3Frame();
	void RightAttack3Frame();
	void DeathFrame();
};

