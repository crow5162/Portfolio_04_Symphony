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

	//�Ϲݸ����� �⺻���� ���� (�ٰŸ�)
	void NormalMonsterAttack(float x, float y, int width, int height, int duration);
	//������ ���� ���� (���Ÿ�) �������� ��� Ÿ�� 1�� ����.
	void MagicFireAngle(float x, float y, float angle, float speed, int type);
	//������ ���� ���� (���Ÿ�) (���ӽð��� �����ش�.)
	void MagicFireAngleDuration(float x, float y, float angle, float speed, int type, int duration);
	//������ ���� ���� (���Ÿ�) �������� ��� Ÿ�� 1�� ����. ���� ���� ���� 0 ������ 1
	void MagicFire(float x, float y, float speed, int Direction, int type);

	void EraseAttack();
	void AttackDelete(int arrNum);
	void MagicMove();

	//Monster���� ����� Vector Get
	vector<MAttack> getMonsterAttackV() { return _vMonsterAttack; }
	vector<MAttack>::iterator getMonsterAttackVi() { return _viMonsterAttack; }
};

