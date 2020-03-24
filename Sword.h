#pragma once
#include "Item.h"
class Sword : public Item
{
private:


public:
	Sword();
	~Sword();

	virtual HRESULT init(float x, float y);
	virtual void update();
	virtual void release();
	virtual void render();
};

