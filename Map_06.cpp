#include "stdafx.h"
#include "Map_06.h"


HRESULT Map_06::init()
{
	MapMaster::init();

	CAMERAMANAGER->set_CameraWorldSize(1024, 2856);
	SCENEMANAGER->setSceneNumber(6);

	_playerStartPosX = 50;
	_playerStartPosY = 2490;

	_alucard->AlucardPositionSet(&_playerStartPosX, &_playerStartPosY);

	for (int i = 0; i < GROUNDNUMBER; i++)
	{
		_ground[i].x = 737;
		_ground[i].y = 2112 - (i * 385);
		//건너편 발판.
		_ground[4].x = 310;
		_ground[4].y = 2110;
		_ground[5].x = 285;
		_ground[5].y = 1344;
		_ground[6].x = 285;
		_ground[6].y = 576;
	
		_ground[i].rc = RectMakeCenter(_ground[i].x, _ground[i].y, GROUNDWIDTH, GROUNDHEIGHT);
		//건너편 발판중 하나가 넓다.
		_ground[4].rc = RectMakeCenter(_ground[4].x, _ground[4].y, 240, 65);
		_ground[i].isDraw = false;
	}

	_wall.x = 172;
	_wall.y = 1980;
	_wall.rc = RectMakeCenter(_wall.x, _wall.y, 40, 200);

	_scaffold.x = 445;
	_scaffold.y = 1970;
	_scaffold.rc = RectMakeCenter(_scaffold.x, _scaffold.y, 130, 30);

	_monsterManager->Skeleton_Knight_Set(335, 430, true);
	_characterInScaffold = false;


	_spawnCount = 0;

	return S_OK;
}

void Map_06::update()
{
	MapMaster::update();

	MedusaSpawn();
	Collision();

	if(KEYMANAGER->isOnceKeyDown('Z'))
	{
		for (int i = 0; i < GROUNDNUMBER; i++)
		{
			_ground[i].isDraw = _ground[i].isDraw ? false : true;
		}
	}

	CAMERAMANAGER->set_CameraXY(_alucard->GetAlucard().x, _alucard->GetAlucard().y, true, true);

	if (_openMiniMap)
	{
		_miniPlayer = RectMake(_alucard->GetAlucard().x / 24 + 900, _alucard->GetAlucard().y / 22 + 502,
			10, 10);
	}
}

void Map_06::release()
{
}

void Map_06::render()
{
	IMAGEMANAGER->findImage("TestMap_06")->render(CAMERAMANAGER->getWorldDC(), 0, 0);

	for (int i = 0; i < GROUNDNUMBER; i++)
	{
		if (_ground[i].isDraw)
		{
			Rectangle(CAMERAMANAGER->getWorldDC(), _ground[i].rc);
			Rectangle(CAMERAMANAGER->getWorldDC(), _scaffold.rc);
		}
	}

	MapMaster::render();
}

void Map_06::MedusaSpawn()
{
	_spawnCount++;

	for (int i = 0; i < 5; i++)
    {
		if (_spawnCount % 200 == 0)
		{
			if (i == 0)_monsterManager->Medusa_Head_Set(950, 1935, false, 0, 1);
			if (i == 1)_monsterManager->Medusa_Head_Set(950, 1150, false, 0, 1);
			if (i == 2)_monsterManager->Medusa_Head_Set(950, 350, false, 0, 1);
		}
		if (_spawnCount % 300 == 0)
		{
			if (i == 3)_monsterManager->Medusa_Head_Set(950, 1530, false, 1, 1);
			if (i == 4)_monsterManager->Medusa_Head_Set(950, 750, false, 1, 1);
		}
    }

	if (_spawnCount > 300) _spawnCount = 0;
}

void Map_06::Collision()
{
	//Monster Collision
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
