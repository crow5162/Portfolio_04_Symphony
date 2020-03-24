#include "stdafx.h"
#include "Item_Money.h"


Item_Money::Item_Money()
{
	IMAGEMANAGER->addImage("Item_Money", "Image/ItemImage/Item_Money.bmp", 35, 31, true, RGB(255, 0, 255));
}


Item_Money::~Item_Money()
{
}

HRESULT Item_Money::init(float x, float y)
{
	_item.x = x;
	_item.y = y;

	_item.img = IMAGEMANAGER->findImage("Item_Money");

	_item.itemName = "GOLD";
	_item.type = Gold;

	_item.gold = 150;
	_item.gravity = true;

	_item.rc = RectMakeCenter(_item.x, _item.y, _item.img->getWidth(), _item.img->getHeight());

	return S_OK;
}

void Item_Money::update()
{
	Item::update();

	_item.rc = RectMakeCenter(_item.x, _item.y, _item.img->getWidth(), _item.img->getHeight());
}

void Item_Money::release()
{
}

void Item_Money::render()
{
	_item.img->render(CAMERAMANAGER->getWorldDC(), _item.rc.left, _item.rc.top);
}
