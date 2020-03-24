#include "stdafx.h"
#include "MonsterAttack.h"

HRESULT MonsterAttack::init()
{
	IMAGEMANAGER->addFrameImage("Gargoyle_Magic", "Image/MonsterImage/Boss_01/Gargoyle_Fire.bmp", 255, 118, 4, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Death_Magic", "Image/MonsterImage/Death_Boss/Magic_01.bmp", 1176, 147, 8, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Death_Magic2", "Image/MonsterImage/Death_Boss/Magic_02.bmp", 1650, 204, 17, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Death_Magic3", "Image/MonsterImage/Death_Boss/Magic_03.bmp", 616, 75, 8, 1, true, RGB(255, 0, 255));

	return S_OK;
}

void MonsterAttack::update()
{
	for (int i = 0; i < _vMonsterAttack.size(); i++)
	{
		if (_vMonsterAttack.size() == 0) return;

		_vMonsterAttack[i].time++;

		//가고일 파이어의 프레임이미지 재생.
		if (_vMonsterAttack[i].type == Gargoyle_Fire || 
			_vMonsterAttack[i].type == Gargoyle_Fire2 || _vMonsterAttack[i].type == Death_Magic2)
		{
			_vMonsterAttack[i].frameCount++;

			if (_vMonsterAttack[i].frameCount % 6 == 0)
			{
				_vMonsterAttack[i].currentX++;

				if (_vMonsterAttack[i].currentX > _vMonsterAttack[i].img->getMaxFrameX())
				{
					_vMonsterAttack[i].currentX = 0;
				}
				_vMonsterAttack[i].frameCount = 0;
			}
		}

		else if (_vMonsterAttack[i].type == Death_Magic)
		{
			_vMonsterAttack[i].frameCount++;

			if (_vMonsterAttack[i].frameCount % 6 == 0)
			{
				_vMonsterAttack[i].currentX++;

				if (_vMonsterAttack[i].currentX > _vMonsterAttack[i].img->getMaxFrameX())
				{
					_vMonsterAttack[i].currentX = 2;
				}
				_vMonsterAttack[i].frameCount = 0;
			}
		}

		else if (_vMonsterAttack[i].type == Death_Magic3)
		{
			_vMonsterAttack[i].frameCount++;

			if (_vMonsterAttack[i].frameCount % 6 == 0)
			{
				_vMonsterAttack[i].currentX++;

				if (_vMonsterAttack[i].currentX > _vMonsterAttack[i].img->getMaxFrameX())
				{
					_vMonsterAttack[i].currentX = 5;
				}
				_vMonsterAttack[i].frameCount = 0;
			}
		}
	}

	MagicMove();
	EraseAttack();
}

void MonsterAttack::release()
{
}

void MonsterAttack::render()
{
	for (int i = 0; i < _vMonsterAttack.size(); i++)
	{
		if (_vMonsterAttack.size() == 0) return;


		if (_vMonsterAttack[i].type == Normal_Attack) return;

		if (_vMonsterAttack[i].type == Gargoyle_Fire || _vMonsterAttack[i].type == Gargoyle_Fire2)
		{
			_vMonsterAttack[i].img->frameRender(CAMERAMANAGER->getWorldDC(), _vMonsterAttack[i].x - 30, _vMonsterAttack[i].y - 30,
				_vMonsterAttack[i].currentX, _vMonsterAttack[i].currentY);
		}
		
		else if (_vMonsterAttack[i].type == Death_Magic)
		{
			_vMonsterAttack[i].img->frameRender(CAMERAMANAGER->getWorldDC(), _vMonsterAttack[i].x - 45, _vMonsterAttack[i].y - 45,
				_vMonsterAttack[i].currentX, _vMonsterAttack[i].currentY);
		}

		else if (_vMonsterAttack[i].type == Death_Magic2)
		{
			_vMonsterAttack[i].img->frameRender(CAMERAMANAGER->getWorldDC(), _vMonsterAttack[i].x - 45, _vMonsterAttack[i].y - 50,
				_vMonsterAttack[i].currentX, _vMonsterAttack[i].currentY);
		}

		else if (_vMonsterAttack[i].type == Death_Magic3)
		{
			_vMonsterAttack[i].img->frameRender(CAMERAMANAGER->getWorldDC(), _vMonsterAttack[i].x - 45, _vMonsterAttack[i].y - 50,
				_vMonsterAttack[i].currentX, _vMonsterAttack[i].currentY);
		}
	}
}

void MonsterAttack::NormalMonsterAttack(float x, float y, int width, int height, int duration)
{
	MAttack monsterAt;

	monsterAt.x = x;
	monsterAt.y = y;

	monsterAt.width = width;
	monsterAt.height = height;

	monsterAt.duration = duration;
	monsterAt.type = Normal_Attack;

	monsterAt.rc = RectMakeCenter(monsterAt.x, monsterAt.y, monsterAt.width, monsterAt.height);
	//time initial 안해주면 쓰레기값 들어가있어서 작동 안합니다.
	monsterAt.time = 0;

	_vMonsterAttack.push_back(monsterAt);
}

void MonsterAttack::MagicFireAngle(float x, float y, float angle, float speed, int type)
{
	MAttack angleFire;

	angleFire.x = x;
	angleFire.y = y;

	angleFire.angle = angle;
	angleFire.speed = speed;
	angleFire.duration = 999;

	angleFire.type = (MagicType)type;

	if (angleFire.type == Gargoyle_Fire) angleFire.img = IMAGEMANAGER->findImage("Gargoyle_Magic");
	else if (angleFire.type == Death_Magic) angleFire.img = IMAGEMANAGER->findImage("Death_Magic3");
	else if (angleFire.type == Death_Magic3) angleFire.img = IMAGEMANAGER->findImage("Death_Magic");

	angleFire.currentX = 0;
	angleFire.currentY = 0;
	angleFire.frameCount = 0;

	angleFire.rc = RectMakeCenter(angleFire.x, angleFire.y,
		angleFire.img->getFrameWidth(), angleFire.img->getFrameHeight());

	_vMonsterAttack.push_back(angleFire);
}

void MonsterAttack::MagicFireAngleDuration(float x, float y, float angle, float speed, int type, int duration)
{
	MAttack angledurationFire;

	angledurationFire.x = x;
	angledurationFire.y = y;

	angledurationFire.angle = angle;
	angledurationFire.speed = speed;
	angledurationFire.duration = duration;


	angledurationFire.type = (MagicType)type;

	if (angledurationFire.type == Gargoyle_Fire) angledurationFire.img = IMAGEMANAGER->findImage("Gargoyle_Magic");
	else if (angledurationFire.type == Death_Magic) angledurationFire.img = IMAGEMANAGER->findImage("Death_Magic3");
	else if (angledurationFire.type == Death_Magic3) angledurationFire.img = IMAGEMANAGER->findImage("Death_Magic");

	angledurationFire.currentX = 0;
	angledurationFire.currentY = 0;
	angledurationFire.frameCount = 0;

	angledurationFire.rc = RectMakeCenter(angledurationFire.x, angledurationFire.y,
		angledurationFire.img->getFrameWidth(), angledurationFire.img->getFrameHeight());

	angledurationFire.time = 0;

	_vMonsterAttack.push_back(angledurationFire);
}

void MonsterAttack::MagicFire(float x, float y, float speed, int Direction, int type)
{
	MAttack magicFire;

	magicFire.x = x;
	magicFire.y = y;

	magicFire.speed = speed;
	magicFire.duration = 999;

	magicFire.type = (MagicType)type;

	magicFire.currentX = 0; 
	magicFire.currentY = Direction;

	if (magicFire.type == Gargoyle_Fire2)	 magicFire.img = IMAGEMANAGER->findImage("Gargoyle_Magic");
	else if (magicFire.type == Death_Magic2)	 magicFire.img = IMAGEMANAGER->findImage("Death_Magic2");

	magicFire.rc = RectMakeCenter(magicFire.x, magicFire.y, 
		magicFire.img->getFrameWidth(), magicFire.img->getFrameHeight());

	_vMonsterAttack.push_back(magicFire);
}

void MonsterAttack::EraseAttack()
{
	for (_viMonsterAttack = _vMonsterAttack.begin(); _viMonsterAttack != _vMonsterAttack.end();)
	{
		if (_vMonsterAttack.size() == 0) return;

		if ((*_viMonsterAttack).time > (*_viMonsterAttack).duration)
		{
			_viMonsterAttack = _vMonsterAttack.erase(_viMonsterAttack);
		}

		else if ((*_viMonsterAttack).x < 0 || (*_viMonsterAttack).x > CAMERAMANAGER->getWorldCameraSize() ||
			(*_viMonsterAttack).y < 0 || (*_viMonsterAttack).y > CAMERAMANAGER->getWorldCameraSize())
		{
			_viMonsterAttack = _vMonsterAttack.erase(_viMonsterAttack);
		}

		else
		{
			_viMonsterAttack++;
		}
	}
}

void MonsterAttack::AttackDelete(int arrNum)
{
	_vMonsterAttack.erase(_vMonsterAttack.begin() + (arrNum));
}

void MonsterAttack::MagicMove()
{
	for (int i = 0; i < _vMonsterAttack.size(); i++)
	{
		if (_vMonsterAttack.size() == 0) return;
		if (_vMonsterAttack[i].type == Normal_Attack) return;

		if (_vMonsterAttack[i].type == Gargoyle_Fire || _vMonsterAttack[i].type == Death_Magic)
		{
			_vMonsterAttack[i].x += cosf(_vMonsterAttack[i].angle) * _vMonsterAttack[i].speed;
			_vMonsterAttack[i].y += -sinf(_vMonsterAttack[i].angle) * _vMonsterAttack[i].speed;

			_vMonsterAttack[i].rc = RectMakeCenter(_vMonsterAttack[i].x, _vMonsterAttack[i].y,
				_vMonsterAttack[i].img->getFrameWidth(), _vMonsterAttack[i].img->getFrameHeight());
		}

		if (_vMonsterAttack[i].type == Gargoyle_Fire2 || _vMonsterAttack[i].type == Death_Magic2)
		{
			if (_vMonsterAttack[i].currentY == 0)
			{
				_vMonsterAttack[i].x -= _vMonsterAttack[i].speed;
			}
			else if (_vMonsterAttack[i].currentY == 1)
			{
				_vMonsterAttack[i].x += _vMonsterAttack[i].speed;
			}

			_vMonsterAttack[i].rc = RectMakeCenter(_vMonsterAttack[i].x, _vMonsterAttack[i].y,
				_vMonsterAttack[i].img->getFrameWidth(), _vMonsterAttack[i].img->getFrameHeight());
		}
	}
}
