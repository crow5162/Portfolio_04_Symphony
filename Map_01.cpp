#include "stdafx.h"
#include "Map_01.h"

Map_01::Map_01()
{
}

Map_01::~Map_01()
{
}

HRESULT Map_01::init()
{
	MapMaster::init();

	CAMERAMANAGER->set_CameraWorldSize(1536, 2142);
	SCENEMANAGER->setSceneNumber(1);

	_playerStartPosX = 400;
	_playerStartPosY = 1860;

	_alucard->AlucardPositionSet(&_playerStartPosX, &_playerStartPosY);

	_ground.x = 890;
	_ground.y = 1969;	
	_ground.rc = RectMakeCenter(_ground.x, _ground.y, GROUNDWIDTH, GROUNDHEIGHT);
	_ground.isDraw = false;
	_gameStartAlpha = 255;
	
	_loopX = _loopY = 0;

	_stageChange.x = 1000;
	_stageChange.y = 420;
	_stageChange.width = 50;
	_stageChange.height = 200;
	_stageChange.rc = RectMakeCenter(_stageChange.x, _stageChange.y, _stageChange.width, _stageChange.height);

	_item->WeaponItemSet(1200, 1900);

	_stageChange.x = 1515;
	_stageChange.y = 1855;
	_stageChange.width = 50;
	_stageChange.height = 200;
	_stageChange.rc = RectMakeCenter(_stageChange.x, _stageChange.y, _stageChange.width, _stageChange.height);

	return S_OK;
}

void Map_01::update()
{
	MapMaster::update();

	_loopX += 1;

	CAMERAMANAGER->set_CameraXY(_alucard->GetAlucard().x, _alucard->GetAlucard().y, true, true);

	if (KEYMANAGER->isOnceKeyDown('Z'))
	{
		_ground.isDraw = _ground.isDraw ? false : true;
	}

	RECT temp;

	CollisionTest();

	if (_openMiniMap)
	{
		_miniPlayer = RectMake(_alucard->GetAlucard().x / 16, _alucard->GetAlucard().y / 16 + 490,
			10, 10);
	}

	if (_gameStartAlpha != 0)
	{
		_gameStartAlpha--;
	}

	if (IntersectRect(&temp, &_stageChange.rc, &_alucard->GetAlucardRect()))
	{
		SCENEMANAGER->changeScene("Map_02");
	}
}

void Map_01::release()
{
	
}

void Map_01::render()
{
	IMAGEMANAGER->findImage("Map_01_Cloud")->loopRender(CAMERAMANAGER->getWorldDC(), &RectMake(0, 0, 1536, 2142), _loopX, _loopY);
	IMAGEMANAGER->findImage("TestMap_01")->render(CAMERAMANAGER->getWorldDC(), 0,0);

	if (_ground.isDraw)
	{
		Rectangle(CAMERAMANAGER->getWorldDC(), _ground.rc);
		IMAGEMANAGER->findImage("Map_01_Pixel")->render(CAMERAMANAGER->getWorldDC(), 0, 0);
	}

	MapMaster::render();

	IMAGEMANAGER->findImage("UIStart")->alphaRender(getMemDC(), 0, 0, _gameStartAlpha);
}

void Map_01::CollisionTest()
{
	//Monster 客 Ground 面倒 贸府.
	for (int i = 0; i < _monsterManager->getMonsterVector().size(); i++)
	{
		if (_monsterManager->getMonsterVector().size() == 0) return;
	
		RECT temp;
	
		if (IntersectRect(&temp, &_ground.rc, &_monsterManager->getMonsterVector()[i]->getMonsterRect()))
		{
			if (_monsterManager->getMonsterVector()[i]->getMonsterRect().bottom >= _ground.rc.top)
			{
				_monsterManager->getMonsterVector()[i]->setMonsterY(_ground.rc.top - _monsterManager->getMonsterVector()[i]->getMonsterInfo().height /2);
				_monsterManager->getMonsterVector()[i]->setMonsterGravity(false);
			}
		}
		else if (_monsterManager->getMonsterVector()[i]->getMonsterRect().bottom < _ground.rc.top)
		{
			_monsterManager->getMonsterVector()[i]->setMonsterGravity(true);
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


