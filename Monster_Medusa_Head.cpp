#include "stdafx.h"
#include "Monster_Medusa_Head.h"


Monster_Medusa_Head::Monster_Medusa_Head()
{

}


Monster_Medusa_Head::~Monster_Medusa_Head()
{
}

HRESULT Monster_Medusa_Head::init(float x, float y, bool gravityActive,int monstertype, int kind, bool direction)
{
	Monster::init();

	IMAGEMANAGER->addFrameImage("Medusa_Yellow", "Image/MonsterImage/MedusaHead/YellowHead.bmp", 224, 94, 4, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Medusa_Blue", "Image/MonsterImage/MedusaHead/BlueHead.bmp", 224, 94, 4, 2, true, RGB(255, 0, 255));

	_monsterInfo.x = x;
	_monsterInfo.y = y;
	_monsterInfo.activeGravity = gravityActive;

	_medusaKind = kind;
	_direction = direction;

	_monsterInfo.width  = MEDUSAWIDTH;
	_monsterInfo.height = MEDUSAHEIGHT;

	_monsterInfo.monsterType = (MonsterType)monstertype;

	_monsterInfo.gravity = 2.0f;
	_monsterInfo.hp = 10;
	_monsterInfo.damage = 10;
	_monsterInfo.def = 1;

	//MedusaHead의 종류를 결정합니다. 0이아니면 Blue
	if (_medusaKind == 0)
	{
		_monsterInfo.image = IMAGEMANAGER->findImage("Medusa_Yellow");
	}
	else
	{
		_monsterInfo.image = IMAGEMANAGER->findImage("Medusa_Blue");
	}

	_monsterInfo.rc = RectMakeCenter(_monsterInfo.x, _monsterInfo.y, _monsterInfo.width, _monsterInfo.height);

	//Medusa Frame Counter
	_count = 0;
	_frameCount = _moveFrameX = _moveFrameY = 0;

	//Medusa Behavior
	_beCount = 0;
	_monsterInfo.behavior = MOVING;

	return S_OK;
}

void Monster_Medusa_Head::update()
{
	Monster::update();

	MedusaState();
	MedusaBehavior();

	_monsterInfo.rc = RectMakeCenter(_monsterInfo.x, _monsterInfo.y, _monsterInfo.width, _monsterInfo.height);
}

void Monster_Medusa_Head::release()
{
}

void Monster_Medusa_Head::render()
{
	Monster::render();

	switch (_monsterInfo.state)
	{
	case MOVE_LEFT:
		_monsterInfo.image->frameRender(CAMERAMANAGER->getWorldDC(), _monsterInfo.rc.left, _monsterInfo.rc.top, _moveFrameX, _moveFrameY);
		break;
	case MOVE_RIGHT:
		_monsterInfo.image->frameRender(CAMERAMANAGER->getWorldDC(), _monsterInfo.rc.left - 10, _monsterInfo.rc.top, _moveFrameX, _moveFrameY);
		break;
	default:
		break;
	}

}

void Monster_Medusa_Head::MedusaBehavior()
{
	if (_monsterInfo.behavior == MOVING)
	{
		_beCount++;

		if (_direction)
			//디렉션 True 일때 이동방향 왼쪽에서 오른쪽
		{

			if (_beCount <= 100)
			{
				_monsterInfo.state = MOVE_LEFT;
				_monsterInfo.y += 5.0f;
			}
			else if (_beCount > 100 && _beCount <= 200)
			{
				_monsterInfo.state = MOVE_LEFT;
				_monsterInfo.y -= 5.0f;
			}
			if (_beCount > 200)
			{
				_beCount = 0;
			}
		}

		if (!_direction)
			//디렉션 false 일때 오른쪽에서 왼쪽.
		{
			if (_beCount <= 100)
			{
				_monsterInfo.state = MOVE_RIGHT;
				_monsterInfo.y -= 5.0f;
			}
			else if (_beCount > 100 && _beCount <= 200)
			{
				_monsterInfo.state = MOVE_RIGHT;
				_monsterInfo.y += 5.0f;
			}
			if (_beCount > 200)
			{
				_beCount = 0;
			}
		}
	}
}

void Monster_Medusa_Head::MedusaState()
{
	switch (_monsterInfo.state)
	{
	case MOVE_LEFT:
		LeftMoveFrame();
		if (_frameCount == 9)
		{
			_attack->NormalMonsterAttack(_monsterInfo.x, _monsterInfo.y, 40, 40, 3);
		}
		_monsterInfo.x -= MEDUSAHEADSPEED;
		break;
	case MOVE_RIGHT:
		RightMoveFrame();
		if (_frameCount == 9)
		{
			_attack->NormalMonsterAttack(_monsterInfo.x, _monsterInfo.y, 40, 40, 3);
		}

		_monsterInfo.x += MEDUSAHEADSPEED;
		break;
	case DEATH:

		break;
	default:
		break;
	}

	_frameCount++;
}

void Monster_Medusa_Head::LeftMoveFrame()
{
	_moveFrameY = 1;
	if (_frameCount % 10 == 0)
	{
		_moveFrameX--;
		if (_moveFrameX < 0)
			_moveFrameX = _monsterInfo.image->getMaxFrameX();

		_frameCount = 0;
	}
}

void Monster_Medusa_Head::RightMoveFrame()
{
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
