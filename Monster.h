#pragma once
#include "gameNode.h"
#include "MonsterAttack.h"

class MonsterAttack;

//�⺻���� State�� ���� �ൿ.
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
	//�ʵ� ����
	MONSTER_SKELETON,
	MONSTER_MEDUSAHEAD,
	MONSTER_MERMAN,
	MONSTER_SKELETONKNIGHT,
	MONSTER_KNIGHT,
	//���� ����
	BOSS_GARGOYLE,
	BOSS_SLOGRA,
	//���� ����
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

	//�浹 ó���� ���� ������ x, y��ǥ Get, Set
	float getMonsterY() { return _monsterInfo.y; }
	void setMonsterY(float y) { _monsterInfo.y = y; }
	void setMonsterX(float x) { _monsterInfo.x = x; }
	//�浹 ó���� ���� ������ Rect Get, Set (�Ʒ��� ������ �ʿ����.)
	RECT getMonsterRect() { return _monsterInfo.rc; }
	void setMonsterRect(RECT rc) { _monsterInfo.rc = rc; }
	//void setMonsterInfo(MONSTERINFO info) { _monsterInfo = info; }
	//Monster Gravity ON/OFF
	void setMonsterGravity(bool gravityisActive) { _monsterInfo.activeGravity = gravityisActive; }
	//MonsterManager���� �ൿ���� �Ҽ��ְ� ��������ϴ�.
	void setMonsterHavior(Behavior havior) { _monsterInfo.behavior = havior; }
	//���ʱ���� ��Ÿ�� Get
	bool getCoolDown() { return _coolDown; }
	void setCoolDown(bool cooldown) { _coolDown = cooldown; }
	//Monster StateSet ������ ���¸� �ٲߴϴ�.
	void setMonsterState(MonsterState state) { _monsterInfo.state = state; }
	//Monster �� ü���� ���ҽ�ŵ�ϴ�.
	void decreaseHP(int damage) { _monsterInfo.hp -= damage; }
	//Monster Attack Vector Get
	MonsterAttack* GetMAttack() { return _attack; }
	//Set isStop
	void SetisStop(bool isStop) { _isStop = isStop; }
	//Monster�� Info ������ Getter, Setter
	MONSTERINFO getMonsterInfo() { return _monsterInfo; }

	//������ �߷��� Monster�� �ȿ��� ���ְ��ִ�.
	//Monster�� Update�� Init�� ���ָ� �߷� ������ �����ϴ�.
	//Monster Gravity Set
	void Gravity();
	void GotoAngleMoving();
	void GotoAngleSpeedMoving();
	//���� �ð��ȿ� ���ϴ� ��ǥ���� �̵��ϴ� �Լ�.
	void GotoAngle(float startX, float startY, float targetX, float targetY, float totaltime);
	//���ϴ� ��ǥ���� �ӵ��� ���� �̵��ϴ� �Լ�.
	void GotoAngleSpeed(float targetX, float targetY, float speed);
};

