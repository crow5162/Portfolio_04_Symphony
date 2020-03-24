#pragma once
#include "Item.h"
class HealItem : public Item
{
private:


public:
	HealItem();
	~HealItem();

	virtual HRESULT init(float x, float y);
	virtual void update();
	virtual void release();
	virtual void render();
};

