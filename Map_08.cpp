#include "stdafx.h"
#include "Map_08.h"

HRESULT Map_08::init()
{
	MapMaster::init();

	CAMERAMANAGER->set_CameraWorldSize(1536, 2142);
	SCENEMANAGER->setSceneNumber(8);

	_playerStartPosX = 1450;
	_playerStartPosY = 1850;

	_alucard->AlucardPositionSet(&_playerStartPosX, &_playerStartPosY);


	for (int i = 0; i < 5; i++)
	{
		_candle[i] = IMAGEMANAGER->findImage("BlueCandle");
	}

	_frameCount = _currentFrameX = _currentFrameY = 0;

	for (int i = 0; i < GROUNDNUMBER; i++)
	{
		_ground[0].x = 760;
		_ground[0].y = 1726;
		_ground[1].x = 555;
		_ground[1].y = 1197;
		_ground[2].x = 850;
		_ground[2].y = 430;

		_ground[i].rc = RectMakeCenter(_ground[i].x, _ground[i].y, GROUNDWIDTH, GROUNDHEIGHT);
		_ground[0].rc = RectMakeCenter(_ground[0].x, _ground[0].y, 550, GROUNDHEIGHT);
	}

	for (int i = 0; i < 4; i++)
	{
		_wall[0].x = 460;
		_wall[0].y = 1625;

		_wall[1].x = 1060;
		_wall[1].y = 1625;

		_wall[2].x = 610;
		_wall[2].y = 330;
			
		_wall[3].x = 1090;
		_wall[3].y = 330;

		_wall[i].rc = RectMakeCenter(_wall[i].x, _wall[i].y, 50, 180);
	}

	_monsterManager->Skeleton_Knight_Set(960, 1590, true);
	_monsterManager->Skeleton_Set(690, 1070, true);
	_monsterManager->Skeleton_Knight_Set(1030, 300, true);

	return S_OK;
}

void Map_08::update()
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
	Collision();

	CAMERAMANAGER->set_CameraXY(_alucard->GetAlucard().x, _alucard->GetAlucard().y, true, true);

	if (_openMiniMap)
	{
		_miniPlayer = RectMake(_alucard->GetAlucard().x / 15 + 750, _alucard->GetAlucard().y / 15 + 403,
			10, 10);
	}
}

void Map_08::release()
{
}

void Map_08::render()
{
	IMAGEMANAGER->findImage("TestMap_08")->render(CAMERAMANAGER->getWorldDC(), 0, 0);

	_candle[0]->frameRender(CAMERAMANAGER->getWorldDC(), 1265, 1430, _currentFrameX, _currentFrameY);
	_candle[1]->frameRender(CAMERAMANAGER->getWorldDC(), 1025, 1435, _currentFrameX, _currentFrameY);
	_candle[2]->frameRender(CAMERAMANAGER->getWorldDC(), 220, 1560, _currentFrameX, _currentFrameY);
	_candle[3]->frameRender(CAMERAMANAGER->getWorldDC(), 500, 225, _currentFrameX, _currentFrameY);
	_candle[4]->frameRender(CAMERAMANAGER->getWorldDC(), 1020, 220, _currentFrameX, _currentFrameY);

	for (int i = 0; i < GROUNDNUMBER; i++)
	{
		if (_ground[i].isDraw)
		{
			Rectangle(CAMERAMANAGER->getWorldDC(), _ground[i].rc);

			for (int j = 0; j < 4; j++)
			{
				Rectangle(CAMERAMANAGER->getWorldDC(), _wall[j].rc);
			}
		}
	}

	MapMaster::render();
}

void Map_08::ObjectFrameCount()
{
	_frameCount++;
	if (_frameCount % 5 == 0)
	{
		_currentFrameX++;
		_frameCount = 0;
		if (_currentFrameX > 1) _currentFrameX = 0;
	}
}

void Map_08::Collision()
{
	for (int i = 0; i < _monsterManager->getMonsterVector().size(); i++)
	{
		if (_monsterManager->getMonsterVector().size() == 0) return;

		//메두사머리는 중력의 영향을 받지않는다.
		if (_monsterManager->getMonsterVector()[i]->getMonsterInfo().monsterType != MONSTER_MEDUSAHEAD)
		{
			for (int j = 0; j < GROUNDNUMBER; j++)
			{
				RECT temp;
				//Rect의 Top과 Monster의 Bottom 충돌 조건. 
				if (IntersectRect(&temp, &_ground[j].rc, &_monsterManager->getMonsterVector()[i]->getMonsterRect()))
				{
					if (_monsterManager->getMonsterVector()[i]->getMonsterRect().bottom >= _ground[j].rc.top)
					{
						_monsterManager->getMonsterVector()[i]->setMonsterY(_ground[j].rc.top - _monsterManager->getMonsterVector()[i]->getMonsterInfo().height / 2);
						_monsterManager->getMonsterVector()[i]->setMonsterGravity(false);
					}
				}

			}
			for (int j = 0; j < 4; j++)
			{
				RECT _temp;

				if (IntersectRect(&_temp, &_wall[j].rc, &_monsterManager->getMonsterVector()[i]->getMonsterRect()))
				{
					if (_monsterManager->getMonsterVector()[i]->getMonsterRect().left <= _wall[j].rc.right &&
						_monsterManager->getMonsterVector()[i]->getMonsterRect().left > _wall[j].rc.left)
					{
						_monsterManager->getMonsterVector()[i]->setMonsterX(_wall[j].rc.right + _monsterManager->getMonsterVector()[i]->getMonsterInfo().width / 2);
					}
					else if (_monsterManager->getMonsterVector()[i]->getMonsterRect().right >= _wall[j].rc.left &&
						_monsterManager->getMonsterVector()[i]->getMonsterRect().right < _wall[j].rc.right)
					{
						_monsterManager->getMonsterVector()[i]->setMonsterX(_wall[j].rc.left - _monsterManager->getMonsterVector()[i]->getMonsterInfo().width / 2);
					}
				}
			}
		}
	}

	for (int i = 0; i < _item->getvItem().size(); i++)
	{
		if (_item->getvItem().size() == 0) return;

		RECT temp;

		for (int j = 0; j < GROUNDNUMBER; j++)
		{

			if (IntersectRect(&temp, &_ground[j].rc, &_item->getvItem()[i]->getItemRect()))
			{
				if (_item->getvItem()[i]->getItemRect().bottom >= _ground[j].rc.top)
				{
					_item->getvItem()[i]->setItemY(_ground[j].rc.top - _item->getvItem()[i]->getItemInfo().img->getHeight() / 2);
					_item->getvItem()[i]->setItemGravity(false);
				}
			}
		}
	}
}
