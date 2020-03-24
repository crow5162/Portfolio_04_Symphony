#pragma once
#include "gameNode.h"
#include "Alucard.h"

#include "Monster_Skeleton_Knight.h"
#include "Monster_Skeleton.h"
#include "Monster_Medusa_Head.h"
#include "Monster_Armored_Knight.h"
#include "Monster_Merman.h"

#include "Boss_Gargoyle.h"
#include "Boss_Slogra.h"
#include "Boss_Death.h"

class Monster;
class Alucard;
class MapMaster;

struct BossPattern
{
	int  timer;
	int    random;
	bool   check;
	float speed;
};

class MonsterManager : public gameNode
{
private:
	typedef vector<Monster*>			 vMonster;
	typedef vector<Monster*>::iterator	 viMonster;

private:
	BossPattern _pattern;

	vMonster	_vMonster;
	viMonster	_viMonster;

	Monster* _monster;
	Alucard* _alucard;
	MapMaster* _map;

	bool _gravity;

public:
	MonsterManager() {};
	~MonsterManager() {};

	virtual HRESULT init();
	virtual void update();
	virtual void release();
	virtual void render();

	void EraseMonster();
	//���� ���� �����ִ� �Լ�.
	void DeleteMonster(int arrNum);

	//���ʱ���� �ൿ����
	void ArmoredKnightBehavior();
	//���̷��� ����� �ൿ����.
	void SkeletonKnightBehavior();
	//�����ϰ� ���α׶��� ��������.
	void GargoyleAndSlogra();
	//�������� ������ ��������.
	void DeathBehavior();

	//���̷��� ��� ���� ��ǥ Set(float x, y) �߷���������(bool gravity) (Vector�� PushBack ���ش�.)
	void Skeleton_Knight_Set(float posx, float posy, bool activeGravity);
	//���̷��� ���� ��ǥ Set(float x, float y, bool �߷���������) (Vector�� Push_Back ���ش�.)
	void Skeleton_Set(float posx, float posy, bool activeGravity);
	//�޵λ� ��� ���� ��ǥ Set (x, y, �߷�����, �޵λ��� ���� 0 == ���, 0 != �Ķ�, �޵λ��� �̵����� ���� 0 = ����, 1 = ������)
	void Medusa_Head_Set(float posx, float posy, bool activeGravity, int medusaKind, bool direction);
	//���� ��� ���� ��ǥ Set
	void Armored_Knight_Set(float posx, float posy, bool activeGravity);
	//����(MerMan) ���� ��ǥ Set
	void Merman_Set(float posx, float posy, bool activeGravity);
	//���� ������ ������ǥ Set
	void Gergoyle_Set(float posx, float posy, bool activegravity);
	//���� ���α׶� ������ǥ Set
	void Slogra_Set(float posx, float posy, bool activegravity);
	//�������� ������ ������ǥ Set
	void DeathSet(float posx, float posy, bool activegravity);

	//�Ŵ������� ��������� ���͵��� �θ��� ���Ϳ� ����.
	//Map�� MonsterManager�� �˰������� �θ����ִ�.

	//Alucard�� Set Link
	void SetLink_Alucard(Alucard* alucard) { _alucard = alucard; }

	//���� ���� Getter
	vector<Monster*>		   getMonsterVector()	  { return _vMonster; }
	vector<Monster*>::iterator getMonsterVectorIter() { return _viMonster;}
};

