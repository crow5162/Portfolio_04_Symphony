#include "stdafx.h"
#include "Map_08_1.h"

HRESULT Map_08_1::init()
{
	MapMaster::init();

	CAMERAMANAGER->set_CameraWorldSize(1024, 828);
	SCENEMANAGER->setSceneNumber(9);

	_playerStartPosX = 60;
	_playerStartPosY = 445;

	_alucard->AlucardPositionSet(&_playerStartPosX, &_playerStartPosY);


	for (int i = 0;i < 2; i++)
	{
		_ground[0].x = 607;
		_ground[0].y = 760;
		_ground[1].x = 95;
		_ground[1].y = 569;

		_ground[0].rc = RectMakeCenter(_ground[0].x, _ground[0].y, 450, 50);
		_ground[1].rc = RectMakeCenter(_ground[1].x, _ground[1].y, 200, 50);
	}

	_item->WeaponItem2Set(630, 570);

	return S_OK;
}

void Map_08_1::update()
{
	MapMaster::update();

	if (KEYMANAGER->isOnceKeyDown('Z'))
	{
		for (int i = 0; i < 2; i++)
		{
			_ground[i].isDraw = _ground[i].isDraw ? false : true;
		}
	}

	CAMERAMANAGER->set_CameraXY(_alucard->GetAlucard().x, _alucard->GetAlucard().y, true, true);
}

void Map_08_1::releasse()
{
}

void Map_08_1::render()
{
	IMAGEMANAGER->findImage("TestMap_08_1")->render(CAMERAMANAGER->getWorldDC(), 0, 0);

	for (int i = 0; i < 2; i++)
	{
		if (_ground[i].isDraw)
		{
			Rectangle(CAMERAMANAGER->getWorldDC(), _ground[i].rc);
		}
	}

	MapMaster::render();
}
