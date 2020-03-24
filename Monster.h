#pragma once
#include "gameNode.h"
#include "MonsterAttack.h"

class MonsterAttack;

//기본적인 State로 만들어낼 행동.
enum Behavior
{
	MOVING,
	SWIM,

	ATTACKING_LEFT,
	ATTACKING_RIGHT,

	KNIGHT_LEFT_STAB,
	KNIGHT_RIGHT_STAB,

	Death_Detected,
	Death_Attack_01_Left,
	Death_Attack_01_Right,
	Death_Attack_02_Left,
	Death_Attack_02_Right,
	Death_Attack_03_Left,
	Death_Attack_03_Right,
};

enum MonsterType
{
	//필드 몬스터
	MONSTER_SKELETON,
	MONSTER_MEDUSAHEAD,
	MONSTER_MERMAN,
	MONSTER_SKELETONKNIGHT,
	MONSTER_KNIGHT,
	//보스 몬스터
	BOSS_GARGOYLE,
	BOSS_SLOGRA,
	//최종 보스
	BOSS_REAPER
};

enum MonsterState
{
	IDLE_LEFT,
	IDLE_RIGHT,
	MOVE_LEFT,
	MOVE_RIGHT,
	ATTACK_LEFT,
	ATTACK_RIGHT,
	ATTACK2_LEFT,
	ATTACK2_RIGHT,
	ATTACK3_LEFT,
	ATTACK3_RIGHT,
	DEATH,

	//MerMan State
	SWIM_LEFT,
	SWIM_RIGHT,
	DIVING,
	FIRE_LEFT,
	FIRE_RIGHT,
};

//test
struct ATTACKRECT
{
	RECT rc;
	float x;
	float y;
	int width;
	int height;
	bool isAttack;
};

struct MONSTERINFO
{
	RECT rc;
	float x, y;
	float speed;
	int width;
	int height;
	int hp;
	image* image;
	animation* ani;
	bool activeGravity;
	float gravity;
	float angle;
	int damage;
	int def;

	MonsterState state;
	MonsterType monsterType;
	ATTACKRECT attackCheck;
	Behavior behavior;
};

class Monster : public gameNode
{
protected:
	MONSTERINFO _monsterInfo;
	MonsterAttack* _attack;
	
	int _beCount;
	bool _coolDown;

	bool _isMoving;
	bool _isStop;
	float _endX, _endY;
	float _endX2, _endY2;
	float _worldTimeCount;
	float _travelRange;
	float _time;
	float _speed;

public:
	Monster();
	~Monster();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	//충돌 처리를 위한 몬스터의 x, y좌표 Get, Set
	float getMonsterY() { return _monsterInfo.y; }
	void setMonsterY(float y) { _monsterInfo.y = y; }
	void setMonsterX(float x) { _monsterInfo.x = x; }
	//충돌 처리를 위한 몬스터의 Rect Get, Set (아래꺼 있으면 필요없다.)
	RECT getMonsterRect() { return _monsterInfo.rc; }
	void setMonsterRect(RECT rc) { _monsterInfo.rc = rc; }
	//void setMonsterInfo(MONSTERINFO info) { _monsterInfo = info; }
	//Monster Gravity ON/OFF
	void setMonsterGravity(bool gravityisActive) { _monsterInfo.activeGravity = gravityisActive; }
	//MonsterManager에서 행동관리 할수있게 만들었습니다.
	void setMonsterHavior(Behavior havior) { _monsterInfo.behavior = havior; }
	//갑옷기사의 쿨타임 Get
	bool getCoolDown() { return _coolDown; }
	void setCoolDown(bool cooldown) { _coolDown = cooldown; }
	//Monster StateSet 몬스터의 상태를 바꿉니다.
	void setMonsterState(MonsterState state) { _monsterInfo.state = state; }
	//Monster 의 체력을 감소시킵니다.
	void decreaseHP(int damage) { _monsterInfo.hp -= damage; }
	//Monster Attack Vector Get
	MonsterAttack* GetMAttack() { return _attack; }
	//Set isStop
	void SetisStop(bool isStop) { _isStop = isStop; }
	//Monster의 Info 수정할 Getter, Setter
	MONSTERINFO getMonsterInfo() { return _monsterInfo; }

	//몬스터의 중력은 Monster의 안에서 해주고있다.
	//Monster의 Update와 Init을 해주면 중력 적용이 가능하다.
	//Monster Gravity Set
	void Gravity();
	void GotoAngleMoving();
	void GotoAngleSpeedMoving();
	//일정 시간안에 원하는 좌표까지 이동하는 함수.
	void GotoAngle(float startX, float startY, float targetX, float targetY, float totaltime);
	//원하는 좌표까지 속도에 따라 이동하는 함수.
	void GotoAngleSpeed(float targetX, float targetY, float speed);
};

