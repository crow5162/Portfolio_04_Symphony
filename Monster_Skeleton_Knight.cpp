#include "stdafx.h"
#include "Monster_Skeleton_Knight.h"


Monster_Skeleton_Knight::Monster_Skeleton_Knight()
{

}


Monster_Skeleton_Knight::~Monster_Skeleton_Knight()
{
}

HRESULT Monster_Skeleton_Knight::init(float x, float y, int monstertype, bool GravityisActive)
{
	Monster::init();

	_moveImage   = IMAGEMANAGER->addFrameImage("SkeletonKnightMove", "Image/MonsterImage/Skeleton_Knight/개선/State_Move.bmp", 480, 259, 6, 2, true, RGB(255, 0, 255));
	_attackImage = IMAGEMANAGER->addFrameImage("SkeletonKnightAttack", "Image/MonsterImage/Skeleton_Knight/개선/State_Attack.bmp", 935, 362, 5, 2, true, RGB(255, 0, 255));

	_monsterInfo.x = x;
	_monsterInfo.y = y;
	_monsterInfo.activeGravity = GravityisActive;

	_monsterInfo.gravity = 10.f;
	_monsterInfo.hp = 20;
	_monsterInfo.damage = 15;
	_monsterInfo.def = 3;

	_monsterInfo.width  = SKELETONKNIGHTWIDTH;
	_monsterInfo.height = SKELETONKNIGHTHEIGHT;

	_monsterInfo.speed = SKELETONKNIGHTSPEED;

	_monsterInfo.monsterType = (MonsterType)monstertype;

	_monsterInfo.rc = RectMakeCenter(_monsterInfo.x, _monsterInfo.y, _monsterInfo.width, _monsterInfo.height);

	_moveFrameX = _moveFrameY = 0;
	_attackFrameX = _attackFrameY = 0;

	_beCount = 0;
	_monsterInfo.behavior = MOVING;

	Monster::init();

	return S_OK;
}

void Monster_Skeleton_Knight::update()
{
	Monster::update();

	SkeletonState();
	SkelBehavior();
	
	SkeletonAttackRectMake();

	_monsterInfo.rc = RectMakeCenter(_monsterInfo.x, _monsterInfo.y, _monsterInfo.width, _monsterInfo.height);
}

void Monster_Skeleton_Knight::release()
{
	
}

void Monster_Skeleton_Knight::render()
{
	Monster::render();
	
	switch (_monsterInfo.state)
	{
	case MOVE_LEFT :
		_moveImage->frameRender(CAMERAMANAGER->getWorldDC(), _monsterInfo.rc.left - 15, _monsterInfo.rc.top - 8, _moveFrameX, _moveFrameY);
		break;
		
	case MOVE_RIGHT :

		_moveImage->frameRender(CAMERAMANAGER->getWorldDC(), _monsterInfo.rc.left, _monsterInfo.rc.top - 8, _moveFrameX, _moveFrameY);
		break;
	case ATTACK_LEFT:
		_attackImage->frameRender(CAMERAMANAGER->getWorldDC(), _monsterInfo.rc.left - 90, _monsterInfo.rc.top - 60, _attackFrameX, _attackFrameY);
		break;
	case ATTACK_RIGHT:
		_attackImage->frameRender(CAMERAMANAGER->getWorldDC(), _monsterInfo.rc.left - 25, _monsterInfo.rc.top - 60, _attackFrameX, _attackFrameY);
		break;
	default:
		break;
	}

}

void Monster_Skeleton_Knight::SkeletonState()
{
	switch (_monsterInfo.state)
	{
	case MOVE_LEFT:

		LeftMoveFrame();
		_monsterInfo.x -= _monsterInfo.speed;
		break;

	case MOVE_RIGHT:
		
		RightMoveFrame();
		_monsterInfo.x += _monsterInfo.speed;
		break;

	case ATTACK_LEFT:

		LeftAttackFrame();
		break;
	case ATTACK_RIGHT:

		RightAttackFrame();
		break;

	default:
		break;
	}

	_frameCount++;
}

void Monster_Skeleton_Knight::SkelBehavior()
{
	//일정 시간마다 방향전환 이동.
	if (_monsterInfo.behavior == MOVING)
	{
		if (_monsterInfo.behavior != MOVING) _beCount = 0;

		_beCount++;

		if (_beCount <= 150)
		{
			_monsterInfo.state = MOVE_LEFT;
		}
		else if (_beCount > 150 && _beCount <= 300)
		{
			_monsterInfo.state = MOVE_RIGHT;
		}

		if (_beCount > 300) _beCount = 0;
	}

	else if (_monsterInfo.behavior == ATTACKING_LEFT)
	{
		if (_monsterInfo.behavior != ATTACKING_LEFT) _beCount = 0;
	
		_beCount++;
	
		if (_beCount <= 30)
		{
			_monsterInfo.state = ATTACK_LEFT;
		}
		else if (_beCount > 30 && _beCount <= 110)
		{
			_monsterInfo.state = MOVE_LEFT;
			_monsterInfo.x += SKELETONKNIGHTSPEED;
		}
		if (_beCount > 110)
		{
			_beCount = 0;
			_attackFrameX = 3;
		}
	}

	else if (_monsterInfo.behavior == ATTACKING_RIGHT)
	{
		if (_monsterInfo.behavior != ATTACKING_RIGHT) _beCount = 0;

		_beCount++;

		if (_beCount <= 30)
		{
			_monsterInfo.state = ATTACK_RIGHT;
		}
		else if (_beCount > 30 && _beCount <= 110)
		{
			_monsterInfo.state = MOVE_RIGHT;
			_monsterInfo.x -= SKELETONKNIGHTSPEED;
		}
		if (_beCount > 110)
		{
			_beCount = 0;
			_attackFrameX = 1;
		}
	}

}

void Monster_Skeleton_Knight::SkeletonAttackRectMake()
{
	if (_monsterInfo.state == ATTACK_LEFT)
	{
		if (_monsterInfo.image->getFrameX() == 1)
		{
			//제한두지 않으면 계속해서 렉트가 생성됩니다.
			if (_frameCount == 3)
			{
				_attack->NormalMonsterAttack(_monsterInfo.x - 80, _monsterInfo.y - 40, 60, 60, 10);
			}
		}
		else if (_monsterInfo.image->getFrameX() != 1)
			_monsterInfo.attackCheck.isAttack = false;
	}
	else if (_monsterInfo.state == ATTACK_RIGHT)
	{
		if (_monsterInfo.image->getFrameX() == 3)
		{
			if (_frameCount == 3)
			{
				_attack->NormalMonsterAttack(_monsterInfo.x + 80, _monsterInfo.y - 40, 60, 60, 10);
			}
		}

		else if (_monsterInfo.image->getFrameX() != 3)
			_monsterInfo.attackCheck.isAttack = false;
	}
	else
	{
		_monsterInfo.attackCheck.isAttack = false;
	}

	if (_monsterInfo.attackCheck.isAttack)
	{
		_monsterInfo.attackCheck.width = 60;
		_monsterInfo.attackCheck.height = 60;

		if (_monsterInfo.state == ATTACK_LEFT)
		{
			_monsterInfo.attackCheck.x = _monsterInfo.x - 80;
			_monsterInfo.attackCheck.y = _monsterInfo.y - 40;

			_monsterInfo.attackCheck.rc = RectMakeCenter(_monsterInfo.attackCheck.x, _monsterInfo.attackCheck.y, 
				_monsterInfo.attackCheck.width, _monsterInfo.attackCheck.height);
		}
		else if (_monsterInfo.state == ATTACK_RIGHT)
		{
			_monsterInfo.attackCheck.x = _monsterInfo.x + 80;
			_monsterInfo.attackCheck.y = _monsterInfo.y - 40;
			_monsterInfo.attackCheck.rc = RectMakeCenter(_monsterInfo.attackCheck.x, _monsterInfo.attackCheck.y, 
				_monsterInfo.attackCheck.width, _monsterInfo.attackCheck.height);
		}
	}
	else
	{
		_monsterInfo.attackCheck.rc = RectMakeCenter(_monsterInfo.x, _monsterInfo.y, 0, 0);
	}

}

void Monster_Skeleton_Knight::LeftMoveFrame()
{
	_monsterInfo.image = IMAGEMANAGER->findImage("SkeletonKnightMove");

	_moveFrameY = 1;
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

void Monster_Skeleton_Knight::RightMoveFrame()
{
	_monsterInfo.image = IMAGEMANAGER->findImage("SkeletonKnightMove");

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

void Monster_Skeleton_Knight::LeftAttackFrame()
{
	_monsterInfo.image = IMAGEMANAGER->findImage("SkeletonKnightAttack");

	_attackFrameY = 1;
	if (_frameCount % 8 == 0)
	{
		_attackFrameX--;

		if (_attackFrameX <= 0)
		{
			_attackFrameX = _monsterInfo.image->getMaxFrameX();
		}
		_frameCount = 0;
	}
}

void Monster_Skeleton_Knight::RightAttackFrame()
{
	_monsterInfo.image = IMAGEMANAGER->findImage("SkeletonKnightAttack");

	_attackFrameY = 0;
	if (_frameCount % 8 == 0)
	{
		_attackFrameX++;

		if (_attackFrameX >= _monsterInfo.image->getMaxFrameX())
		{
			_attackFrameX = 0;
		}
		_frameCount = 0;
	}
}
