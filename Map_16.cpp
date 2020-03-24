#include "stdafx.h"
#include "Map_16.h"

HRESULT Map_16::init()
{
	MapMaster::init();

	CAMERAMANAGER->set_CameraWorldSize(3180, 768);
	SCENEMANAGER->setSceneNumber(18);

	_playerStartPosX = 70;
	_playerStartPosY = 400;

	_alucard->AlucardPositionSet(&_playerStartPosX, &_playerStartPosY);

	_ground.x = 2667;
	_ground.y = 708;
	_ground.isDraw = false;

	//최종보스 세팅.
	_monsterManager->DeathSet(2900, 410, false);

	_ground.rc = RectMakeCenter(_ground.x, _ground.y, 1024, 50);

	return S_OK;
}

void Map_16::update()
{
	MapMaster::update();

	if (KEYMANAGER->isOnceKeyDown('Z'))
	{
		_ground.isDraw = _ground.isDraw ? false : true;
	}
	
	CAMERAMANAGER->set_CameraXY(_alucard->GetAlucard().x, _alucard->GetAlucard().y, true, true);

	if (_openMiniMap)
	{
		_miniPlayer = RectMake(_alucard->GetAlucard().x / 20 + 850, _alucard->GetAlucard().y / 22 + 136,
			10, 10);
	}
}

void Map_16::release()
{

}

void Map_16::render()
{
	IMAGEMANAGER->findImage("TestMap_16")->render(CAMERAMANAGER->getWorldDC(), 0, 0);

	if (_ground.isDraw)
	{
		Rectangle(CAMERAMANAGER->getWorldDC(), _ground.rc);
	}

	MapMaster::render();
}
