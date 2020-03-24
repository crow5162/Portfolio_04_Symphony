#include "stdafx.h"
#include "Monster_Skeleton.h"

Monster_Skeleton::Monster_Skeleton()
{
	IMAGEMANAGER->addFrameImage("Skeleton_Red_Move", "Image/MonsterImage/Skeleton/Skeleton_Red_Move3.bmp", 531, 235, 8, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Skeleton_Red_Death", "Image/MonsterImage/Skeleton/Skeleton_Red_Death2.bmp", 664, 235, 10, 2, true, RGB(255, 0, 255));
}

Monster_Skeleton::~Monster_Skeleton()
{

}

HRESULT Monster_Skeleton::init(float posx, float posy, bool gravityisActive, int monstertype)
{
	Monster::init();

	_monsterInfo.x = posx;
	_monsterInfo.y = posy;

	_monsterInfo.activeGravity = gravityisActive;
	_monsterInfo.monsterType = (MonsterType)monstertype;

	_monsterInfo.width = SKELETONWIDTH;
	_monsterInfo.height = SKELETONHEIGHT;

	_monsterInfo.gravity = 2.0f;
	_monsterInfo.hp = 10;
	_monsterInfo.damage = 10;
	_monsterInfo.def = 1;

	_monsterInfo.image = IMAGEMANAGER->findImage("Skeleton_Red_Move");

	_monsterInfo.rc = RectMakeCenter(_monsterInfo.x, _monsterInfo.y, _monsterInfo.width, _monsterInfo.height);

	//프레임 카운터 초기화.
	_moveFrameX = _moveFrameY = _frameCount = 0;
	_deathFrameX = _deathFrameY = 0;

	//스켈레톤의 행동 카운트 (일정시간마다 이동.)
	_monsterInfo.behavior = MOVING;
	_beCount = 0;

	return S_OK;
}

void Monster_Skeleton::update()
{
	Monster::update();

	SkeletonState();
	SkeletonBehavior();
	
	_monsterInfo.rc = RectMakeCenter(_monsterInfo.x, _monsterInfo.y, _monsterInfo.width, _monsterInfo.height);
}

void Monster_Skeleton::release()
{
	
}

void Monster_Skeleton::render()
{
	Monster::render();

	switch (_monsterInfo.state)
	{
	case MOVE_LEFT:
	case MOVE_RIGHT:
		_monsterInfo.image->frameRender(CAMERAMANAGER->getWorldDC(), _monsterInfo.rc.left, _monsterInfo.rc.top, _moveFrameX, _moveFrameY);
		break;
	case DEATH:
		_monsterInfo.image->frameRender(CAMERAMANAGER->getWorldDC(), _monsterInfo.rc.left, _monsterInfo.rc.top, _deathFrameX, _deathFrameY);
		break;
	default:
		break;
	}
	
}

void Monster_Skeleton::SkeletonState()
{
	_frameCount++;

	switch (_monsterInfo.state)
	{
	case MOVE_LEFT:
		LeftMoveFrame();
		_monsterInfo.x -= SKELETONSPEED;
		break;

	case MOVE_RIGHT:
		RightMoveFrame();
		_monsterInfo.x += SKELETONSPEED;
		break;

	case DEATH:
		DeathFrame();

		break;

	default:
		break;
	}

}

void Monster_Skeleton::SkeletonBehavior()
{
	//일정시간에 따라 좌, 우 반복적으로 움직인다.
	if (_monsterInfo.behavior == MOVING)
	{
		if (_monsterInfo.behavior != MOVING) _beCount = 0;

		_beCount++;

		if (_beCount <= 120)
		{
			_monsterInfo.state = MOVE_LEFT;
		}
		else if (_beCount > 120 && _beCount <= 240)
		{
			_monsterInfo.state = MOVE_RIGHT;
		}
		if (_beCount > 240) _beCount = 0;
	}
	

}

void Monster_Skeleton::LeftMoveFrame()
{
	_monsterInfo.image = IMAGEMANAGER->findImage("Skeleton_Red_Move");

	_moveFrameY = 1;
	if (_frameCount % 10 == 0)
	{
		_moveFrameX--;
		if (_moveFrameX < 0)
			_moveFrameX = _monsterInfo.image->getMaxFrameX();

		_frameCount = 0;
	}
}

void Monster_Skeleton::RightMoveFrame()
{
	_monsterInfo.image = IMAGEMANAGER->findImage("Skeleton_Red_Move");

	_moveFrameY = 0;
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

void Monster_Skeleton::DeathFrame()
{
	_monsterInfo.image = IMAGEMANAGER->findImage("Skeleton_Red_Death");

	_deathFrameY = 0;

	if (_frameCount % 10 == 0)
	{
		_deathFrameX++;
		if (_deathFrameX > _monsterInfo.image->getMaxFrameX())
		{
			_deathFrameX = 0;
		}
		_frameCount = 0;
	}
}
