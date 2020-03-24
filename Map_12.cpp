#include "stdafx.h"
#include "Map_12.h"

HRESULT Map_12::init()
{
	MapMaster::init();

	CAMERAMANAGER->set_CameraWorldSize(1024, 2876);
	SCENEMANAGER->setSceneNumber(13);

	_playerStartPosX = 965;
	_playerStartPosY = 2500;

	_alucard->AlucardPositionSet(&_playerStartPosX, &_playerStartPosY);

	for (int i = 0; i < 4; i++)
	{
		_torchLight[i] = IMAGEMANAGER->findImage("TorchLight");
	}

	for (int i = 0; i < GROUNDNUMBER; i++)
	{
		_ground[i].x = 513;
		_ground[i].y = 2361;

		_ground[4].x = 189;
		_ground[4].y = 1593;

		_ground[5].x = 125;
		_ground[5].y = 569;

		_ground[6].x = 835;
		_ground[6].y = 2105;

		_ground[7].x = 836;
		_ground[7].y = 1081;

		_ground[8].x = 895;
		_ground[8].y = 2617;

		_ground[9].x = 515;
		_ground[9].y = 2873;

		_ground[i].rc = RectMakeCenter(_ground[i].x, _ground[i].y - i * 512, 125, 50);
		_ground[4].rc = RectMakeCenter(_ground[4].x, _ground[4].y, 125, 50);
		_ground[5].rc = RectMakeCenter(_ground[5].x, _ground[5].y, 250, 50);
		_ground[6].rc = RectMakeCenter(_ground[6].x, _ground[6].y, 125, 50);
		_ground[7].rc = RectMakeCenter(_ground[7].x, _ground[7].y, 125, 50);
		_ground[8].rc = RectMakeCenter(_ground[8].x, _ground[8].y, 250, 50);
		_ground[9].rc = RectMakeCenter(_ground[9].x, _ground[9].y, 250, 50);
	}

	for (int i = 0; i < 4; i++)
	{
		if (i == 0) _monsterManager->Medusa_Head_Set(930, 1865, false, 0, 1);
		if (i == 1) _monsterManager->Medusa_Head_Set(930, 1330, false, 0 ,1);
		if (i == 2) _monsterManager->Medusa_Head_Set(930, 825, false, 0, 1);
		if (i == 3) _monsterManager->Medusa_Head_Set(930, 265, false, 0, 1);
	}

	_spawnCount = 0;

	_frameCount = _currentFrameX = _currentFrameY = 0;

	return S_OK;
}

void Map_12::update()
{
	MapMaster::update();


	if (KEYMANAGER->isOnceKeyDown('Z'))
	{
		for (int i = 0; i < GROUNDNUMBER; i++)
		{
			_ground[i].isDraw = _ground[i].isDraw ? false : true;
		}
	}

	ObjectFrameCount();
	MedusaSpawn();

	CAMERAMANAGER->set_CameraXY(_alucard->GetAlucard().x, _alucard->GetAlucard().y, true, true);

	if (_openMiniMap)
	{
		_miniPlayer = RectMake(_alucard->GetAlucard().x / 18 + 469, _alucard->GetAlucard().y / 22 + 227,
			10, 10);
	}
}

void Map_12::release()
{
}

void Map_12::render()
{
	IMAGEMANAGER->findImage("TestMap_12")->render(CAMERAMANAGER->getWorldDC(), 0, 0);

	_torchLight[0]->frameRender(CAMERAMANAGER->getWorldDC(), 485, 2072, _currentFrameX, _currentFrameY); 
	_torchLight[1]->frameRender(CAMERAMANAGER->getWorldDC(), 485, 1560, _currentFrameX, _currentFrameY); 
	_torchLight[2]->frameRender(CAMERAMANAGER->getWorldDC(), 485, 1048, _currentFrameX, _currentFrameY); 
	_torchLight[3]->frameRender(CAMERAMANAGER->getWorldDC(), 485, 536, _currentFrameX, _currentFrameY); 

	for (int i = 0; i < GROUNDNUMBER; i++)
	{
		if (_ground[i].isDraw)
		{
			Rectangle(CAMERAMANAGER->getWorldDC(), _ground[i].rc);
		}
	}

	MapMaster::render();
}

void Map_12::MedusaSpawn()
{
	_spawnCount++;

	if (_spawnCount % 150 == 0)
	{
		for (int i = 0; i < 4; i++)
		{
			if (i == 0) _monsterManager->Medusa_Head_Set(930, 1865, false, 0, 1);
			if (i == 1) _monsterManager->Medusa_Head_Set(930, 1330, false, 0, 1);
			if (i == 2) _monsterManager->Medusa_Head_Set(930, 825, false, 0, 1);
			if (i == 3) _monsterManager->Medusa_Head_Set(930, 265, false, 0, 1);
		}
	}
	if (_spawnCount % 100 == 0)
	{
		for (int i = 0; i < 4; i++)
		{
			if (i == 0) _monsterManager->Medusa_Head_Set(45, 2430, false, 1, 0);
			if (i == 1) _monsterManager->Medusa_Head_Set(45, 1700, false, 1, 0);
			if (i == 2) _monsterManager->Medusa_Head_Set(45, 1290, false, 1, 0);
			if (i == 3) _monsterManager->Medusa_Head_Set(45, 790, false, 1, 0);
		}
	}

	if (_spawnCount > 170) _spawnCount = 0;
}

void Map_12::ObjectFrameCount()
{
	_frameCount++;
	if (_frameCount % 3 == 0)
	{
		_currentFrameX++;
		_frameCount = 0;
		if (_currentFrameX >= 4) _currentFrameX = 0;
	}
}
