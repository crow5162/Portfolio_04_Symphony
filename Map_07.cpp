#include "stdafx.h"
#include "Map_07.h"

HRESULT Map_07::init()
{
	MapMaster::init();

	CAMERAMANAGER->set_CameraWorldSize(1024, 828);
	SCENEMANAGER->setSceneNumber(7);

	_playerStartPosX = 925;
	_playerStartPosY = 445;

	_alucard->AlucardPositionSet(&_playerStartPosX, &_playerStartPosY);


	_loopX = _loopY = 0;

	return S_OK;
}

void Map_07::update()
{
	MapMaster::update();

	_loopX += 3;

	CAMERAMANAGER->set_CameraXY(_alucard->GetAlucard().x, _alucard->GetAlucard().y, true, true);

	if (_openMiniMap)
	{
		_miniPlayer = RectMake(_alucard->GetAlucard().x / 24 + 850, _alucard->GetAlucard().y / 22 + 500,
			10, 10);
	}
}

void Map_07::release()
{
}

void Map_07::render()
{
	IMAGEMANAGER->findImage("Map_07_Cloud")->loopRender(CAMERAMANAGER->getWorldDC(), &RectMake(0, 0, 1024, 828), _loopX, _loopY);
	IMAGEMANAGER->findImage("TestMap_07")->render(CAMERAMANAGER->getWorldDC(), 0, 0);

	MapMaster::render();
}
