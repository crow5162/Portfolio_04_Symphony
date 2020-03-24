#include "stdafx.h"
#include "Map_05.h"

HRESULT Map_05::init()
{
	MapMaster::init();

	CAMERAMANAGER->set_CameraWorldSize(1024, 1852);
	SCENEMANAGER->setSceneNumber(5);

	_playerStartPosX = 45;
	_playerStartPosY = 1495;

	_alucard->AlucardPositionSet(&_playerStartPosX, &_playerStartPosY);
	
	_loopX = _loopY = 0;

	return S_OK;
}

void Map_05::update()
{
	MapMaster::update();

	_loopX += 2;

	CAMERAMANAGER->set_CameraXY(_alucard->GetAlucard().x, _alucard->GetAlucard().y, true, true);

	if (_openMiniMap)
	{
		_miniPlayer = RectMake(_alucard->GetAlucard().x / 22 + 850, _alucard->GetAlucard().y / 17 + 530,
			10, 10);
	}
}

void Map_05::release()
{
}

void Map_05::render()
{
	IMAGEMANAGER->findImage("Map_05_Cloud")->loopRender(CAMERAMANAGER->getWorldDC(), &RectMake(0, 0, 2656, 1852), _loopX, _loopY);
	IMAGEMANAGER->findImage("TestMap_05")->render(CAMERAMANAGER->getWorldDC(), 0, 0);

	MapMaster::render();
}
