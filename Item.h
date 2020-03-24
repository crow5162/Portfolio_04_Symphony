#pragma once
#include "gameNode.h"

enum ItemType
{
	Weapon_01,
	Weapon_02,
	Immediate_01,
	Immediate_02,
	Gold,
};

struct ItemSt
{
	ItemType type;
	float x, y;
	RECT rc;
	float invenX, invenY;
	int Heal;
	int Mana;
	int gold;
	int atk;
	int def;
	bool gravity;

	image* img;
	string itemName;
};

class Item : public gameNode
{
private:

protected:
	ItemSt _item;


public:
	Item();
	~Item();

	virtual HRESULT init();
	virtual void update();
	virtual void release();
	virtual void render();

	RECT getItemRect() { return _item.rc; }
	ItemSt getItemInfo() { return _item; }
	void setItemGravity(bool gravity) { _item.gravity = gravity; }
	void setItemX(float x) { _item.x; }
	void setItemY(float y) { _item.y; }
};

