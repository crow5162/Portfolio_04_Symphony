#include "stdafx.h"
#include "Map_13_1.h"


HRESULT Map_13_1::init()
{
	MapMaster::init();

	CAMERAMANAGER->set_CameraWorldSize(1024, 828);
	SCENEMANAGER->setSceneNumber(15);

	_playerStartPosX = 940;
	_playerStartPosY = 460;

	_alucard->AlucardPositionSet(&_playerStartPosX, &_playerStartPosY);

	_ground.x = 510;
	_ground.y = 695;
	_ground.rc = RectMakeCenter(_ground.x, _ground.y, 1024, 50);
	_ground.isDraw = false;

	return S_OK;
}

void Map_13_1::update()
{
	MapMaster::update();

	if(KEYMANAGER->isOnceKeyDown('Z'))
	{ 
		_ground.isDraw = _ground.isDraw ? false : true;
	}

	CAMERAMANAGER->set_CameraXY(_alucard->GetAlucard().x, _alucard->GetAlucard().y, true, true);
}

void Map_13_1::release()
{
}

void Map_13_1::render()
{
	IMAGEMANAGER->findImage("TestMap_13_1")->render(CAMERAMANAGER->getWorldDC(), 0, 0);
	IMAGEMANAGER->findImage("Map_13_Object")->render(CAMERAMANAGER->getWorldDC(), 852, 330);

	if (_ground.isDraw)
	{
		Rectangle(CAMERAMANAGER->getWorldDC(), _ground.rc);
	}

	MapMaster::render();
}
