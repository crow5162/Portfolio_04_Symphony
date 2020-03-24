#pragma once
#include "Item.h"
class Sword_02 : public Item
{
public:
	Sword_02();
	~Sword_02();

	virtual HRESULT init(float x, float y);
	virtual void update();
	virtual void release();
	virtual void render();
};

