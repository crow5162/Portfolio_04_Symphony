#include "stdafx.h"
#include "Boss_Death.h"


Boss_Death::Boss_Death()
{
}


Boss_Death::~Boss_Death()
{
}

HRESULT Boss_Death::init(float x, float y, int monstertype, bool gravity)
{
	Monster::init();

	_monsterInfo.x = x;
	_monsterInfo.y = y;
	_monsterInfo.activeGravity = gravity;
	_monsterInfo.monsterType = (MonsterType)monstertype;

	_monsterInfo.width = DEATHWIDTH;
	_monsterInfo.height = DEATHHEIGHT;

	_monsterInfo.speed = 5.0f;
	_monsterInfo.hp = 500;
	_monsterInfo.def = 10;

	_monsterInfo.damage = 10;
	_monsterInfo.state = IDLE_LEFT;

	_monsterInfo.rc = RectMakeCenter(_monsterInfo.x, _monsterInfo.y, _monsterInfo.width, _monsterInfo.height);

#pragma region ANIMATION
	IMAGEMANAGER->addFrameImage("Death_Idle", "Image/MonsterImage/Death_Boss/State_Idle.bmp", 2180, 476, 10, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Death_Attack", "Image/MonsterImage/Death_Boss/State_Attack.bmp", 1308, 466, 6, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Death_Attack2", "Image/MonsterImage/Death_Boss/State_Attack2.bmp", 2829, 465, 13, 2, true, RGB(255, 0, 255));


	//¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á Idle Right
	_ani.rightIdle = new animation;
	_ani.rightIdle->init(IMAGEMANAGER->findImage("Death_Idle")->getWidth(), IMAGEMANAGER->findImage("Death_Idle")->getHeight(),
		IMAGEMANAGER->findImage("Death_Idle")->getFrameWidth(), IMAGEMANAGER->findImage("Death_Idle")->getFrameHeight());
	_ani.rightIdle->setPlayFrame(0, 5, false, true);
	_ani.rightIdle->setFPS(3);
	_ani.rightIdle->start();
	//¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á Idle Left
	_ani.leftIdle = new animation;
	_ani.leftIdle->init(IMAGEMANAGER->findImage("Death_Idle")->getWidth(), IMAGEMANAGER->findImage("Death_Idle")->getHeight(),
		IMAGEMANAGER->findImage("Death_Idle")->getFrameWidth(), IMAGEMANAGER->findImage("Death_Idle")->getFrameHeight());
	_ani.leftIdle->setPlayFrame(10, 15, false, true);
	_ani.leftIdle->setFPS(3);
	_ani.leftIdle->start();
	//¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á Attack Right
	_ani.rightAttack = new animation;
	_ani.rightAttack->init(IMAGEMANAGER->findImage("Death_Attack")->getWidth(), IMAGEMANAGER->findImage("Death_Attack")->getHeight(),
		IMAGEMANAGER->findImage("Death_Attack")->getFrameWidth(), IMAGEMANAGER->findImage("Death_Attack")->getFrameHeight());
	_ani.rightAttack->setPlayFrame(0, 6, false, true);
	_ani.rightAttack->setFPS(3);
	_ani.rightAttack->start();
	//¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á Attack Right
	_ani.leftAttack = new animation;
	_ani.leftAttack->init(IMAGEMANAGER->findImage("Death_Attack")->getWidth(), IMAGEMANAGER->findImage("Death_Attack")->getHeight(),
		IMAGEMANAGER->findImage("Death_Attack")->getFrameWidth(), IMAGEMANAGER->findImage("Death_Attack")->getFrameHeight());
	_ani.leftAttack->setPlayFrame(7, 12, false, true);
	_ani.leftAttack->setFPS(3);
	_ani.leftAttack->start();
	//¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á Attack2 Right
	_ani.rightAttack2 = new animation;
	_ani.rightAttack2->init(IMAGEMANAGER->findImage("Death_Attack2")->getWidth(), IMAGEMANAGER->findImage("Death_Attack2")->getHeight(),
		IMAGEMANAGER->findImage("Death_Attack2")->getFrameWidth(), IMAGEMANAGER->findImage("Death_Attack2")->getFrameHeight());
	_ani.rightAttack2->setPlayFrame(0, 12, false, true);
	_ani.rightAttack2->setFPS(3);
	_ani.rightAttack2->start();
	//¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á Attack2 Left
	_ani.leftAttack2 = new animation;
	_ani.leftAttack2->init(IMAGEMANAGER->findImage("Death_Attack2")->getWidth(), IMAGEMANAGER->findImage("Death_Attack2")->getHeight(),
		IMAGEMANAGER->findImage("Death_Attack2")->getFrameWidth(), IMAGEMANAGER->findImage("Death_Attack2")->getFrameHeight());
	_ani.leftAttack2->setPlayFrame(13, 25, false, true);
	_ani.leftAttack2->setFPS(3);
	_ani.leftAttack2->start();
	//¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á Attack3 Right
	_ani.rightAttack3 = new animation;
	_ani.rightAttack3->init(IMAGEMANAGER->findImage("Death_Idle")->getWidth(), IMAGEMANAGER->findImage("Death_Idle")->getHeight(),
		IMAGEMANAGER->findImage("Death_Idle")->getFrameWidth(), IMAGEMANAGER->findImage("Death_Idle")->getFrameHeight());
	_ani.rightAttack3->setPlayFrame(7, 10, false, true);
	_ani.rightAttack3->setFPS(3);
	_ani.rightAttack3->start();
	//¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á Attack3 Left
	_ani.leftAttack3 = new animation; 
	_ani.leftAttack3->init(IMAGEMANAGER->findImage("Death_Idle")->getWidth(), IMAGEMANAGER->findImage("Death_Idle")->getHeight(),
		IMAGEMANAGER->findImage("Death_Idle")->getFrameWidth(), IMAGEMANAGER->findImage("Death_Idle")->getFrameHeight());
	_ani.leftAttack3->setPlayFrame(17, 20, false, true);
	_ani.leftAttack3->setFPS(3);
	_ani.leftAttack3->start();
	//¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á MonsterInfo Ani Init
	_monsterInfo.image = IMAGEMANAGER->findImage("Death_Idle");
	_monsterInfo.ani = new animation;
	_monsterInfo.ani->init(IMAGEMANAGER->findImage("Death_Idle")->getWidth(), IMAGEMANAGER->findImage("Death_Idle")->getHeight(),
		IMAGEMANAGER->findImage("Death_Idle")->getFrameWidth(), IMAGEMANAGER->findImage("Death_Idle")->getFrameHeight());
	_monsterInfo.ani->setPlayFrame(1, 10, false, true);
	_monsterInfo.ani->setFPS(5);
	_monsterInfo.ani->start();
#pragma endregion

	_count = 0;

	return S_OK;
}

void Boss_Death::update()
{
	Monster::update();

	_monsterInfo.ani->frameUpdate(TIMEMANAGER->getElapsedTime() * 2.5f );

	DeathState();
	DeathBehavior();

	_monsterInfo.rc = RectMakeCenter(_monsterInfo.x, _monsterInfo.y, _monsterInfo.width, _monsterInfo.height);
}

void Boss_Death::release()
{
}

void Boss_Death::render()
{
	Monster::render();

	_monsterInfo.image->aniRender(CAMERAMANAGER->getWorldDC(), _monsterInfo.x - 110, _monsterInfo.y - 110, _monsterInfo.ani);
}

void Boss_Death::DeathState()
{
	switch (_monsterInfo.state)
	{
	case IDLE_RIGHT:
		_monsterInfo.image = IMAGEMANAGER->findImage("Death_Idle");
		_monsterInfo.ani = _ani.rightIdle;

		break;

	case IDLE_LEFT:
		_monsterInfo.image = IMAGEMANAGER->findImage("Death_Idle");
		_monsterInfo.ani = _ani.leftIdle;

		break;

	case ATTACK_RIGHT:
		_monsterInfo.image = IMAGEMANAGER->findImage("Death_Attack");
		_monsterInfo.ani = _ani.rightAttack;

		break;

	case ATTACK_LEFT:
		_monsterInfo.image = IMAGEMANAGER->findImage("Death_Attack");
		_monsterInfo.ani = _ani.leftAttack;


		break;

	case ATTACK2_RIGHT:
		_monsterInfo.image = IMAGEMANAGER->findImage("Death_Attack2");
		_monsterInfo.ani = _ani.rightAttack2;

		break;

	case ATTACK2_LEFT:
		_monsterInfo.image = IMAGEMANAGER->findImage("Death_Attack2");
		_monsterInfo.ani = _ani.leftAttack2;

		break;

	case ATTACK3_RIGHT:
		_monsterInfo.image = IMAGEMANAGER->findImage("Death_Idle");
		_monsterInfo.ani = _ani.rightAttack3;

		break;

	case ATTACK3_LEFT:
		_monsterInfo.image = IMAGEMANAGER->findImage("Death_Idle");
		_monsterInfo.ani = _ani.leftAttack3;

		break;
	default:
		break;
	}
}

void Boss_Death::DeathBehavior()
{

}
