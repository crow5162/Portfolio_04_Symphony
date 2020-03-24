#include "stdafx.h"
#include "Sword_02.h"


Sword_02::Sword_02()
{
	IMAGEMANAGER->addImage("Item_Sword_02", "Image/itemImage/Item_Sword_02.bmp", 50, 50, true, RGB(255, 0, 255));
}


Sword_02::~Sword_02()
{
}

HRESULT Sword_02::init(float x, float y)
{
	_item.x = x;
	_item.y = y;

	_item.img = IMAGEMANAGER->findImage("Item_Sword_02");

	_item.atk = 35;

	_item.invenX = 100;
	_item.invenY = 100;

	_item.type = Weapon_02;
	_item.gravity = false;

	_item.rc = RectMakeCenter(_item.x, _item.y, _item.img->getWidth(), _item.img->getHeight());

	return S_OK;
}

void Sword_02::update()
{
	_item.rc = RectMakeCenter(_item.x, _item.y, _item.img->getWidth(), _item.img->getHeight());
}

void Sword_02::release()
{
}

void Sword_02::render()
{
	_item.img->render(CAMERAMANAGER->getWorldDC(), _item.rc.left, _item.rc.top);
}
