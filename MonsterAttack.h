#pragma once
#include "gameNode.h"

enum MagicType
{
	Normal_Attack,
	Gargoyle_Fire,
	Gargoyle_Fire2,
	Death_Magic,
	Death_Magic2,
	Death_Magic3
};

struct MAttack
{
	RECT rc;
	float x;
	float y;
	float angle;
	float speed;
	int duration;
	int time;

	int width;
	int height;

	image* img;
	int currentX, currentY;
	int frameCount;
	MagicType type;
};

class MonsterAttack : public gameNode
{
private:
	vector<MAttack>			_vMonsterAttack;
	vector<MAttack>::iterator _viMonsterAttack;

public:
	MonsterAttack() {};
	~MonsterAttack() {};

	virtual HRESULT init();
	virtual void update();
	virtual void release();
	virtual void render();

	//일반몹들의 기본적인 공격 (근거리)
	void NormalMonsterAttack(float x, float y, int width, int height, int duration);
	//몬스터의 마법 공격 (원거리) 가고일의 경우 타입 1로 지정.
	void MagicFireAngle(float x, float y, float angle, float speed, int type);
	//몬스터의 마법 공격 (원거리) (지속시간을 정해준다.)
	void MagicFireAngleDuration(float x, float y, float angle, float speed, int type, int duration);
	//몬스터의 마법 공격 (원거리) 가고일의 경우 타입 1로 지정. 방향 결정 왼쪽 0 오른쪽 1
	void MagicFire(float x, float y, float speed, int Direction, int type);

	void EraseAttack();
	void AttackDelete(int arrNum);
	void MagicMove();

	//Monster에서 사용할 Vector Get
	vector<MAttack> getMonsterAttackV() { return _vMonsterAttack; }
	vector<MAttack>::iterator getMonsterAttackVi() { return _viMonsterAttack; }
};

