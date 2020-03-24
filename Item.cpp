#include "stdafx.h"
#include "Item.h"


Item::Item()
{
}


Item::~Item()
{
}

HRESULT Item::init()
{

	



	return S_OK;
}

void Item::update()
{
	if (_item.gravity)
	{
		_item.y += 3.0f;
	}
}

void Item::release()
{
}

void Item::render()
{
}
