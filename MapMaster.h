#pragma once
#include "gameNode.h"
#include "MonsterManager.h"
#include "Alucard.h"
#include "ItemManager.h"

class MonsterManager;
class Alucard;
class ItemManager;
class GameData;

//MapMaster�� ��� �� Ŭ������ ������ְ� �����ϱ� ���⿡ �÷��̾�� ���ʹ� �������ָ�
//�ٸ��������� ����� �� �ִ�. �Ʒ��� ī�޶� �� �� �׽�Ʈ�� Rect ����.
//MapMaster���� MonsterManager�� init, update, render, release���ְ� �ֱ⶧���� 
//�� Map���� �ҷ������� ������ MOnster �׷����� �ʴ´�.

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

// c++ �������� ���������ڸ� ���� �ʾ��� ���
// struct�� public����, class�� private���� ������.
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
	//�÷��̾��� ������ǥ ������
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