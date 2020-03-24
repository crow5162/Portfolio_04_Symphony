#include "stdafx.h"
#include "Map_15.h"

HRESULT Map_15::init()
{
	MapMaster::init();

	CAMERAMANAGER->set_CameraWorldSize(3799, 768);
	SCENEMANAGER->setSceneNumber(17);

	_playerStartPosX = 80;
	_playerStartPosY = 400;

	_alucard->AlucardPositionSet(&_playerStartPosX, &_playerStartPosY);

	return S_OK;
}

void Map_15::update()
{
	MapMaster::update();

	CAMERAMANAGER->set_CameraXY(_alucard->GetAlucard().x, _alucard->GetAlucard().y, true, true);

	if (_openMiniMap)
	{
		_miniPlayer = RectMake(_alucard->GetAlucard().x / 18 + 648, _alucard->GetAlucard().y / 22 + 136,
			10, 10);
	}
}

void Map_15::release()
{
}

void Map_15::render()
{
	IMAGEMANAGER->findImage("TestMap_15")->render(CAMERAMANAGER->getWorldDC(), 0, 0);

	MapMaster::render();
}
