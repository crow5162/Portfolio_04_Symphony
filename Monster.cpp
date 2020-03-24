#include "stdafx.h"
#include "Monster.h"


Monster::Monster()
{
}


Monster::~Monster()
{
}

HRESULT Monster::init()
{
	_attack = new MonsterAttack;
	_attack->init();

	return S_OK;
}

void Monster::release()
{
	_attack->release();
}

void Monster::update()
{
	Gravity();
	GotoAngleMoving();
	GotoAngleSpeedMoving();

	_attack->update();
}

void Monster::render()
{
	if (KEYMANAGER->isToggleKey('M'))
	{
		Rectangle(CAMERAMANAGER->getWorldDC(), _monsterInfo.rc);
		Rectangle(CAMERAMANAGER->getWorldDC(), _monsterInfo.attackCheck.rc);
	}
	_attack->render();
}

void Monster::Gravity()
{
	if (_monsterInfo.activeGravity)
	{
		_monsterInfo.y += _monsterInfo.gravity;
	}
}

void Monster::GotoAngleMoving()
{
	if (!_isMoving) return;

	float elapsedTime = TIMEMANAGER->getElapsedTime();

	float moveSpeed = (elapsedTime / _time) * _travelRange;

	_monsterInfo.x +=  cosf(_monsterInfo.angle) * moveSpeed;
	_monsterInfo.y += -sinf(_monsterInfo.angle) * moveSpeed;

	float time = TIMEMANAGER->getElapsedTime();

	if (_time + _worldTimeCount <= TIMEMANAGER->getWorldTime())
	{
		_worldTimeCount = TIMEMANAGER->getWorldTime();

		_monsterInfo.x = _endX;
		_monsterInfo.y = _endY;
		_isMoving = false;
	}
}

void Monster::GotoAngleSpeedMoving()
{

}

void Monster::GotoAngle(float startX, float startY, float targetX, float targetY, float totaltime)
{
	if (!_isMoving)
	{
		_monsterInfo.x = startX;
		_monsterInfo.y = startY;

		_endX = targetX;
		_endY = targetY;

		_travelRange = getDistance(_monsterInfo.x, _monsterInfo.y, _endX, _endY);

		_monsterInfo.angle = getAngle(_monsterInfo.x, _monsterInfo.y, _endX, _endY);

		_worldTimeCount = TIMEMANAGER->getWorldTime();

		_time = totaltime;

		_isMoving = true;
	}
}
void Monster::GotoAngleSpeed(float targetX, float targetY, float speed)
{
	if (!_isStop)
	{                                                                                                                                                                                         
		_endX2 = targetX;
		_endY2 = targetY;
		_speed = speed;
		_monsterInfo.angle = getAngle(_monsterInfo.x, _monsterInfo.y, _endX2, _endY2);
		_monsterInfo.x +=  cosf(_monsterInfo.angle) * _speed;
		_monsterInfo.y += -sinf(_monsterInfo.angle) * _speed;
	}
	if ((_monsterInfo.x < _endX2 + speed /2.f && _monsterInfo.x > _endX2 - speed / 2.f) && 
		(_monsterInfo.y < _endY2 + speed / 2.f && _monsterInfo.y > _endY2 - speed / 2.f))
		//목표지점으로 부터 공차. (떨리는 현상)
	{
		_isStop = true;
		_speed = 0;
	}
	else
	{
		_isStop = false;
	}
}
