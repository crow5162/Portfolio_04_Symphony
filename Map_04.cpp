#include "stdafx.h"
#include "Map_04.h"

HRESULT Map_04::init()
{
	MapMaster::init();

	CAMERAMANAGER->set_CameraWorldSize(5699, 768);
	SCENEMANAGER->setSceneNumber(4);

	_playerStartPosX = 60;
	_playerStartPosY = 375;

	_alucard->AlucardPositionSet(&_playerStartPosX, &_playerStartPosY);

	for (int i = 0; i < 2; i++)
	{
		if (i == 0) _monsterManager->Skeleton_Set(945, 680, true);
		if (i == 1) _monsterManager->Skeleton_Set(4930, 680, true);
	}

	for (int i = 0; i < 3; i++)
	{
		if (i == 0) _monsterManager->Skeleton_Knight_Set(1685, 680, true);
		if (i == 1) _monsterManager->Skeleton_Knight_Set(2635, 680, true);
		if (i == 2) _monsterManager->Skeleton_Knight_Set(3815, 680, true);
	}

	for (int i = 0; i < 8; i++)
	{
		_candle[i] = IMAGEMANAGER->findImage("BlueCandle");
	}

	_currentFrameX = _currentFrameY = _frameCount = 0;

	_ground.x = 2850;
	_ground.y = 755;
	_ground.rc = RectMakeCenter(_ground.x, _ground.y, GROUNDWIDTH, GROUNDHEIGHT);
	_ground.isDraw = false;

	return S_OK;
}

void Map_04::update()
{
	MapMaster::update();

	ObjectFrameCount();
	Collision();

	if (KEYMANAGER->isOnceKeyDown('Z'))
	{
		_ground.isDraw = _ground.isDraw ? false : true;
	}

	CAMERAMANAGER->set_CameraXY(_alucard->GetAlucard().x, _alucard->GetAlucard().y, true, true);

	if (_openMiniMap)
	{
		_miniPlayer = RectMake(_alucard->GetAlucard().x / 20 + 570, _alucard->GetAlucard().y / 17 + 590,
			10, 10);
	}
}

void Map_04::release()
{
}

void Map_04::render()
{
	IMAGEMANAGER->findImage("Map_04_Cloud")->render(CAMERAMANAGER->getWorldDC(), 0, 0);
	IMAGEMANAGER->findImage("Map_04_BackGround")->loopRender(CAMERAMANAGER->getWorldDC(), &RectMake(0, 0, 5698, 768), _alucard->GetAlucard().x / 7, 0);
	IMAGEMANAGER->findImage("TestMap_04")->render(CAMERAMANAGER->getWorldDC(), 0, 0);

	_candle[0]->frameRender(CAMERAMANAGER->getWorldDC(), 587, 400, _currentFrameX, _currentFrameY);
	_candle[1]->frameRender(CAMERAMANAGER->getWorldDC(), 1062, 400, _currentFrameX, _currentFrameY);
	_candle[2]->frameRender(CAMERAMANAGER->getWorldDC(), 2010, 395, _currentFrameX, _currentFrameY);
	_candle[3]->frameRender(CAMERAMANAGER->getWorldDC(), 2488, 460, _currentFrameX, _currentFrameY);
	_candle[4]->frameRender(CAMERAMANAGER->getWorldDC(), 3200, 460, _currentFrameX, _currentFrameY);
	_candle[5]->frameRender(CAMERAMANAGER->getWorldDC(), 3673, 395, _currentFrameX, _currentFrameY);
	_candle[6]->frameRender(CAMERAMANAGER->getWorldDC(), 4622, 400, _currentFrameX, _currentFrameY);
	_candle[7]->frameRender(CAMERAMANAGER->getWorldDC(), 5095, 400, _currentFrameX, _currentFrameY);

	if (_ground.isDraw)
	{
		Rectangle(CAMERAMANAGER->getWorldDC(), _ground.rc);
	}

	MapMaster::render();
}

void Map_04::ObjectFrameCount()
{
	_frameCount++;
	if (_frameCount % 5 == 0)
	{
		_currentFrameX++;
		_frameCount = 0;
		if (_currentFrameX > 1) _currentFrameX = 0;
	}
}

void Map_04::Collision()
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

	for (int i = 0; i < _item->getvItem().size(); i++)
	{
		if (_item->getvItem().size() == 0) return;

		RECT temp;

		if (IntersectRect(&temp, &_ground.rc, &_item->getvItem()[i]->getItemRect()))
		{
			if (_item->getvItem()[i]->getItemRect().bottom >= _ground.rc.top)
			{
				_item->getvItem()[i]->setItemY(_ground.rc.top - _item->getvItem()[i]->getItemInfo().img->getHeight() / 2);
				_item->getvItem()[i]->setItemGravity(false);
			}
		}
	}
}
