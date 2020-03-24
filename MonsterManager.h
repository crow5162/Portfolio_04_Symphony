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
	//자폭 몬스터 지워주는 함수.
	void DeleteMonster(int arrNum);

	//갑옷기사의 행동패턴
	void ArmoredKnightBehavior();
	//스켈레톤 기사의 행동패턴.
	void SkeletonKnightBehavior();
	//가고일과 슬로그라의 공격패턴.
	void GargoyleAndSlogra();
	//최종보스 데스의 공격패턴.
	void DeathBehavior();

	//스켈레톤 기사 생성 좌표 Set(float x, y) 중력적용유무(bool gravity) (Vector에 PushBack 해준다.)
	void Skeleton_Knight_Set(float posx, float posy, bool activeGravity);
	//스켈레톤 생성 좌표 Set(float x, float y, bool 중력적용유무) (Vector에 Push_Back 해준다.)
	void Skeleton_Set(float posx, float posy, bool activeGravity);
	//메두사 헤드 생성 좌표 Set (x, y, 중력유무, 메두사의 종류 0 == 노랑, 0 != 파랑, 메두사의 이동방향 결정 0 = 왼쪽, 1 = 오른쪽)
	void Medusa_Head_Set(float posx, float posy, bool activeGravity, int medusaKind, bool direction);
	//갑옷 기사 생성 좌표 Set
	void Armored_Knight_Set(float posx, float posy, bool activeGravity);
	//어인(MerMan) 생성 좌표 Set
	void Merman_Set(float posx, float posy, bool activeGravity);
	//보스 가고일 생성좌표 Set
	void Gergoyle_Set(float posx, float posy, bool activegravity);
	//보스 슬로그라 생성좌표 Set
	void Slogra_Set(float posx, float posy, bool activegravity);
	//최종보스 데쓰의 생성좌표 Set
	void DeathSet(float posx, float posy, bool activegravity);

	//매니저에서 모든종류의 몬스터들을 부르고 벡터에 담긴다.
	//Map은 MonsterManager만 알고있으면 부를수있다.

	//Alucard와 Set Link
	void SetLink_Alucard(Alucard* alucard) { _alucard = alucard; }

	//몬스터 벡터 Getter
	vector<Monster*>		   getMonsterVector()	  { return _vMonster; }
	vector<Monster*>::iterator getMonsterVectorIter() { return _viMonster;}
};

