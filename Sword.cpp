#include "stdafx.h"
#include "Sword.h"


Sword::Sword()
{
	IMAGEMANAGER->addImage("Item_Sword", "Image/ItemImage/Item_Sword.bmp", 50, 50, true, RGB(255, 0, 255));
}


Sword::~Sword()
{
}

HRESULT Sword::init(float x, float y)
{
	_item.x = x;
	_item.y = y;

	_item.type = Weapon_01;

	_item.invenX = 100;
	_item.invenY = 100;

	_item.atk = 15;
	_item.gravity = false;

	_item.img = IMAGEMANAGER->findImage("Item_Sword");

	_item.rc = RectMakeCenter(_item.x, _item.y, _item.img->getWidth(), _item.img->getHeight());

	return S_OK;
}

void Sword::update()
{
	_item.rc = RectMakeCenter(_item.x, _item.y, _item.img->getWidth(), _item.img->getHeight());
}

void Sword::release()
{
}

void Sword::render()
{
	_item.img->render(CAMERAMANAGER->getWorldDC(), _item.rc.left, _item.rc.top);
}
