#pragma once
#include "Item.h"

class Item;

struct PlayerInfo
{
	int maxHp;
	int currentHp;
	int maxMana;
	int currentMana;

	int Gold;
	int Kills;

	int initX;
	int initO;

	int playerAtk;
	int playerDef;

	int STR;
	int CON;
	int INT;
	int LCK;

	int characterLevel;

	int currentExp;
	int maxExp;

	int swordType;

	int characterLocation;

	vector<Item*>				_vInven;
	vector<Item*>::iterator		_viInven;

	PlayerInfo()
	{
		maxHp = 80;
		currentHp = 80;
		maxMana = 35;
		currentMana = 35;

		Gold = 0;
		Kills = 0;

		playerAtk = 0;
		playerDef = 3;

		initX = 0;
		initO = 0;

		STR = 15;
		CON = 17;
		INT = 12;
		LCK = 14;

		characterLevel = 1;

		currentExp = 0;
		maxExp = 150;

		swordType = 0;

		characterLocation = 0;
	}
};

class GameData
{
public:
	PlayerInfo playerInfo;

	GameData();
	~GameData();

};
