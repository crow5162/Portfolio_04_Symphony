#include "stdafx.h"
#include "Map_03.h"



HRESULT Map_03::init()
{
	MapMaster::init();

	CAMERAMANAGER->set_CameraWorldSize(2304, 1389);
	SCENEMANAGER->setSceneNumber(3);

	_playerStartPosX = 105;
	_playerStartPosY = 330;

	_alucard->AlucardPositionSet(&_playerStartPosX, &_playerStartPosY);

	for (int i = 0; i < 4; i++)
	{
		_candle[i] = IMAGEMANAGER->findImage("BlueCandle");
	}
	
	_currentFrameX = _currentFrameY = _frameCount = 0;

	_ground.x = 1300;
	_ground.y = 1365;
	_ground.rc = RectMakeCenter(_ground.x, _ground.y, GROUNDWIDTH, GROUNDHEIGHT);
	_ground.isDraw = false;

	return S_OK;
}

void Map_03::update()
{
	MapMaster::update();

	if (KEYMANAGER->isOnceKeyDown('Z'))
	{
		_ground.isDraw = _ground.isDraw ? false : true;
	}

	ObjectFrameCount();
	Collision();

	CAMERAMANAGER->set_CameraXY(_alucard->GetAlucard().x, _alucard->GetAlucard().y, true, true);

	if (_openMiniMap)
	{
		_miniPlayer = RectMake(_alucard->GetAlucard().x / 17 + 430, _alucard->GetAlucard().y / 17 + 595,
			10, 10);
	}
}

void Map_03::release()
{
}

void Map_03::render()
{

	IMAGEMANAGER->findImage("TestMap_03")->render(CAMERAMANAGER->getWorldDC(), 0, 0);

	for (int i = 0; i < 4; i++)
	{
		if (i < 2)
			_candle[i]->frameRender(CAMERAMANAGER->getWorldDC(), 520 + i * 1247, 308, _currentFrameX, _currentFrameY);

			_candle[2]->frameRender(CAMERAMANAGER->getWorldDC(), 310, 885, _currentFrameX, _currentFrameY);
			_candle[3]->frameRender(CAMERAMANAGER->getWorldDC(), 1980, 890, _currentFrameX, _currentFrameY);
	}

	if (_ground.isDraw)
	{
		IMAGEMANAGER->findImage("Map_03_Pixel")->render(CAMERAMANAGER->getWorldDC(), 0, 0);
		Rectangle(CAMERAMANAGER->getWorldDC(), _ground.rc);
	}

	MapMaster::render();
}

void Map_03::ObjectFrameCount()
{
	_frameCount++;
	if (_frameCount % 5 == 0)
	{
		_currentFrameX++;
		_frameCount = 0;
		if (_currentFrameX > 1) _currentFrameX = 0;
	}
}

void Map_03::Collision()
{
	for (int i = 0; i < _monsterManager->getMonsterVector().size(); i++)
	{
		if (_monsterManager->getMonsterVector().size() == 0) return;

		//메두사머리는 중력의 영향을 받지않는다.
		if (_monsterManager->getMonsterVector()[i]->getMonsterInfo().monsterType != MONSTER_MEDUSAHEAD)
		{
			RECT temp;

			//Rect의 Top과 Monster의 Bottom 충돌 조건. 
			if (IntersectRect(&temp, &_ground.rc, &_monsterManager->getMonsterVector()[i]->getMonsterRect()))
			{
				if (_monsterManager->getMonsterVector()[i]->getMonsterRect().bottom >= _ground.rc.top)
				{
					_monsterManager->getMonsterVector()[i]->setMonsterY(_ground.rc.top - _monsterManager->getMonsterVector()[i]->getMonsterInfo().height / 2);
					_monsterManager->getMonsterVector()[i]->setMonsterGravity(false);
				}
			}
			//Rect의 Top보다 위에있을시 중력 받음 조건.
			else if (_monsterManager->getMonsterVector()[i]->getMonsterRect().bottom < _ground.rc.top)
			{
				_monsterManager->getMonsterVector()[i]->setMonsterGravity(true);
			}
		}
	}
}
