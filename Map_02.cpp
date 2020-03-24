#include "stdafx.h"
#include "Map_02.h"

HRESULT Map_02::init()
{
	MapMaster::init();

	CAMERAMANAGER->set_CameraWorldSize(6649, 768);
	SCENEMANAGER->setSceneNumber(2);

	_playerStartPosX = 100;
	_playerStartPosY = 385;

	//MonsterSetting
	for (int i = 0; i < 5; i++)
	{
		_monsterManager->Skeleton_Set(835 + i * 900, 620, true);
	}

	_monsterManager->Skeleton_Knight_Set(5700, 620, true);

	_alucard->AlucardPositionSet(&_playerStartPosX, &_playerStartPosY);

	_loopX = _loopY = 0;

	_frameCount = _currentFrameX = _currentFrameY = 0;

	for (int i = 0; i < 6; i++)
	{
		_candle[i] = IMAGEMANAGER->findImage("BlueCandle");
	}

	_ground.x = 3320;
	_ground.y = 708;
	_ground.rc = RectMakeCenter(_ground.x, _ground.y, GROUNDWIDTH, GROUNDHEIGHT);
	_ground.isDraw = false;

	_preStage.x = 5;
	_preStage.y = 390;
	_preStage.width = 50;
	_preStage.height = 200;
	_preStage.rc = RectMakeCenter(_preStage.x, _preStage.y, _preStage.width, _preStage.height);

	return S_OK;
}

void Map_02::update()
{
	MapMaster::update();

	if (KEYMANAGER->isOnceKeyDown('Z'))
	{
		_ground.isDraw = _ground.isDraw ? false : true;
	}
	 
	ObjectFrameCount();
	CollisionTest();

	CAMERAMANAGER->set_CameraXY(_alucard->GetAlucard().x, _alucard->GetAlucard().y, true, true);

	if (_openMiniMap)
	{
		_miniPlayer = RectMake(_alucard->GetAlucard().x / 21 + 100, _alucard->GetAlucard().y / 22 + 595,
			10, 10);
	}
}

void Map_02::release()
{

}

void Map_02::render()
{
	//PatBlt(CAMERAMANAGER->getWorldDC(), 0, 0, IMAGEMANAGER->findImage("TestMap_02")->getWidth(), WINSIZEY, BLACKNESS);
	IMAGEMANAGER->findImage("Map_02_BackGround")->render(CAMERAMANAGER->getWorldDC(), 0, 0);
	IMAGEMANAGER->findImage("TestMap_02")->render(CAMERAMANAGER->getWorldDC(), 0, 0);

	for (int i = 0; i < 6; i++)
	{
		if(i < 3)
		_candle[i]->frameRender(CAMERAMANAGER->getWorldDC(), 1000 + i * 830, 395, _currentFrameX, _currentFrameY);
		if (i >= 3)
		_candle[i]->frameRender(CAMERAMANAGER->getWorldDC(), 1479 + i * 830, 395, _currentFrameX, _currentFrameY);
	}

	if (_ground.isDraw)
	{
		Rectangle(CAMERAMANAGER->getWorldDC(), _ground.rc);
	}

	MapMaster::render();
}

void Map_02::ObjectFrameCount()
{
	_frameCount++;

	if (_frameCount % 5 == 0)
	{
		_currentFrameX++;
		_frameCount = 0;
		if (_currentFrameX > 1) _currentFrameX = 0;
	}

}

void Map_02::CollisionTest()
{
	//Monster 와 Ground 충돌 처리.
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
