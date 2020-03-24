#pragma once
#include "gameNode.h"
#include "MonsterManager.h"
#include "Alucard.h"
#include "ItemManager.h"

class MonsterManager;
class Alucard;
class ItemManager;
class GameData;

//MapMaster가 모든 맵 클래스를 상속해주고 있으니까 여기에 플레이어와 에너미 연동해주면
//다른곳에서도 사용할 수 있다. 아래는 카메라 및 맵 테스트용 Rect 생성.
//MapMaster에서 MonsterManager를 init, update, render, release해주고 있기때문에 
//각 Map에서 불러와주지 않으면 MOnster 그려지지 않는다.

struct GROUND
{
	float x, y;
	RECT rc;
	bool isDraw;
};

struct NEXTSTAGE
{
	float x;
	float y;
	float width;
	float height;

	RECT rc;
};

struct PREVIOUSSTAGE
{
	float x;
	float y;
	float width;
	float height;

	RECT rc;
};

enum Select
{
	SelectEquip,
	SelectSpells,
	SelectRelics,
	SelectFamiliars,
};

enum Informaion
{
	NoneInfo,
	EquipInfo,
	SpellsInfo,
	RelicsInfo,
	FamiliarsInfo,
};

enum EquipInformation
{
	Weapon,
	Armor,
	Armor2
};

enum EquipSelect
{
	index,
	index2,
	index3,
	index4,
	index5,
	index6,
};

struct Damage
{
	float x;
	float y;

	int damageCount;
	int timeCount;
	int color;
};

struct UI
{
	bool uiStart;
	bool interfaceStart;
	bool informationStart;
	bool selectEquip;
	int alphaValue;
	image* blackScreen;

	image* StatusInfo;
	image* Infoimg;
	Select select;
	EquipSelect _selectEquip;
	Informaion info;
	EquipInformation equipInformation;
};

struct HUD
{
	float x, y;
	float x2, y2;

	image* img;
	image* img2;
	animation* ani;
};

// c++ 한정으로 접근지정자를 쓰지 않았을 경우
// struct는 public으로, class는 private으로 잡힌다.
//struct abc
//{
//public:
//	int a = 0;
//};
//class bbc
//{
//private:
//	int a = 0;
//};


class MapMaster : public gameNode
{
public:
	static GameData* gameData;
	static GameData* GetData();
private:



protected:
	vector<Damage*>		_vDamage;
	//플레이어의 시작좌표 설정용
	float _playerStartPosX;
	float _playerStartPosY;
	int _testCount;
	bool _openMiniMap;
	RECT _miniPlayer;

	MonsterManager* _monsterManager;
	Alucard* _alucard;
	NEXTSTAGE _stageChange;
	PREVIOUSSTAGE _preStage;
	HUD _hud;
	UI _ui;
	ItemManager* _item;

	image* NumImg[10];
	image* DamageNum[10];
	image* EDamageNum[10];

public:

	MapMaster();
	~MapMaster();

	virtual HRESULT init();
	virtual void update();
	virtual void release();
	virtual void render();

	void MonsterHit();
	void CharacterHit();
	void CharacterHit2();
	void ItemCollision();
	void UiInterface();

	void DrawNumber(int Num, int destX, int destY);
	void DrawDamageNum(int Num, int destX, int destY);
	void DrawEDamageNum(int Num, int destX, int destY);
	void RandomSpawnItem(int x, int y);
};

#define DATA MapMaster::GetData()