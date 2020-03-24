#include "stdafx.h"
#include "Boss_Gargoyle.h"


Boss_Gargoyle::Boss_Gargoyle()
{
	IMAGEMANAGER->addFrameImage("Gargoyle_Idle", "Image/MonsterImage/Boss_01/Boss_01_Idle.bmp", 1680, 490, 7, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Gargoyle_Fire", "Image/MonsterImage/Boss_01/Boss_01_Fire.bmp", 1680, 490, 7, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Gargoyle_Ground", "Image/MonsterImage/Boss_01/Boss_01_Ground.bmp", 750, 500, 3, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Gargoyle_Ground_Fire", "Image/MonsterImage/Boss_01/Boss_01_Ground_Fire.bmp", 1250, 500, 5, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Gargoyle_Carry", "Image/MonsterImage/Boss_01/Boss_01_CarryOn.bmp", 1750, 500, 7, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Gargoyle_Death", "Image/MonsterImage/Boss_01/Boss_01_Death.bmp", 1750, 500, 7, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Gargoyle", "Image/MonsterImage/Boss_01/Gargoyle_init.bmp", 240, 245, 1, 1, true, RGB(255, 0, 255));
}


Boss_Gargoyle::~Boss_Gargoyle()
{
}

HRESULT Boss_Gargoyle::init(float x, float y, int monstertype, bool gravity)
{
	Monster::init();

	_monsterInfo.x = x;
	_monsterInfo.y = y;

	_monsterInfo.monsterType = (MonsterType)monstertype;

	_monsterInfo.activeGravity = gravity;
	_monsterInfo.gravity = 8.0f;
	_monsterInfo.speed = 5.0f;

	_monsterInfo.width = 65;
	_monsterInfo.height = 120;
	_monsterInfo.hp = 600;
	_monsterInfo.def = 10;
	_monsterInfo.damage = 15;

	_monsterInfo.state = IDLE_LEFT;

	_monsterInfo.rc = RectMakeCenter(_monsterInfo.x, _monsterInfo.y, _monsterInfo.width, _monsterInfo.height);

	_count = 0;
	_random = 0;

#pragma region ANIMATION
	//¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á Idle Left
	_ani.leftIdle = new animation;
	_ani.leftIdle->init(IMAGEMANAGER->findImage("Gargoyle_Idle")->getWidth(), IMAGEMANAGER->findImage("Gargoyle_Idle")->getHeight(),
		IMAGEMANAGER->findImage("Gargoyle_Idle")->getFrameWidth(), IMAGEMANAGER->findImage("Gargoyle_Idle")->getFrameHeight());
	_ani.leftIdle->setPlayFrame(8, 14, false, true);
	_ani.leftIdle->setFPS(5);
	_ani.leftIdle->start();
	//¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á Idle Right
	_ani.rightIdle = new animation;
	_ani.rightIdle->init(IMAGEMANAGER->findImage("Gargoyle_Idle")->getWidth(), IMAGEMANAGER->findImage("Gargoyle_Idle")->getHeight(),
		IMAGEMANAGER->findImage("Gargoyle_Idle")->getFrameWidth(), IMAGEMANAGER->findImage("Gargoyle_Idle")->getFrameHeight());
	_ani.rightIdle->setPlayFrame(1, 7, false, true);
	_ani.rightIdle->setFPS(5);
	_ani.rightIdle->start();
	//¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á Fire Left
	_ani.leftFire = new animation;
	_ani.leftFire->init(IMAGEMANAGER->findImage("Gargoyle_Fire")->getWidth(), IMAGEMANAGER->findImage("Gargoyle_Fire")->getHeight(),
		IMAGEMANAGER->findImage("Gargoyle_Fire")->getFrameWidth(), IMAGEMANAGER->findImage("Gargoyle_Fire")->getFrameHeight());
	_ani.leftFire->setPlayFrame(8, 14, false, true);
	_ani.leftFire->setFPS(4);
	_ani.leftFire->start();
	//¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á Fire Right
	_ani.rightFire = new animation;
	_ani.rightFire->init(IMAGEMANAGER->findImage("Gargoyle_Fire")->getWidth(), IMAGEMANAGER->findImage("Gargoyle_Fire")->getHeight(),
		IMAGEMANAGER->findImage("Gargoyle_Fire")->getFrameWidth(), IMAGEMANAGER->findImage("Gargoyle_Fire")->getFrameHeight());
	_ani.rightFire->setPlayFrame(1, 7, false, true);
	_ani.rightFire->setFPS(4);
	_ani.rightFire->start();
	//¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á On Ground Left
	_ani.leftGround = new animation;
	_ani.leftGround->init(IMAGEMANAGER->findImage("Gargoyle_Ground")->getWidth(), IMAGEMANAGER->findImage("Gargoyle_Ground")->getHeight(),
		IMAGEMANAGER->findImage("Gargoyle_Ground")->getFrameWidth(), IMAGEMANAGER->findImage("Gargoyle_Ground")->getFrameHeight());
	_ani.leftGround->setPlayFrame(4, 6, false, false);
	_ani.leftGround->setFPS(2);
	_ani.leftGround->start();
	//¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á On Ground Right
	_ani.rightGround = new animation;
	_ani.rightGround->init(IMAGEMANAGER->findImage("Gargoyle_Ground")->getWidth(), IMAGEMANAGER->findImage("Gargoyle_Ground")->getHeight(),
		IMAGEMANAGER->findImage("Gargoyle_Ground")->getFrameWidth(), IMAGEMANAGER->findImage("Gargoyle_Ground")->getFrameHeight());
	_ani.rightGround->setPlayFrame(1, 3, false, false);
	_ani.rightGround->setFPS(2);
	_ani.rightGround->start();
	//¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á Ground Fire Left
	_ani.leftGroundFire = new animation;
	_ani.leftGroundFire->init(IMAGEMANAGER->findImage("Gargoyle_Ground_Fire")->getWidth(), IMAGEMANAGER->findImage("Gargoyle_Ground_Fire")->getHeight(),
		IMAGEMANAGER->findImage("Gargoyle_Ground_Fire")->getFrameWidth(), IMAGEMANAGER->findImage("Gargoyle_Ground_Fire")->getFrameHeight());
	_ani.leftGroundFire->setPlayFrame(6, 10, false, true);
	_ani.leftGroundFire->setFPS(2);
	_ani.leftGroundFire->start();
	//¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á Ground Fire Right
	_ani.rightGroundFire = new animation;
	_ani.rightGroundFire->init(IMAGEMANAGER->findImage("Gargoyle_Ground_Fire")->getWidth(), IMAGEMANAGER->findImage("Gargoyle_Ground_Fire")->getHeight(),
		IMAGEMANAGER->findImage("Gargoyle_Ground_Fire")->getFrameWidth(), IMAGEMANAGER->findImage("Gargoyle_Ground_Fire")->getFrameHeight());
	_ani.rightGroundFire->setPlayFrame(1, 5, false, true);
	_ani.rightGroundFire->setFPS(2);
	_ani.rightGroundFire->start();
	//¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á Carry Left
	_ani.leftCarryOn = new animation;
	_ani.leftCarryOn->init(IMAGEMANAGER->findImage("Gargoyle_Carry")->getWidth(), IMAGEMANAGER->findImage("Gargoyle_Carry")->getHeight(),
		IMAGEMANAGER->findImage("Gargoyle_Carry")->getFrameWidth(), IMAGEMANAGER->findImage("Gargoyle_Carry")->getFrameHeight());
	_ani.leftCarryOn->setPlayFrame(8, 14, false, true);
	_ani.leftCarryOn->setFPS(3);
	_ani.leftCarryOn->start();
	//¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á Carry Right
	_ani.rightCarryOn = new animation;
	_ani.rightCarryOn->init(IMAGEMANAGER->findImage("Gargoyle_Carry")->getWidth(), IMAGEMANAGER->findImage("Gargoyle_Carry")->getHeight(),
		IMAGEMANAGER->findImage("Gargoyle_Carry")->getFrameWidth(), IMAGEMANAGER->findImage("Gargoyle_Carry")->getFrameHeight());
	_ani.rightCarryOn->setPlayFrame(1, 7, false, true);
	_ani.rightCarryOn->setFPS(3);
	_ani.rightCarryOn->start();
	//¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á Death
	_ani.death = new animation;
	_ani.death->init(IMAGEMANAGER->findImage("Gargoyle_Death")->getWidth(), IMAGEMANAGER->findImage("Gargoyle_Death")->getHeight(),
		IMAGEMANAGER->findImage("Gargoyle_Death")->getFrameWidth(), IMAGEMANAGER->findImage("Gargoyle_Death")->getFrameHeight());
	_ani.death->setPlayFrame(0, 7, false, false);
	_ani.death->setFPS(2);
	_ani.death->start();
	//¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á MonsterInfo Ani Init
	_monsterInfo.image = IMAGEMANAGER->findImage("Gargoyle");
	_monsterInfo.ani = new animation;
	_monsterInfo.ani->init(IMAGEMANAGER->findImage("Gargoyle_Idle")->getWidth(), IMAGEMANAGER->findImage("Gargoyle_Idle")->getHeight(),
		IMAGEMANAGER->findImage("Gargoyle_Idle")->getFrameWidth(), IMAGEMANAGER->findImage("Gargoyle_Idle")->getFrameHeight());
	_monsterInfo.ani->setPlayFrame(8, 14, false, true);
	_monsterInfo.ani->setFPS(5);
	_monsterInfo.ani->start();

#pragma endregion


	return S_OK;
}

void Boss_Gargoyle::update()
{
	Monster::update();

	GargoyleState();
	GargoyleBehavior();

	_monsterInfo.ani->frameUpdate(TIMEMANAGER->getElapsedTime() * 2.5f);

	_monsterInfo.rc = RectMakeCenter(_monsterInfo.x, _monsterInfo.y, _monsterInfo.width, _monsterInfo.height);
}

void Boss_Gargoyle::release()
{

}

void Boss_Gargoyle::render()
{
	Monster::render();

	_monsterInfo.image->aniRender(CAMERAMANAGER->getWorldDC(), _monsterInfo.rc.left - 100, _monsterInfo.rc.top - 127, _monsterInfo.ani);
}

void Boss_Gargoyle::GargoyleState()
{
	switch (_monsterInfo.state)
	{
	case IDLE_LEFT:
		_monsterInfo.image = IMAGEMANAGER->findImage("Gargoyle_Idle");
		_monsterInfo.ani = _ani.leftIdle;
		break;

	case IDLE_RIGHT:
		_monsterInfo.image = IMAGEMANAGER->findImage("Gargoyle_Idle");
		_monsterInfo.ani = _ani.rightIdle;
		break;

	case ATTACK_LEFT:
		_monsterInfo.image = IMAGEMANAGER->findImage("Gargoyle_Fire");
		_monsterInfo.ani = _ani.leftFire;
		break;

	case ATTACK_RIGHT:
		_monsterInfo.image = IMAGEMANAGER->findImage("Gargoyle_Fire");
		_monsterInfo.ani = _ani.rightFire;
		break;

	case MOVE_LEFT:
		//¶¥¿¡ ÂøÁöÇÑ »óÅÂ. (ÁÂ)
		_monsterInfo.image = IMAGEMANAGER->findImage("Gargoyle_Ground");
		_monsterInfo.ani = _ani.leftGround;
		break;

	case MOVE_RIGHT:
		//¶¥¿¡ ÂøÁöÇÑ »óÅÂ. (¿ì)
		_monsterInfo.image = IMAGEMANAGER->findImage("Gargoyle_Ground");
		_monsterInfo.ani = _ani.rightGround;
		break;

	case ATTACK2_LEFT:
		_monsterInfo.image = IMAGEMANAGER->findImage("Gargoyle_Ground_Fire");
		_monsterInfo.ani = _ani.leftGroundFire;
		break;

	case ATTACK2_RIGHT:
		_monsterInfo.image = IMAGEMANAGER->findImage("Gargoyle_Ground_Fire");
		_monsterInfo.ani = _ani.rightGroundFire;
		break;

	case ATTACK3_LEFT:
		_monsterInfo.image = IMAGEMANAGER->findImage("Gargoyle_Carry");
		_monsterInfo.ani = _ani.leftCarryOn;
		break;

	case ATTACK3_RIGHT:
		_monsterInfo.image = IMAGEMANAGER->findImage("Gargoyle_Carry");
		_monsterInfo.ani = _ani.rightCarryOn;
		break;

	case DEATH:
		_monsterInfo.image = IMAGEMANAGER->findImage("Gargoyle_Death");
		_monsterInfo.ani = _ani.death;
		break;

	default:
		break;
	}
}

void Boss_Gargoyle::GargoyleBehavior()
{

}
