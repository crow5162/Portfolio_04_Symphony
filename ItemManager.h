#pragma once
#include "gameNode.h"

#include "HealItem.h"
#include "ManaItem.h"
#include "Sword.h"
#include "Sword_02.h"
#include "Item_Money.h"

class Item;

class ItemManager : public gameNode
{
private:
	vector<Item*>				_vItem;
	vector<Item*>::iterator		_viItem;

public:
	ItemManager();
	~ItemManager();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void EraseItem(int arrNum);

	void HealItemSet(float x, float y);
	void ManaItemSet(float x, float y);
	void MoneyItemSet(float x, float y);
	void WeaponItemSet(float x, float y);
	void WeaponItem2Set(float x, float y);

	vector<Item*>			getvItem()	{ return _vItem; }
	vector<Item*>::iterator getviItem() { return _viItem; }


};

