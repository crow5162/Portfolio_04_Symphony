#include "stdafx.h"
#include "ManaItem.h"


ManaItem::ManaItem()
{
	IMAGEMANAGER->addImage("Item_Mana", "Image/ItemImage/Item_Mana.bmp", 35, 46, true, RGB(255, 0, 255));
}


ManaItem::~ManaItem()
{
}

HRESULT ManaItem::init(float x, float y)
{
	_item.x = x;
	_item.y = y;

	_item.img = IMAGEMANAGER->findImage("Item_Mana");

	_item.type = Immediate_02;
	_item.Mana = 20;

	_item.gravity = true;

	_item.rc = RectMakeCenter(_item.x, _item.y, _item.img->getWidth(), _item.img->getHeight());
	
	return S_OK;
}

void ManaItem::release()
{
}

void ManaItem::update()
{
	Item::update();

	_item.rc = RectMakeCenter(_item.x, _item.y, _item.img->getWidth(), _item.img->getHeight());
}

void ManaItem::render()
{
	_item.img->render(CAMERAMANAGER->getWorldDC(), _item.rc.left, _item.rc.top);
}
