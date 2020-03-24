#include "stdafx.h"
#include "Monster_Armored_Knight.h"


Monster_Armored_Knight::Monster_Armored_Knight()
{
	
}

Monster_Armored_Knight::~Monster_Armored_Knight()
{
}

HRESULT Monster_Armored_Knight::init(float posx, float posy, int monstertype, bool gravityActive)
{
	Monster::init();

	_monsterInfo.x =			 posx;
	_monsterInfo.y =			 posy;
	_monsterInfo.activeGravity = gravityActive;

	_monsterInfo.gravity =	KNIGHTGEAVITY;
	_monsterInfo.width   =	KNIGHTWIDTH;
	_monsterInfo.height  =	KNIGHTHEIGHT;

	_monsterInfo.state = MOVE_LEFT;
	_monsterInfo.monsterType = (MonsterType)monstertype;
	_monsterInfo.hp = 100;
	_monsterInfo.damage = 25;
	_monsterInfo.def = 5;

	_moveImage    =	IMAGEMANAGER->addFrameImage("Armored_Move", "Image/MonsterImage/ArmoredKnight/State_Move.bmp", 960, 576, 8, 2, true, RGB(255, 0, 255));
	_attackImage  =	IMAGEMANAGER->addFrameImage("Armored_Attack_01", "Image/MonsterImage/ArmoredKnight/State_Attack_01_개선.bmp", 3993, 584, 11, 2, true, RGB(255, 0, 255));
	_attack2Image = IMAGEMANAGER->addFrameImage("Armored_Attack_02", "Image/MonsterImage/ArmoredKnight/State_Attack_02_개선.bmp", 4650, 594, 10, 2, true, RGB(255, 0, 255));
	_attack3Image =	IMAGEMANAGER->addFrameImage("Armored_Attack_03", "Image/MonsterImage/ArmoredKnight/State_Attack_03_개선.bmp", 5300, 485, 11, 2, true, RGB(255, 0, 255));
	_deathImage   =	IMAGEMANAGER->addFrameImage("Armored_Death", "Image/MonsterImage/ArmoredKnight/State_Death.bmp", 423, 399, 2, 2, true, RGB(255, 0, 255));

	_monsterInfo.image = IMAGEMANAGER->findImage("Armored_Move");

	_monsterInfo.rc = RectMakeCenter(_monsterInfo.x, _monsterInfo.y, _monsterInfo.width, _monsterInfo.height);

	_moveFrameX    = _moveFrameY	= _frameCount = 0;
	_deathFrameX   = _deathFrameY	= 0;
	_attackFrameX  = _attackFrameY	= 0;
	_attack2FrameX = _attack2FrameY = 0;
	_attack3FrameX = _attack3FrameY = 0;

	_beCount = 0;
	_stabCount = 0;

	_coolDown = false;

	return S_OK;
}

void Monster_Armored_Knight::update()
{
	Monster::update();

	ArmoredKnightState();
	ArmoredKnightBehavior();

	_monsterInfo.rc = RectMakeCenter(_monsterInfo.x, _monsterInfo.y, _monsterInfo.width, _monsterInfo.height);
}

void Monster_Armored_Knight::release()
{
}

void Monster_Armored_Knight::render()
{
	Monster::render();

	switch (_monsterInfo.state)
	{
	case MOVE_LEFT:
	case MOVE_RIGHT:
		_moveImage->frameRender(CAMERAMANAGER->getWorldDC(), _monsterInfo.rc.left - 20, _monsterInfo.rc.top - 90, _moveFrameX, _moveFrameY);
		break;
	case ATTACK_LEFT:
		_attackImage->frameRender(CAMERAMANAGER->getWorldDC(), _monsterInfo.rc.left - 200, _monsterInfo.rc.top - 90, _attackFrameX, _attackFrameY);
		break;
	case ATTACK_RIGHT:
		_attackImage->frameRender(CAMERAMANAGER->getWorldDC(), _monsterInfo.rc.left - 75, _monsterInfo.rc.top - 90, _attackFrameX, _attackFrameY);
		break;
	case ATTACK2_LEFT:
		_attack2Image->frameRender(CAMERAMANAGER->getWorldDC(), _monsterInfo.rc.left - 170, _monsterInfo.rc.top - 100, _attack2FrameX, _attack2FrameY);
		break;
	case ATTACK2_RIGHT:
		_attack2Image->frameRender(CAMERAMANAGER->getWorldDC(), _monsterInfo.rc.left - 170, _monsterInfo.rc.top - 100, _attack2FrameX, _attack2FrameY);
		break;
	case ATTACK3_LEFT:
		_attack3Image->frameRender(CAMERAMANAGER->getWorldDC(), _monsterInfo.rc.left - 195, _monsterInfo.rc.top - 42, _attack3FrameX, _attack3FrameY);
		break;
	case ATTACK3_RIGHT:
		_attack3Image->frameRender(CAMERAMANAGER->getWorldDC(), _monsterInfo.rc.left - 195, _monsterInfo.rc.top - 42, _attack3FrameX, _attack3FrameY);
		break;
	case DEATH:
		_deathImage->frameRender(CAMERAMANAGER->getWorldDC(), _monsterInfo.rc.left - 30, _monsterInfo.rc.top, _deathFrameX, _deathFrameY);
		break;
	default:
		break;
	}
}

void Monster_Armored_Knight::ArmoredKnightState()
{
	switch (_monsterInfo.state)
	{
	case MOVE_LEFT:

		leftMoveFrame();
		AttackRectMakeTest();
		_monsterInfo.x -= KNIGHTSPEED;
		break;
	case MOVE_RIGHT:

		rightMoveFrame();
		AttackRectMakeTest();
		_monsterInfo.x += KNIGHTSPEED;
		break;
	case ATTACK_LEFT:

		LeftAttackFrame();
		AttackRectMakeTest();
		break;
	case ATTACK_RIGHT:

		RightAttackFrame();
		AttackRectMakeTest();
		break;
	case ATTACK2_LEFT:

		LeftAttack2Frame();
		AttackRectMakeTest();
		break;
	case ATTACK2_RIGHT:

		RightAttack2Frame();
		AttackRectMakeTest();
		break;
	case ATTACK3_LEFT:

		LeftAttack3Frame();
		AttackRectMakeTest();
		break;
	case ATTACK3_RIGHT:

		RightAttack3Frame();
		AttackRectMakeTest();
		break;
	case DEATH:
		DeathFrame();
		break;
	default:
		break;
	}

	_frameCount++;
}

void Monster_Armored_Knight::ArmoredKnightBehavior()
{
	if (_monsterInfo.behavior == MOVING)
	{
		if (_beCount > 400) _beCount = 0;

		_beCount++;

		if (_beCount <= 200)
		{
			_monsterInfo.state = MOVE_RIGHT;
		}
		else if (_beCount > 200 && _beCount <= 400)
		{
			_monsterInfo.state = MOVE_LEFT;
		}
	}
	else if (_monsterInfo.behavior == ATTACKING_LEFT)
		//좌측 하단베기 후 상단베기 공격행동.
	{
		if (_beCount > 130) _beCount = 0;

		_beCount++;
	
		if (_beCount <= 60)
		{
			_monsterInfo.state = ATTACK2_LEFT;
		}
		else if (_beCount > 60 && _beCount <= 130)
		{
			_monsterInfo.state = ATTACK3_LEFT;
		}
	}
	else if (_monsterInfo.behavior == ATTACKING_RIGHT)
	{
		if (_beCount > 130) _beCount = 0;

		_beCount++;
	
		if (_beCount <= 60)
		{
			_monsterInfo.state = ATTACK2_RIGHT;
		}
		else if (_beCount > 60 && _beCount <= 130)
		{
			_monsterInfo.state = ATTACK3_RIGHT;
		}
	}
	else if (_monsterInfo.behavior == KNIGHT_LEFT_STAB)
		//갑옥기사의 쿨타임이 false 일떄만 발동되고
	{
		_stabCount++;

		if (_stabCount <= 65)
		{
			_monsterInfo.state = ATTACK_LEFT;
		}
		if (_stabCount > 65)

		{
			_coolDown = true;
			_stabCount = 0;
			_attackFrameX = 5;
		}
	}
	else if (_monsterInfo.behavior == KNIGHT_RIGHT_STAB)
	{
		_stabCount++;

		if (_stabCount <= 65)
		{
			_monsterInfo.state = ATTACK_RIGHT;
		}
		if (_stabCount > 65)
		{
			_coolDown = true;
			_stabCount = 0;
			_attackFrameX = 6;
		}
	}

	if(_monsterInfo.behavior != KNIGHT_RIGHT_STAB && _monsterInfo.behavior != KNIGHT_LEFT_STAB)
	{
		_stabCount = 0;
	}
}

void Monster_Armored_Knight::AttackRectMakeTest()
{
	//Attack State 중일때 특정 프레임 구간에서만 isAttack 활성화 해주기.
	//■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
	//■■■■■■■■■■■■■■■■ATTACK 1 찌르기 공격■■■■■■■■■■■■■■■
	if (_monsterInfo.state == ATTACK_LEFT || _monsterInfo.state == ATTACK_RIGHT)
	{
		if (_monsterInfo.state == ATTACK_LEFT)
		{
			if (_monsterInfo.image->getFrameX() > 2 && _monsterInfo.image->getFrameX() < 5)
			{
				//_monsterInfo.attackCheck.isAttack = true;
				//찌르기 공격 대쉬.
				if (_frameCount % 5 == 0)
				{
					_attack->NormalMonsterAttack(_monsterInfo.x - 100, _monsterInfo.y - 15, 140, 40, 10);
				}
				_monsterInfo.x -= KNIGHTATTACKSPEED;
			}
			else
			{
				_monsterInfo.attackCheck.isAttack = false;
			}
		}
		else if (_monsterInfo.state == ATTACK_RIGHT)
		{
			if (_monsterInfo.image->getFrameX() > 5 && _monsterInfo.image->getFrameX() < 8)
			{
				//_monsterInfo.attackCheck.isAttack = true;
				if (_frameCount % 5 == 0)
				{
					_attack->NormalMonsterAttack(_monsterInfo.x + 100, _monsterInfo.y - 15, 140, 40, 10);
				}
				_monsterInfo.x += KNIGHTATTACKSPEED;
			}
			else
			{
				_monsterInfo.attackCheck.isAttack = false;
			}
		}
	}
	//■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
	//■■■■■■■■■■■■■■■■ATTACK 2 내려찍기 공격■■■■■■■■■■■■■■■
	if (_monsterInfo.state == ATTACK2_LEFT || _monsterInfo.state == ATTACK2_RIGHT)
	{
		if (_monsterInfo.state == ATTACK2_LEFT)
		{
			if (_monsterInfo.image->getFrameX() > 1 && _monsterInfo.image->getFrameX() < 6)
			{
				//_monsterInfo.attackCheck.isAttack = true;

				if (_frameCount == 3)
				{
					_attack->NormalMonsterAttack(_monsterInfo.x - 120, _monsterInfo.y - 25, 75, 75, 8);
				}
			}
			else
			{
				_monsterInfo.attackCheck.isAttack = false;
			}
		}
		else if (_monsterInfo.state == ATTACK2_RIGHT)
		{
			if (_monsterInfo.image->getFrameX() > 3 && _monsterInfo.image->getFrameX() < 8)
			{

				if (_frameCount == 3)
				{
					_attack->NormalMonsterAttack(_monsterInfo.x + 170, _monsterInfo.y - 25, 75, 75, 8);
				}
			}
			else
			{
				_monsterInfo.attackCheck.isAttack = false;
			}
		}
	}
	if (_monsterInfo.state == ATTACK3_LEFT || _monsterInfo.state == ATTACK3_RIGHT)
	{
		if (_monsterInfo.state == ATTACK3_LEFT)
		{
			if (_monsterInfo.image->getFrameX() > 2 && _monsterInfo.image->getFrameX() < 7)
			{
				_monsterInfo.attackCheck.isAttack = true;
			}
			else
			{
				_monsterInfo.attackCheck.isAttack = false;
			}
		}
		else if (_monsterInfo.state == ATTACK3_RIGHT)
		{
			if (_monsterInfo.image->getFrameX() > 3 && _monsterInfo.image->getFrameX() < 8)
			{
				_monsterInfo.attackCheck.isAttack = true;
			}
			else
			{
				_monsterInfo.attackCheck.isAttack = false;
			}
		}
	}
	if (_monsterInfo.state == MOVE_LEFT || _monsterInfo.state == MOVE_RIGHT)
	{
		_monsterInfo.attackCheck.isAttack = false;
	}
	//■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
	//isAttack 활성화 상태일때 Attack Rect 그려주기.
	if (_monsterInfo.attackCheck.isAttack)
	{
		if (!_monsterInfo.attackCheck.isAttack) return;

		//ATTACK 1 상태일때 모션 사이즈에 맞는 공격렉트 사이즈 생성 (검신의 길이)
		if (_monsterInfo.state == ATTACK_LEFT || _monsterInfo.state == ATTACK_RIGHT)
		{
			//공격렉트 사이즈 설정.
			_monsterInfo.attackCheck.width	= 140;
			_monsterInfo.attackCheck.height = 40;

			if (_monsterInfo.state == ATTACK_LEFT)
			{
				_monsterInfo.attackCheck.x = _monsterInfo.x - 90;
				_monsterInfo.attackCheck.y = _monsterInfo.y - 15;

				_monsterInfo.attackCheck.rc = RectMakeCenter(_monsterInfo.attackCheck.x, _monsterInfo.attackCheck.y,
					_monsterInfo.attackCheck.width, _monsterInfo.attackCheck.height);

			}
			else if (_monsterInfo.state == ATTACK_RIGHT)
			{
				_monsterInfo.attackCheck.x = _monsterInfo.x + 90;
				_monsterInfo.attackCheck.y = _monsterInfo.y - 15;

				_monsterInfo.attackCheck.rc = RectMakeCenter(_monsterInfo.attackCheck.x, _monsterInfo.attackCheck.y,
					_monsterInfo.attackCheck.width, _monsterInfo.attackCheck.height);
			}
		}
		if(_monsterInfo.state == ATTACK2_LEFT || _monsterInfo.state == ATTACK2_RIGHT)
		{
			//공격렉트 사이즈 설정.
			_monsterInfo.attackCheck.width	= 200;
			_monsterInfo.attackCheck.height = 200;

			if (_monsterInfo.state == ATTACK2_LEFT)
			{
				_monsterInfo.attackCheck.x = _monsterInfo.x - 70;
				_monsterInfo.attackCheck.y = _monsterInfo.y - 70;

				_monsterInfo.attackCheck.rc = RectMakeCenter(_monsterInfo.attackCheck.x, _monsterInfo.attackCheck.y,
					_monsterInfo.attackCheck.width, _monsterInfo.attackCheck.height);
			}
			else if (_monsterInfo.state == ATTACK2_RIGHT)
			{
				_monsterInfo.attackCheck.x = _monsterInfo.x + 200;
				_monsterInfo.attackCheck.y = _monsterInfo.y - 70;

				_monsterInfo.attackCheck.rc = RectMakeCenter(_monsterInfo.attackCheck.x, _monsterInfo.attackCheck.y,
					_monsterInfo.attackCheck.width, _monsterInfo.attackCheck.height);
			}
		}
		if (_monsterInfo.state == ATTACK3_LEFT || _monsterInfo.state == ATTACK3_RIGHT)
		{
			_monsterInfo.attackCheck.width = 160;
			_monsterInfo.attackCheck.height = 160;

			if (_monsterInfo.state == ATTACK3_LEFT)
			{
				_monsterInfo.attackCheck.x = _monsterInfo.x - 130;
				_monsterInfo.attackCheck.y = _monsterInfo.y - 70;

				_monsterInfo.attackCheck.rc = RectMakeCenter(_monsterInfo.attackCheck.x, _monsterInfo.attackCheck.y,
					_monsterInfo.attackCheck.width, _monsterInfo.attackCheck.height);
			}
			else if (_monsterInfo.state == ATTACK3_RIGHT)
			{
				_monsterInfo.attackCheck.x = _monsterInfo.x + 130;
				_monsterInfo.attackCheck.y = _monsterInfo.y - 70;

				_monsterInfo.attackCheck.rc = RectMakeCenter(_monsterInfo.attackCheck.x, _monsterInfo.attackCheck.y,
					_monsterInfo.attackCheck.width, _monsterInfo.attackCheck.height);
			}
		}
	}
	if(!_monsterInfo.attackCheck.isAttack)
	{
		//isAttack 활성화 되지 않았다면 Rect 지워주기.(안보이게 하기) (추후에 Vector에 담아서 사용하는 방식으로 바꾸어야합니다)
		_monsterInfo.attackCheck.rc = RectMakeCenter(_monsterInfo.x, _monsterInfo.y, 0, 0);
	}
}

void Monster_Armored_Knight::leftMoveFrame()
{
	_monsterInfo.image = IMAGEMANAGER->findImage("Armored_Move");

	_moveFrameY = 1;
	if (_frameCount % 16 == 0)
	{
		_moveFrameX--;
		if (_moveFrameX < 0)
			_moveFrameX = _monsterInfo.image->getMaxFrameX();

		_frameCount = 0;
	}
}

void Monster_Armored_Knight::rightMoveFrame()
{
	_monsterInfo.image = IMAGEMANAGER->findImage("Armored_Move");
	
	_moveFrameY = 0;

	if (_frameCount % 16 == 0)
	{
		_moveFrameX++;
		if (_moveFrameX > _monsterInfo.image->getMaxFrameX())
		{
			_moveFrameX = 0;
		}
		_frameCount = 0;
	}
}

void Monster_Armored_Knight::LeftAttackFrame()
{
	_monsterInfo.image = IMAGEMANAGER->findImage("Armored_Attack_01");

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

void Monster_Armored_Knight::RightAttackFrame()
{
	_monsterInfo.image = IMAGEMANAGER->findImage("Armored_Attack_01");

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

void Monster_Armored_Knight::LeftAttack2Frame()
{
	_monsterInfo.image = IMAGEMANAGER->findImage("Armored_Attack_02");
	
	_attack2FrameY = 1;
	
	if (_frameCount % 6 == 0)
	{
		_attack2FrameX--;
	
		if (_attack2FrameX < 0)
		{
			_attack2FrameX = _monsterInfo.image->getMaxFrameX();
		}
	
		_frameCount = 0;
	}
}

void Monster_Armored_Knight::RightAttack2Frame()
{
	_monsterInfo.image = IMAGEMANAGER->findImage("Armored_Attack_02");

	_attack2FrameY = 0;

	if (_frameCount % 6 == 0)
	{
		_attack2FrameX++;

		if (_attack2FrameX > _monsterInfo.image->getMaxFrameX())
		{
			_attack2FrameX = 0;
		}

		_frameCount = 0;
	}
}

void Monster_Armored_Knight::LeftAttack3Frame()
{
	_monsterInfo.image = IMAGEMANAGER->findImage("Armored_Attack_03");

	_attack3FrameY = 1;

	if (_frameCount % 6 == 0)
	{
		_attack3FrameX--;

		if (_attack3FrameX < 0)
		{
			_attack3FrameX = _monsterInfo.image->getMaxFrameX();
		}
		_frameCount = 0;
	}
}

void Monster_Armored_Knight::RightAttack3Frame()
{
	_monsterInfo.image = IMAGEMANAGER->findImage("Armored_Attack_03");

	_attack3FrameY = 0;

	if (_frameCount % 6 == 0)
	{
		_attack3FrameX++;

		if (_attack3FrameX > _monsterInfo.image->getMaxFrameX())
		{
			_attack3FrameX = 0;
		}
		
		_frameCount = 0;
	}
}

void Monster_Armored_Knight::DeathFrame()
{
	_monsterInfo.image = IMAGEMANAGER->findImage("Armored_Death");

	_deathFrameY = 0;

	if (_frameCount % 24 == 0)
	{
		_deathFrameX++;

		if (_deathFrameX > _monsterInfo.image->getMaxFrameX())
		{
			_deathFrameX = 0;
		}

		_frameCount = 0;
	}
}
