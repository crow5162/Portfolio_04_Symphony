#include "stdafx.h"
#include "HealItem.h"


HealItem::HealItem()
{
	IMAGEMANAGER->addImage("Item_Heart", "Image/ItemImage/Item_Heart.bmp", 35, 29, true, RGB(255, 0, 255));
}


HealItem::~HealItem()
{

}

HRESULT HealItem::init(float x, float y)
{
	_item.x = x;
	_item.y = y;

	_item.type = Immediate_01;

	_item.Heal = 30;

	_item.img = IMAGEMANAGER->findImage("Item_Heart");
	_item.gravity = true;

	_item.rc = RectMakeCenter(_item.x, _item.y, _item.img->getWidth(),_item.img->getHeight());

	return S_OK;
}

void HealItem::update()
{
	Item::update();

	_item.rc = RectMakeCenter(_item.x, _item.y, _item.img->getWidth(), _item.img->getHeight());
}

void HealItem::release()
{
}

void HealItem::render()
{
	_item.img->render(CAMERAMANAGER->getWorldDC(), _item.rc.left, _item.rc.top);
}
