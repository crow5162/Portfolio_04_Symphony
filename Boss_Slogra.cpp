#include "stdafx.h"
#include "Boss_Slogra.h"


Boss_Slogra::Boss_Slogra()
{
	IMAGEMANAGER->addFrameImage("Slogra_Move", "Image/MonsterImage/Boss_02/Move_State.bmp", 1250, 350, 5, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Slogra_Attack", "Image/MonsterImage/Boss_02/Attack_State_New.bmp", 1500, 350, 6, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Slogra_Attack2", "Image/MonsterImage/Boss_02/Attack2_State.bmp", 500, 350, 2, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Slogra_Attack3", "Image/MonsterImage/Boss_02/Attack3_State.bmp", 250, 405, 1, 2, true, RGB(255, 0, 255));
}


Boss_Slogra::~Boss_Slogra()
{
}

HRESULT Boss_Slogra::init(float x, float y, int monstertype, bool gravity)
{
	Monster::init();

	_monsterInfo.x = x;
	_monsterInfo.y = y;

	_monsterInfo.activeGravity = gravity;
	_monsterInfo.gravity = 2.0f;

	_monsterInfo.width = 80;
	_monsterInfo.height = 120;
	_monsterInfo.hp = 600;
	_monsterInfo.damage = 25;
	_monsterInfo.def = 7;

	_monsterInfo.speed = 2.0f;
	_monsterInfo.state = MOVE_LEFT;
	_monsterInfo.monsterType = (MonsterType)monstertype;

	_monsterInfo.rc = RectMakeCenter(_monsterInfo.x, _monsterInfo.y, _monsterInfo.width, _monsterInfo.height);

#pragma region ANI
	//¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á Idle Left
	_ani.leftIdle = new animation;
	_ani.leftIdle->init(IMAGEMANAGER->findImage("Slogra_Move")->getWidth(), IMAGEMANAGER->findImage("Slogra_Move")->getHeight(),
		IMAGEMANAGER->findImage("Slogra_Move")->getFrameWidth(), IMAGEMANAGER->findImage("Slogra_Move")->getFrameHeight());
	_ani.leftIdle->setPlayFrame(6, 10, false, true);
	_ani.leftIdle->setFPS(4);
	_ani.leftIdle->start();
	//¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á Idle Right
	_ani.rightIdle = new animation;
	_ani.rightIdle->init(IMAGEMANAGER->findImage("Slogra_Move")->getWidth(), IMAGEMANAGER->findImage("Slogra_Move")->getHeight(),
		IMAGEMANAGER->findImage("Slogra_Move")->getFrameWidth(), IMAGEMANAGER->findImage("Slogra_Move")->getFrameHeight());
	_ani.rightIdle->setPlayFrame(1, 5, false, true);
	_ani.rightIdle->setFPS(4);
	_ani.rightIdle->start();
	//¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á Move Left
	_ani.leftMove = new animation;
	_ani.leftMove->init(IMAGEMANAGER->findImage("Slogra_Move")->getWidth(), IMAGEMANAGER->findImage("Slogra_Move")->getHeight(),
		IMAGEMANAGER->findImage("Slogra_Move")->getFrameWidth(), IMAGEMANAGER->findImage("Slogra_Move")->getFrameHeight());
	_ani.leftMove->setPlayFrame(6, 10, false, true);
	_ani.leftMove->setFPS(4);
	_ani.leftMove->start();
	//¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á Move Right
	_ani.rightMove = new animation;
	_ani.rightMove->init(IMAGEMANAGER->findImage("Slogra_Move")->getWidth(), IMAGEMANAGER->findImage("Slogra_Move")->getHeight(),
		IMAGEMANAGER->findImage("Slogra_Move")->getFrameWidth(), IMAGEMANAGER->findImage("Slogra_Move")->getFrameHeight());
	_ani.rightMove->setPlayFrame(1, 5, false, true);
	_ani.rightMove->setFPS(4);
	_ani.rightMove->start();
	//¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á Attack Left
	_ani.leftAttack = new animation;
	_ani.leftAttack->init(IMAGEMANAGER->findImage("Slogra_Attack")->getWidth(), IMAGEMANAGER->findImage("Slogra_Attack")->getHeight(),
		IMAGEMANAGER->findImage("Slogra_Attack")->getFrameWidth(), IMAGEMANAGER->findImage("Slogra_Attack")->getFrameHeight());
	_ani.leftAttack->setPlayFrame(7, 12, false, true);
	_ani.leftAttack->setFPS(2);
	_ani.leftAttack->start();
	//¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á Attack Right
	_ani.rightAttack = new animation;
	_ani.rightAttack->init(IMAGEMANAGER->findImage("Slogra_Attack")->getWidth(), IMAGEMANAGER->findImage("Slogra_Attack")->getHeight(),
		IMAGEMANAGER->findImage("Slogra_Attack")->getFrameWidth(), IMAGEMANAGER->findImage("Slogra_Attack")->getFrameHeight());
	_ani.rightAttack->setPlayFrame(1, 6, false, true);
	_ani.rightAttack->setFPS(2);
	_ani.rightAttack->start();
	//¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á Attack2 (Carry)
	_ani.attack2 = new animation;
	_ani.attack2->init(IMAGEMANAGER->findImage("Slogra_Attack2")->getWidth(), IMAGEMANAGER->findImage("Slogra_Attack2")->getHeight(),
		IMAGEMANAGER->findImage("Slogra_Attack2")->getFrameWidth(), IMAGEMANAGER->findImage("Slogra_Attack2")->getFrameHeight());
	_ani.attack2->setPlayFrame(3, 4, false, true);
	_ani.attack2->setFPS(6);
	_ani.attack2->start();
	//¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á Attack3
	_ani.attack3 = new animation;
	_ani.attack3->init(IMAGEMANAGER->findImage("Slogra_Attack3")->getWidth(), IMAGEMANAGER->findImage("Slogra_Attack3")->getHeight(),
		IMAGEMANAGER->findImage("Slogra_Attack3")->getFrameWidth(), IMAGEMANAGER->findImage("Slogra_Attack3")->getFrameHeight());
	_ani.attack3->setPlayFrame(1, 2, false, false);
	_ani.attack3->setFPS(6);
	_ani.attack3->start();
	//¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á Monster Info Animation Init
	_monsterInfo.image = IMAGEMANAGER->findImage("Slogra_Move");
	_monsterInfo.ani = new animation;
	_monsterInfo.ani->init(IMAGEMANAGER->findImage("Slogra_Move")->getWidth(), IMAGEMANAGER->findImage("Slogra_Move")->getHeight(),
		IMAGEMANAGER->findImage("Slogra_Move")->getFrameWidth(), IMAGEMANAGER->findImage("Slogra_Move")->getFrameHeight());
	_monsterInfo.ani->setPlayFrame(6, 10, false, true);
	_monsterInfo.ani->setFPS(4);
	_monsterInfo.ani->start();
#pragma endregion 

	_count = 0;

	return S_OK;
}

void Boss_Slogra::update()
{
	Monster::update();

	SlograState();
	StateTest();
	attackCount();

	_monsterInfo.ani->frameUpdate(TIMEMANAGER->getElapsedTime() * 2.5f);

	_monsterInfo.rc = RectMakeCenter(_monsterInfo.x, _monsterInfo.y, _monsterInfo.width, _monsterInfo.height);
}

void Boss_Slogra::release()
{
}

void Boss_Slogra::render()
{
	Monster::render();

	_monsterInfo.image->aniRender(CAMERAMANAGER->getWorldDC(), _monsterInfo.x - 145, _monsterInfo.y - 113, _monsterInfo.ani);
}

void Boss_Slogra::SlograState()
{
	switch (_monsterInfo.state)
	{
	case IDLE_LEFT:
		
		_monsterInfo.image = IMAGEMANAGER->findImage("Slogra_Move");
		_monsterInfo.ani = _ani.leftIdle;

		break;
	case IDLE_RIGHT:
		
		_monsterInfo.image = IMAGEMANAGER->findImage("Slogra_Move");
		_monsterInfo.ani = _ani.rightIdle;

		break;
	case MOVE_LEFT:
		_monsterInfo.x -= _monsterInfo.speed;
		_monsterInfo.image = IMAGEMANAGER->findImage("Slogra_Move");
		_monsterInfo.ani = _ani.leftMove;

		break;
	case MOVE_RIGHT:
		_monsterInfo.x += _monsterInfo.speed;
		_monsterInfo.image = IMAGEMANAGER->findImage("Slogra_Move");
		_monsterInfo.ani = _ani.rightMove;

		break;
	case ATTACK_LEFT:
		_monsterInfo.image = IMAGEMANAGER->findImage("Slogra_Attack");
		_monsterInfo.ani = _ani.leftAttack;

		if (_monsterInfo.ani->getFramePos().x == 250)
		{
			_count++;

			if (_count > 12)
			{
				_attack->NormalMonsterAttack(_monsterInfo.x - 100, _monsterInfo.y - 30, 70, 40, 3);
				_count = 0;
			}
		}

		break;
	case ATTACK_RIGHT:
		_monsterInfo.image = IMAGEMANAGER->findImage("Slogra_Attack");
		_monsterInfo.ani = _ani.rightAttack;

		if (_monsterInfo.ani->getFramePos().x == 250)
		{
			_count++;

			if (_count > 12)
			{
				_attack->NormalMonsterAttack(_monsterInfo.x + 70, _monsterInfo.y - 30, 70, 40, 3);
				_count = 0;
			}
		}

		break;
	case ATTACK2_LEFT:
	case ATTACK2_RIGHT:

		_monsterInfo.image = IMAGEMANAGER->findImage("Slogra_Attack2");
		_monsterInfo.ani = _ani.attack2;

		break;
	case ATTACK3_LEFT:
	case ATTACK3_RIGHT:

		_monsterInfo.image = IMAGEMANAGER->findImage("Slogra_Attack3");
		_monsterInfo.ani = _ani.attack3;

		break;
	default:
		break;
	}
}

void Boss_Slogra::StateTest()
{

}

void Boss_Slogra::attackCount()
{

}
