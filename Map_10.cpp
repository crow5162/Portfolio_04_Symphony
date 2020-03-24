#include "stdafx.h"
#include "Map_10.h"

HRESULT Map_10::init()
{
	MapMaster::init();

	CAMERAMANAGER->set_CameraWorldSize(2849, 768);
	SCENEMANAGER->setSceneNumber(11);

	_playerStartPosX = 2720;
	_playerStartPosY = 410;

	_alucard->AlucardPositionSet(&_playerStartPosX, &_playerStartPosY);

	for (int i = 0; i < 2; i++)
	{
		_monsterManager->Armored_Knight_Set(750 + i * 1100, 570, true);
	}

	_monsterManager->Skeleton_Knight_Set(1150, 260, true);
	_monsterManager->Skeleton_Knight_Set(1350, 565, true);

	for (int i = 0; i < 3; i++)
	{
		_candle[i] = IMAGEMANAGER->findImage("BlueCandle");
	}

	_frameCount = _currentFrameX = _currentFrameY = 0;

	for (int i = 0; i < GROUNDNUMBER; i++)
	{
		_ground[0].x = 1400;
		_ground[0].y = 707;
		_ground[1].x = 975;
		_ground[1].y = 410;
		_ground[2].x = 1305;
		_ground[2].y = 350;
		_ground[3].x = 565;
		_ground[3].y = 470;
		_ground[4].x = 178;
		_ground[4].y = 589;
		_ground[5].x = 295;
		_ground[5].y = 648;

		_ground[0].rc = RectMakeCenter(_ground[0].x, _ground[0].y, 2080, GROUNDHEIGHT);
		_ground[1].rc = RectMakeCenter(_ground[1].x, _ground[1].y, 410, GROUNDHEIGHT);
		_ground[2].rc = RectMakeCenter(_ground[2].x, _ground[2].y, 235, GROUNDHEIGHT);
		_ground[3].rc = RectMakeCenter(_ground[3].x, _ground[3].y, 170, GROUNDHEIGHT);
		_ground[4].rc = RectMakeCenter(_ground[4].x, _ground[4].y, 115, GROUNDHEIGHT);
		_ground[5].rc = RectMakeCenter(_ground[5].x, _ground[5].y, 115, GROUNDHEIGHT);

		_ground[i].isDraw = false;
	}

	for (int i = 0; i < 4; i++)
	{
		_wall[0].x = 2460;
		_wall[0].y = 600;

		_wall[1].x = 340;
		_wall[1].y = 600;

		_wall[2].x = 745;
		_wall[2].y = 320;

		_wall[3].x = 1205;
		_wall[3].y = 320;

		_wall[i].rc = RectMakeCenter(_wall[i].x, _wall[i].y, 50, 180);
	}

	return S_OK;
}

void Map_10::update()
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
	CollisionTest();

	CAMERAMANAGER->set_CameraXY(_alucard->GetAlucard().x, _alucard->GetAlucard().y, true, true);

	if (_openMiniMap)
	{
		_miniPlayer = RectMake(_alucard->GetAlucard().x / 21 + 570, _alucard->GetAlucard().y / 17 + 403,
			10, 10);
	}
}

void Map_10::release()
{
}

void Map_10::render()
{
	IMAGEMANAGER->findImage("TestMap_10")->render(CAMERAMANAGER->getWorldDC(), 0, 0);

	_candle[0]->frameRender(CAMERAMANAGER->getWorldDC(), 1325, 475, _currentFrameX, _currentFrameY);
	_candle[1]->frameRender(CAMERAMANAGER->getWorldDC(), 548, 545, _currentFrameX, _currentFrameY);
	_candle[2]->frameRender(CAMERAMANAGER->getWorldDC(), 540, 300, _currentFrameX, _currentFrameY);

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

void Map_10::ObjectFrameCount()
{
	_frameCount++;
	if (_frameCount % 5 == 0)
	{
		_currentFrameX++;
		_frameCount = 0;
		if (_currentFrameX > 1) _currentFrameX = 0;
	}
}

void Map_10::CollisionTest()
{
	//Monster 와 Ground 충돌 처리.
	for (int i = 0; i < _monsterManager->getMonsterVector().size(); i++)
	{
		if (_monsterManager->getMonsterVector().size() == 0) return;

		RECT temp;

		//Ground가 배열로 깔려있을때 다르게 설정할수있다.
		for (int j = 0; j < GROUNDNUMBER; j++)
		{
			//Rect의 Top과 Monster의 Bottom 충돌 조건. 
			if (IntersectRect(&temp, &_ground[0].rc, &_monsterManager->getMonsterVector()[i]->getMonsterRect()))
			{
				if (_monsterManager->getMonsterVector()[i]->getMonsterInfo().rc.top > _ground[1].rc.top)
				{
					if (_monsterManager->getMonsterVector()[i]->getMonsterRect().bottom >= _ground[0].rc.top)
					{
						_monsterManager->getMonsterVector()[i]->setMonsterY(_ground[0].rc.top - _monsterManager->getMonsterVector()[i]->getMonsterInfo().height / 2);
						_monsterManager->getMonsterVector()[i]->setMonsterGravity(false);
					}
				}
			}
			if (IntersectRect(&temp, &_ground[1].rc, &_monsterManager->getMonsterVector()[i]->getMonsterRect()))
			{
				if (_monsterManager->getMonsterVector()[i]->getMonsterInfo().rc.top < _ground[1].rc.top)
				{
					if (_monsterManager->getMonsterVector()[i]->getMonsterInfo().rc.bottom >= _ground[1].rc.top)
					{
						_monsterManager->getMonsterVector()[i]->setMonsterY(_ground[1].rc.top - _monsterManager->getMonsterVector()[i]->getMonsterInfo().height / 2);
						_monsterManager->getMonsterVector()[i]->setMonsterGravity(false);
					}
				}
			}

		}
		for (int j = 0; j < 4; j++)
		{
			//(좌/우 몬스터 탈출 방지)
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
