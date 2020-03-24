#pragma once
#include "Item.h"

class Item_Money : public Item
{
public:
	Item_Money();
	~Item_Money();

	virtual HRESULT init(float x, float y);
	virtual void update();
	virtual void release();
	virtual void render();
};

