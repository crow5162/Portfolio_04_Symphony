#pragma once
#include "Item.h"

class ManaItem : public Item
{
public:
	ManaItem();
	~ManaItem();

	virtual HRESULT init(float x, float y);
	virtual void release();
	virtual void update();
	virtual void render();
};

