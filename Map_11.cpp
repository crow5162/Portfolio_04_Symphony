#include "stdafx.h"
#include "Map_11.h"

HRESULT Map_11::init()
{
	MapMaster::init();

	CAMERAMANAGER->set_CameraWorldSize(2304, 1389);
	SCENEMANAGER->setSceneNumber(12);

	_playerStartPosX = 1910;
	_playerStartPosY = 1320;

	_alucard->AlucardPositionSet(&_playerStartPosX, &_playerStartPosY);

	for (int i = 0; i < 6; i++)
	{
		_candle[i] = IMAGEMANAGER->findImage("BlueCandle");
	}

	_frameCount = _currentFrameX = _currentFrameY = 0;

	_alchemiFire = IMAGEMANAGER->findImage("AlchemiFire");

	for (int i = 0; i < GROUNDNUMBER; i++)
	{
		_ground[0].x = 1560;
		_ground[0].y = 1393;

		_ground[1].x = 783;
		_ground[1].y = 1345;

		_ground[2].x = 1775;
		_ground[2].y = 1056;

		_ground[3].x = 1850;
		_ground[3].y = 816;

		_ground[4].x = 980;
		_ground[4].y = 577;

		_ground[0].rc = RectMakeCenter(_ground[0].x, _ground[0].y, 530, 50);
		_ground[1].rc = RectMakeCenter(_ground[1].x, _ground[1].y, 1025, 50);
		_ground[2].rc = RectMakeCenter(_ground[2].x, _ground[2].y, 470, 50);
		_ground[3].rc = RectMakeCenter(_ground[3].x, _ground[3].y, 330, 50);
		_ground[4].rc = RectMakeCenter(_ground[4].x, _ground[4].y, 1370, 50);
	}

	for (int i = 0; i < 6; i++)
	{
		_wall[0].x = 265;
		_wall[0].y = 1235;

		_wall[1].x = 1320;
		_wall[1].y = 1235;

		_wall[2].x = 1690;
		_wall[2].y = 470;

		_wall[3].x = 270;
		_wall[3].y = 485;

		_wall[4].x = 1515;
		_wall[4].y = 970;

		_wall[5].x = 2030;
		_wall[5].y = 970;

		_wall[i].rc = RectMakeCenter(_wall[i].x, _wall[i].y, 50, 180);
	}

	_monsterManager->Armored_Knight_Set(945, 1180, true);
	_monsterManager->Armored_Knight_Set(560, 395, true);
	_monsterManager->Armored_Knight_Set(1265, 430, true);
	_monsterManager->Skeleton_Knight_Set(1950, 935, true);

	return S_OK;
}

void Map_11::update()
{
	MapMaster::update();

	if(KEYMANAGER->isOnceKeyDown('Z'))
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
		_miniPlayer = RectMake(_alucard->GetAlucard().x / 17 + 525, _alucard->GetAlucard().y / 17 + 325,
			10, 10);
	}
}

void Map_11::release()
{
}

void Map_11::render()
{
	IMAGEMANAGER->findImage("TestMap_11")->render(CAMERAMANAGER->getWorldDC(), 0, 0);

	_candle[0]->frameRender(CAMERAMANAGER->getWorldDC(), 570, 1010, _currentFrameX, _currentFrameY);
	_candle[1]->frameRender(CAMERAMANAGER->getWorldDC(), 790, 1010, _currentFrameX, _currentFrameY);
	_candle[2]->frameRender(CAMERAMANAGER->getWorldDC(), 425, 265, _currentFrameX, _currentFrameY);
	_candle[3]->frameRender(CAMERAMANAGER->getWorldDC(), 640, 2265, _currentFrameX, _currentFrameY);
	_candle[4]->frameRender(CAMERAMANAGER->getWorldDC(), 1195, 270, _currentFrameX, _currentFrameY);
	_candle[5]->frameRender(CAMERAMANAGER->getWorldDC(), 1400, 270, _currentFrameX, _currentFrameY);
	
	for (int i = 0; i < GROUNDNUMBER; i++)
	{
		if (_ground[i].isDraw)
		{
			Rectangle(CAMERAMANAGER->getWorldDC(), _ground[i].rc);

			for (int j = 0; j < 6; j++)
			{
				Rectangle(CAMERAMANAGER->getWorldDC(), _wall[j].rc);
			}
		}
	}

	

	_alchemiFire->frameRender(CAMERAMANAGER->getWorldDC(), 508, 1100, _fireFrameX, _fireFrameY);

	MapMaster::render();
}

void Map_11::ObjectFrameCount()
{
	_frameCount++;
	if (_frameCount % 3 == 0)
	{
		_currentFrameX++;
		_frameCount = 0;
		if (_currentFrameX >= 2) _currentFrameX = 0;
	}

	_fireCount++;
	if (_fireCount % 3 == 0)
	{
		_fireFrameX++;
		_fireCount = 0;
		if (_fireFrameX >= 7) _fireFrameX = 0;
	}
}

void Map_11::Collision()
{
	for (int i = 0; i < _monsterManager->getMonsterVector().size(); i++)
	{
		if (_monsterManager->getMonsterVector().size() == 0) return;

		//메두사머리는 중력의 영향을 받지않는다.
		if (_monsterManager->getMonsterVector()[i]->getMonsterInfo().monsterType != MONSTER_MEDUSAHEAD)
		{
			RECT temp;

			for (int j = 0; j < GROUNDNUMBER; j++)
			{
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

			for (int j = 0; j < 6; j++)
			{
				if (IntersectRect(&temp, &_wall[j].rc, &_monsterManager->getMonsterVector()[i]->getMonsterRect()))
				{
					if (_monsterManager->getMonsterVector()[i]->getMonsterRect().left <= _wall[j].rc.right && 
						_monsterManager->getMonsterVector()[i]->getMonsterRect().left > _wall[j].rc.left)
					{
						_monsterManager->getMonsterVector()[i]->setMonsterX(_wall[j].rc.right + _monsterManager->getMonsterVector()[i]->getMonsterInfo().width / 2);
					}
					if (_monsterManager->getMonsterVector()[i]->getMonsterRect().right >= _wall[j].rc.left &&
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
