#include "stdafx.h"
#include "Monster_Merman.h"


Monster_Merman::Monster_Merman()
{
	IMAGEMANAGER->addFrameImage("Merman_Move", "Image/MonsterImage/Merman/State_Move.bmp", 513, 205, 8, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Merman_Swim", "Image/MonsterImage/Merman/State_Swim.bmp", 232, 240, 4, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Merman_Fire", "Image/MonsterImage/Merman/State_Fire.bmp", 265, 205, 4, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Merman_Diving", "Image/MonsterImage/Merman/State_Diving.bmp", 600, 75, 8, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Merman_Death", "Image/MonsterImage/Merman/State_Death.bmp", 273, 205, 4, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Merman_Bullet", "Image/MonsterImage/Merman/Merman_Bullet.bmp", 156, 38, 4, 2, true, RGB(255, 0, 255));
}

Monster_Merman::~Monster_Merman()
{
}

HRESULT Monster_Merman::init(float x, float y, int monstertype, bool gravityAcvite)
{
	Monster::init();

	_monsterInfo.x = x;
	_monsterInfo.y = y;
	_monsterInfo.activeGravity = gravityAcvite;

	_monsterInfo.width  = MERMANWIDTH;
	_monsterInfo.height = MERMANHEIGHT;

	_monsterInfo.monsterType = (MonsterType)monstertype;

	_monsterInfo.gravity = 2.0f;
	_monsterInfo.hp = 30;
	_monsterInfo.def = 3;

	_monsterInfo.image = IMAGEMANAGER->findImage("Merman_Move");

	_monsterInfo.rc = RectMakeCenter(_monsterInfo.x, _monsterInfo.y, _monsterInfo.width, _monsterInfo.height);

	//MerMan FrameCounter
	_moveFrameX = _moveFrameY = _frameCount = 0;
	_swimFrameX = _swimFrameY = 0;
	_fireFrameX = _fireFrameY = 0;
	_deathFrameX = _deathFrameY = 0;

	_monsterInfo.behavior = SWIM;
	_beCount = 0;
	_randomMove = 0;

	_randomMove = rand() % 2;
	srand(time(NULL));

	return S_OK;
}

void Monster_Merman::update()
{
	Monster::update();

	MerManState();
	MerManBehavior();

	_monsterInfo.rc = RectMakeCenter(_monsterInfo.x, _monsterInfo.y, _monsterInfo.width, _monsterInfo.height);
}

void Monster_Merman::release()
{
}

void Monster_Merman::render()
{
	Monster::render();
	
	switch (_monsterInfo.state)
	{
	case MOVE_LEFT:
	case MOVE_RIGHT:
		_monsterInfo.image->frameRender(CAMERAMANAGER->getWorldDC(), _monsterInfo.rc.left - 10, _monsterInfo.rc.top, _moveFrameX, _moveFrameY);
		break;
	case SWIM_LEFT:
	case SWIM_RIGHT:
		_monsterInfo.image->frameRender(CAMERAMANAGER->getWorldDC(), _monsterInfo.rc.left, _monsterInfo.rc.top - 10, _swimFrameX, _swimFrameY);
		break;
	case FIRE_LEFT:
	case FIRE_RIGHT:
		_monsterInfo.image->frameRender(CAMERAMANAGER->getWorldDC(), _monsterInfo.rc.left, _monsterInfo.rc.top, _fireFrameX, _fireFrameY);
		break;
	case DIVING:
		_monsterInfo.image->frameRender(CAMERAMANAGER->getWorldDC(), _monsterInfo.rc.left, _monsterInfo.rc.top, _divingFrameX, _divingFrameY);
		break;
	case DEATH:
		_monsterInfo.image->frameRender(CAMERAMANAGER->getWorldDC(), _monsterInfo.rc.left, _monsterInfo.rc.top, _deathFrameX, _deathFrameY);
		break;
	default:
		break;
	}
}

void Monster_Merman::MerManState()
{

	switch (_monsterInfo.state)
	{
	case MOVE_LEFT:
		_monsterInfo.x -= MERMANSPEED;
		_monsterInfo.image = IMAGEMANAGER->findImage("Merman_Move");
		LeftMoveFrame();
		break;
	case MOVE_RIGHT:
		_monsterInfo.x += MERMANSPEED;
		_monsterInfo.image = IMAGEMANAGER->findImage("Merman_Move");
		RightMoveFrame();
		break;
	case SWIM_LEFT:
		_monsterInfo.x -= MERMANSWIMSPEED;
		_monsterInfo.image = IMAGEMANAGER->findImage("Merman_Swim");
		LeftSwimFrame();
		break;
	case SWIM_RIGHT:
		_monsterInfo.x += MERMANSWIMSPEED;
		_monsterInfo.image = IMAGEMANAGER->findImage("Merman_Swim");
		RightSwimFrame();
		break;
	case DIVING:
		_monsterInfo.y -= MERMANJUMPPOWER;
		_monsterInfo.image = IMAGEMANAGER->findImage("Merman_Diving");
		DivingFrame();
		break;
	case FIRE_LEFT:
		_monsterInfo.image = IMAGEMANAGER->findImage("Merman_Fire");
		LeftFireFrame();
		break;
	case FIRE_RIGHT:
		_monsterInfo.image = IMAGEMANAGER->findImage("Merman_Fire");
		RightFireFrame();
		break;
	case DEATH:
		_monsterInfo.image = IMAGEMANAGER->findImage("Merman_Death");
		DeathFrame();
	default:
		break;
	}

	//프레임 카운터
	_frameCount++;
}

void Monster_Merman::MerManBehavior()
{
	if (_monsterInfo.behavior == SWIM)
	{
		if (_monsterInfo.behavior != SWIM) _beCount = 0;

		_beCount++;

		if (_beCount <= 150 && _randomMove == 0)
		{
			_monsterInfo.state = SWIM_RIGHT;
		}
		else if (_beCount <= 150 && _randomMove == 1)
		{
			_monsterInfo.state = SWIM_LEFT;
		}
		else if (_beCount > 150 && _beCount <= 300 && _randomMove ==0 )
		{
			_monsterInfo.state = SWIM_LEFT;
		}
		else if (_beCount > 150 && _beCount <= 300 && _randomMove == 1)
		{
			_monsterInfo.state = SWIM_RIGHT;
		}
		if (_beCount > 300)
		{
			_beCount = 0;
			_randomMove = rand() % 2;
		}
	}
}

void Monster_Merman::LeftMoveFrame()
{
	_moveFrameY = 0;

	if (_frameCount % 10 == 0)
	{
		_moveFrameX--;
		if (_moveFrameX < 0)
		{
			_moveFrameX = _monsterInfo.image->getMaxFrameX();
		}
		_frameCount = 0;
	}
}

void Monster_Merman::RightMoveFrame()
{
	_moveFrameY = 1;

	if (_frameCount % 10 == 0)
	{
		_moveFrameX++;
		if (_moveFrameX > _monsterInfo.image->getMaxFrameX())
		{
			_moveFrameX = 0;
		}
		_frameCount = 0;
	}
}

void Monster_Merman::LeftSwimFrame()
{
	_swimFrameY = 0;

	if (_frameCount % 10 == 0)
	{
		_swimFrameX--;
		if (_swimFrameX < 0)
		{
			_swimFrameX = _monsterInfo.image->getMaxFrameX();
		}
		_frameCount = 0;
	}
}

void Monster_Merman::RightSwimFrame()
{
	_swimFrameY = 1;

	if (_frameCount % 10 == 0)
	{
		_swimFrameX++;

		if (_swimFrameX > _monsterInfo.image->getMaxFrameX())
		{
			_swimFrameX = 0;
		}
		_frameCount = 0;
	}
}

void Monster_Merman::DivingFrame()
{
	_divingFrameY = 0;

	if (_frameCount % 4 == 0)
	{
		_divingFrameX++;

		if (_divingFrameX > _monsterInfo.image->getMaxFrameX())
		{
			_divingFrameX = 0;
		}
		_frameCount = 0;
	}
}

void Monster_Merman::LeftFireFrame()
{
	_fireFrameY = 0;

	if (_frameCount % 24 == 0)
	{
		_fireFrameX++;

		if (_fireFrameX > _monsterInfo.image->getMaxFrameX())
		{
			_fireFrameX = 0;
		}
		_frameCount = 0;
	}
}

void Monster_Merman::RightFireFrame()
{
	_fireFrameY = 1;

	if (_frameCount % 24 == 0)
	{
		_fireFrameX--;

		if (_fireFrameX < 0)
		{
			_fireFrameX = _monsterInfo.image->getMaxFrameX();
		}
		_frameCount = 0;
	}
}

void Monster_Merman::DeathFrame()
{
	_deathFrameY = 0;

	if (_frameCount % 12 == 0)
	{
		_deathFrameX++;

		if (_deathFrameX > _monsterInfo.image->getMaxFrameX())
		{
			_deathFrameX = 0;
		}
		_frameCount = 0;
	}
}

