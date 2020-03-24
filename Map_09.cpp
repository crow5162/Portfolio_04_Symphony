#include "stdafx.h"
#include "Map_09.h"

HRESULT Map_09::init()
{
	MapMaster::init();

	CAMERAMANAGER->set_CameraWorldSize(1024, 831);
	SCENEMANAGER->setSceneNumber(10);

	_playerStartPosX = 895;
	_playerStartPosY = 470;

	_alucard->AlucardPositionSet(&_playerStartPosX, &_playerStartPosY);


	return S_OK;
}

void Map_09::update()
{
	MapMaster::update();

	CAMERAMANAGER->set_CameraXY(_alucard->GetAlucard().x, _alucard->GetAlucard().y, true, true);

	if (_openMiniMap)
	{
		_miniPlayer = RectMake(_alucard->GetAlucard().x / 19 + 700, _alucard->GetAlucard().y / 15 + 395,
			10, 10);
	}
}

void Map_09::release()
{
}

void Map_09::render()
{
	IMAGEMANAGER->findImage("TestMap_09")->render(CAMERAMANAGER->getWorldDC(), 0, 0);

	MapMaster::render();
}
