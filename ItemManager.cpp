#include "stdafx.h"
#include "ItemManager.h"


ItemManager::ItemManager()
{
}


ItemManager::~ItemManager()
{
}

HRESULT ItemManager::init()
{

	return S_OK;
}

void ItemManager::release()
{
}

void ItemManager::update()
{
	for (int i = 0; i < _vItem.size(); i++)
	{
		if (_vItem.size() == 0) return;

		_vItem[i]->update();

	}
}

void ItemManager::render()
{
	for (int i = 0; i < _vItem.size(); i++)
	{
		if (_vItem.size() == 0) return;

		_vItem[i]->render();
	}
}

void ItemManager::EraseItem(int arrNum)
{
	_vItem.erase(_vItem.begin() + arrNum);
}

void ItemManager::HealItemSet(float x, float y)
{
	HealItem* healItem;
	healItem = new HealItem;
	healItem->init(x, y);

	_vItem.push_back(healItem);
}

void ItemManager::MoneyItemSet(float x, float y)
{
	Item_Money* money;
	money = new Item_Money;
	money->init(x, y);

	_vItem.push_back(money);
}

void ItemManager::WeaponItemSet(float x, float y)
{
	Sword* sword;
	sword = new Sword;
	sword->init(x, y);

	_vItem.push_back(sword);
}

void ItemManager::WeaponItem2Set(float x, float y)
{
	Sword_02* sword2;
	sword2 = new Sword_02;
	sword2->init(x, y);

	_vItem.push_back(sword2);
}

void ItemManager::ManaItemSet(float x, float y)
{
	ManaItem* mana;
	mana = new ManaItem;
	mana->init(x, y);

	_vItem.push_back(mana);
}
