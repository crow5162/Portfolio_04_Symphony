#include "stdafx.h"
#include "Map_13.h"


HRESULT Map_13::init()
{
	MapMaster::init();

	CAMERAMANAGER->set_CameraWorldSize(1024, 4924);
	SCENEMANAGER->setSceneNumber(14);

	_playerStartPosX = 940;
	_playerStartPosY = 3500;

	_alucard->AlucardPositionSet(&_playerStartPosX, &_playerStartPosY);

	for (int i = 0; i < 4; i++)
	{
		_torchLight[i] = IMAGEMANAGER->findImage("TorchLight");
	}

	_frameCount = _currentFrameX = _currentFrameY = 0;

	for (int i = 0; i < GROUNDNUMBER; i++)
	{
		_ground[0].x = 510;
		_ground[0].y = 4920;

		_ground[1].x = 575;
		_ground[1].y = 2873;

		_ground[2].x = 575;
		_ground[2].y = 2360;

		_ground[3].x = 512;
		_ground[3].y = 825;

		_ground[i].rc = RectMakeCenter(_ground[i].x, _ground[i].y, 255, 50);
		_ground[3].rc = RectMakeCenter(_ground[3].x, _ground[3].y, 128, 50);

		_ground[i].isDraw = false;
	}

	for (int i = 0; i < 4; i++)
	{
		_wall[0].x = 425;
		_wall[0].y = 2780;

		_wall[1].x = 725;
		_wall[1].y = 2780;

		_wall[2].x = 425;
		_wall[2].y = 2270;

		_wall[3].x = 725;
		_wall[3].y = 2270;

		_wall[i].rc = RectMakeCenter(_wall[i].x, _wall[i].y, 50, 180);
	}

	_monsterManager->Skeleton_Knight_Set(630, 2740, true);
	_monsterManager->Skeleton_Knight_Set(630, 2220, true);

	_stageChange.x = 1000;
	_stageChange.y = 420;
	_stageChange.width = 50;
	_stageChange.height = 200;
	_stageChange.rc = RectMakeCenter(_stageChange.x, _stageChange.y, _stageChange.width, _stageChange.height);

	return S_OK;
}

void Map_13::update()
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

	RECT temp;

	if (IntersectRect(&temp, &_stageChange.rc, &_alucard->GetAlucardRect()))
	{
		SCENEMANAGER->changeScene("Map_14");
	}

	CAMERAMANAGER->set_CameraXY(_alucard->GetAlucard().x, _alucard->GetAlucard().y, true, true);

	if (_openMiniMap)
	{
		_miniPlayer = RectMake(_alucard->GetAlucard().x / 22 + 427, _alucard->GetAlucard().y / 22 + 87,
			10, 10);
	}
}

void Map_13::release()
{
}

void Map_13::render()
{
	IMAGEMANAGER->findImage("TestMap_13")->render(CAMERAMANAGER->getWorldDC(), 0, 0);

	_torchLight[0]->frameRender(CAMERAMANAGER->getWorldDC(), 485, 4637, _currentFrameX, _currentFrameY);
	_torchLight[1]->frameRender(CAMERAMANAGER->getWorldDC(), 485, 2583, _currentFrameX, _currentFrameY);
	_torchLight[2]->frameRender(CAMERAMANAGER->getWorldDC(), 485, 2072, _currentFrameX, _currentFrameY);
	_torchLight[3]->frameRender(CAMERAMANAGER->getWorldDC(), 485, 536, _currentFrameX, _currentFrameY);

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

void Map_13::ObjectFrameCount()
{
	_frameCount++;
	if (_frameCount % 3 == 0)
	{
		_currentFrameX++;
		_frameCount = 0;
		if (_currentFrameX >= 4) _currentFrameX = 0;
	}
}

void Map_13::Collision()
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
	}
}

void Map_13::NextStage()
{
}
