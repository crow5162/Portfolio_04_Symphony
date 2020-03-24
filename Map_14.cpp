#include "stdafx.h"
#include "Map_14.h"

HRESULT Map_14::init()
{
	MapMaster::init();

	CAMERAMANAGER->set_CameraWorldSize(3072, 1389);
	SCENEMANAGER->setSceneNumber(16);

	_playerStartPosX = 75;
	_playerStartPosY = 330;

	_alucard->AlucardPositionSet(&_playerStartPosX, &_playerStartPosY);


	for (int i = 0; i < GROUNDNUMBER; i++)
	{
		_ground[0].x = 580;
		_ground[0].y = 619;

		_ground[1].x = 410;
		_ground[1].y = 1003;

		_ground[2].x = 795;
		_ground[2].y = 1099;

		_ground[3].x = 1400;
		_ground[3].y = 1292;

		_ground[0].rc = RectMakeCenter(_ground[0].x, _ground[0].y, 370, 40);
		_ground[1].rc = RectMakeCenter(_ground[1].x, _ground[1].y, 325, 40);
		_ground[2].rc = RectMakeCenter(_ground[2].x, _ground[2].y, 220, 40);
		_ground[3].rc = RectMakeCenter(_ground[3].x, _ground[3].y, 2450, 40);
		_ground[i].isDraw = false;
	}

	//보스몬스터 세팅. Map14는 두마리의 보스몬스터가 등장.
	_monsterManager->Gergoyle_Set(1550, 900, false);
	_monsterManager->Slogra_Set(1400, 900, true);

	return S_OK;
}

void Map_14::update()
{
	MapMaster::update();

	if (KEYMANAGER->isOnceKeyDown('Z'))
	{
		for (int i = 0; i < GROUNDNUMBER; i++)
		{
			_ground[i].isDraw = _ground[i].isDraw ? false : true;
		}
	}

	GroundCollision();
	CAMERAMANAGER->set_CameraXY(_alucard->GetAlucard().x, _alucard->GetAlucard().y, true, true);

	if (_openMiniMap)
	{
		_miniPlayer = RectMake(_alucard->GetAlucard().x / 17 + 473, _alucard->GetAlucard().y / 17 + 88,
			10, 10);
	}
}

void Map_14::release()
{
}

void Map_14::render()
{
	IMAGEMANAGER->findImage("TestMap_14")->render(CAMERAMANAGER->getWorldDC(), 0, 0);

	for (int i = 0; i < GROUNDNUMBER; i++)
	{
		if (_ground[i].isDraw)
		{
			Rectangle(CAMERAMANAGER->getWorldDC(), _ground[i].rc);
		}
	}

	MapMaster::render();
}

void Map_14::GroundCollision()
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
				if (IntersectRect(&temp, &_ground[3].rc, &_monsterManager->getMonsterVector()[i]->getMonsterRect()))
				{
					if (_monsterManager->getMonsterVector()[i]->getMonsterRect().bottom >= _ground[3].rc.top)
					{
						_monsterManager->getMonsterVector()[i]->setMonsterY(_ground[3].rc.top - _monsterManager->getMonsterVector()[i]->getMonsterInfo().height / 2);
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
