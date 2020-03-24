#include "stdafx.h"
#include "Alucard.h"

Alucard::Alucard()
{

}

Alucard::~Alucard()
{
}

HRESULT Alucard::init()
{

#pragma region IMAGE
	//Character IMAGE
	IMAGEMANAGER->addFrameImage("Alucard_Idle_Image", "Image/AlucardImage/State_Idle.bmp", 5700, 600, 19, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Alucard_Start_Move_Image", "Image/AlucardImage/State_Move_01.bmp", 4500, 600, 15, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Alucard_Move_Image", "Image/AlucardImage/State_Move_02.bmp", 4800, 600, 16, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Alucard_Jump_Image", "Image/AlucardImage/State_Jump.bmp", 3000, 600, 10, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Alucard_Double_Jump_Image", "Image/AlucardImage/State_Double_Jump.bmp", 1500, 600, 5, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Alucard_Back_Dash_Image", "Image/AlucardImage/State_Backdash.bmp", 3900, 600, 13, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Alucard_Attack_Image", "Image/AlucardImage/State_Attack_02.bmp", 3300, 600, 11, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Alucard_Attack_Image_02", "Image/AlucardImage/State_Attack_01.bmp", 3300, 600, 11, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Alucard_Ducking_Image", "Image/AlucardImage/State_Ducking.bmp", 5100, 600, 17, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Alucard_Ducking_Attack_Image", "Image/AlucardImage/State_Ducking_Attack_01.bmp", 3600, 600, 12, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Alucard_Ducking_Attack_Image_02", "Image/AlucardImage/State_Ducking_Attack_02.bmp", 3600, 600, 12, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Alucard_Attack_InAir_Image", "Image/AlucardImage/State_Attack_Air.bmp", 1200, 600, 4, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Alucard_inAir_Attack", "Image/AlucardImage/State_AttackInAir_02.bmp", 1200, 600, 4, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Alucard_inAir_Attack_02", "Image/AlucardImage/State_AttackInAir_01.bmp", 1200, 600, 4, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Alucard_Hit_Image", "Image/AlucardImage/State_Heart.bmp", 3900, 600, 13, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Alucard_Skill_Image", "Image/AlucardImage/State_HellFire.bmp", 3600, 600, 12, 2, true, RGB(255, 0, 255));
	//Attack Image
	IMAGEMANAGER->addFrameImage("Attack_type_01", "Image/AlucardImage/AttackImage/Attack_01.bmp", 700, 89, 4, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Attack_type_02", "Image/AlucardImage/AttackImage/Attack_02.bmp", 700, 96, 4, 2, true, RGB(255, 0, 255));

	//Character ANIMATION
	KEYANIMANAGER->addCoordinateFrameAnimation("Idle_Right", "Alucard_Idle_Image", 0, 7, 7, false, true);
	KEYANIMANAGER->addCoordinateFrameAnimation("Idle_Left",  "Alucard_Idle_Image", 19, 25, 7, false, true);
	KEYANIMANAGER->addCoordinateFrameAnimation("Move_Right", "Alucard_Move_Image", 0, 15, 24, false, true);
	KEYANIMANAGER->addCoordinateFrameAnimation("Move_Left",  "Alucard_Move_Image", 16, 31, 24, false, true);
	KEYANIMANAGER->addCoordinateFrameAnimation("Move_Start_Right", "Alucard_Start_Move_Image", 0, 14, 18, false, true);
	KEYANIMANAGER->addCoordinateFrameAnimation("Move_Start_Left", "Alucard_Start_Move_Image", 15, 29, 18, false, true);
	KEYANIMANAGER->addCoordinateFrameAnimation("Jump_Right", "Alucard_Jump_Image", 0, 9, 14, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("Jump_Left", "Alucard_Jump_Image", 10, 19, 14, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("Jump_Right_Key", "Alucard_Jump_Image", 7, 9, 6, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("Jump_Left_Key", "Alucard_Jump_Image", 17, 19, 6, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("DJump_Left", "Alucard_Double_Jump_Image", 5, 9, 12, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("DJump_Right", "Alucard_Double_Jump_Image", 0, 4, 12, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("BackDash_Left", "Alucard_Back_Dash_Image", 0, 12, 23, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("BackDash_Right", "Alucard_Back_Dash_Image", 13, 25, 23, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("Attack_Right", "Alucard_Attack_Image", 0, 10, 18, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("Attack_Left", "Alucard_Attack_Image", 11, 21, 18, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("Attack2_Right", "Alucard_Attack_Image_02", 0, 10, 18, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("Attack2_Left", "Alucard_Attack_Image_02", 11, 21, 18, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("Attack_Air_Right", "Alucard_inAir_Attack", 0, 4, 9, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("Attack_Air_Left", "Alucard_inAir_Attack", 5, 8, 9, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("Attack2_Air_Right", "Alucard_inAir_Attack_02", 0, 4, 9, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("Attack2_Air_Left", "Alucard_inAir_Attack_02", 5, 8, 9, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("Ducking_Right", "Alucard_Ducking_Image", 0, 13, 10, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("Ducking_Left", "Alucard_Ducking_Image", 17, 30, 10, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("Duck_Right", "Alucard_Ducking_Image", 10, 13, 12, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("Duck_Left", "Alucard_Ducking_Image", 27, 30, 12, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("Ducking_Attack_Right", "Alucard_Ducking_Attack_Image", 0, 11, 18, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("Ducking_Attack_Left", "Alucard_Ducking_Attack_Image", 12, 23, 18, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("Ducking_Attack_02_Right", "Alucard_Ducking_Attack_Image_02", 0, 11, 18, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("Ducking_Attack_02_Left", "Alucard_Ducking_Attack_Image_02", 12, 23, 18, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("Hit_Right", "Alucard_Hit_Image", 0, 5, 8, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("Hit_Left", "Alucard_Hit_Image", 13, 18, 8, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("Skill_Right", "Alucard_Skill_Image", 1, 12, 8, false, false);
	KEYANIMANAGER->addCoordinateFrameAnimation("Skill_Left", "Alucard_Skill_Image", 13, 24, 8, false, false);

#pragma endregion

	_alucard.width  = 45;
	_alucard.height = 115;
	_alucard.jumpCount = 0;

	_alucard.moveSpeed = MOVESPEED;
	_alucard.boolset.gravityCheck = true;
	_alucard.boolset.aniCheck = false;
	_alucard.boolset.jumpCheck = false;

	_alucard.image = IMAGEMANAGER->findImage("Alucard_Idle_Image");
	_alucard.ani = KEYANIMANAGER->findAnimation("Idle_Right");
	_alucard.ani->start();

	_attack = new CharacterAttack;
	_attack->init();

	_currentX = _currentY = 0;
	_alucard.frameCount = 0;
	_alucard.state = NONE;
	_alucard.direction = DirectionRight;

	for (int i = 0; i < 6; i++)
	{
		//잔상효과 Initial
		_afterimg[i].img = _alucard.image;
		_afterimg[i].testimg = _alucard.image;

		_afterimg[i].x = _alucard.x;
		_afterimg[i].y = _alucard.y;

		_afterimg[i].currentX = 0;
		_afterimg[i].currentY = 0;
		_afterimg[i].currentX2 = 0;
		_afterimg[i].currentY2 = 0;

		//초기 알파값 다르게 설정해서 순차적으로 나타나게 했습니다.
		_afterimg[0].alpha = 0;
		_afterimg[1].alpha = 25;
		_afterimg[2].alpha = 60;
		_afterimg[3].alpha = 95;
		_afterimg[4].alpha = 115;
		_afterimg[5].alpha = 135;
	}

	_alucard.rc = RectMakeCenter(_alucard.x, _alucard.y, _alucard.width, _alucard.height);

	_probeX = _probeY = 0;
	_firecount = 0;

	return S_OK;
}

void Alucard::update()
{
	AlucardData();
	AlucardInputKey();
	GravitySet();
	isJump();
	State();
	CharacterPixelGround();
	CharacterPixelWall();
	CharacterPixelTop();
	AlucardFrameCounter();
	AlucardAfterImage();

	_alucard.frameCount++;

	KEYANIMANAGER->update();
	_attack->update();

	//숙이고 있는 상태에서는 Rect 크기의 변화가 있습니다.
	if (_alucard.state != DUCK || _alucard.state != DUCKINGATTACK)
	{
		_alucard.rc = RectMakeCenter(_alucard.x, _alucard.y, _alucard.width, _alucard.height);
	}
	if (_alucard.state == DUCK || _alucard.state == DUCKINGATTACK)
	{
		_alucard.rc = RectMakeCenter(_alucard.x, _alucard.y, _alucard.width, 25);
	}
}

void Alucard::release()
{
	_attack->release();
}

void Alucard::render()
{
	if (KEYMANAGER->isToggleKey('P'))
	{
		Rectangle(CAMERAMANAGER->getWorldDC(), _alucard.rc);

	}

	for (int i = 0; i < 5; i++)
	{
		//잔상 효과 렌더
		_afterimg[i].img->alphaFrameRender(CAMERAMANAGER->getWorldDC(), _afterimg[i].x - 150, _afterimg[i].y - 240, 
		_afterimg[i].currentX2, _afterimg[i].currentY2,_afterimg[i].alpha);
	}

	_alucard.image->aniRender(CAMERAMANAGER->getWorldDC(), _alucard.x - 150, _alucard.y - 240, _alucard.ani);
	_attack->render();

	//Pixel Collision 범위 체크 
	//LineMake(CAMERAMANAGER->getWorldDC(), _alucard.x, _probeY - 7, _alucard.x, _probeY + 5);
	//LineMake(CAMERAMANAGER->getWorldDC(), _probeX - 24, _alucard.y, _probeX + 24, _alucard.y);
	//LineMake(CAMERAMANAGER->getWorldDC(), _alucard.x, _probeY2 - 4, _alucard.x, _probeY2 + 5);
}

void Alucard::AlucardData()
{
	//체력관련.
	//알카드의 현재 체력이 최대체력을 넘어서려할때 다시 최대 체력으로 맞춰준다.
	//0이하로 떨어지지않게 보정해주었습니다.
	if (DATA->playerInfo.currentHp > DATA->playerInfo.maxHp)
	{
		DATA->playerInfo.currentHp = DATA->playerInfo.maxHp;
	}
	if (DATA->playerInfo.currentHp <= 0)
	{
		DATA->playerInfo.currentHp = 0;
	}
	//마나 관련
	if (DATA->playerInfo.currentMana > DATA->playerInfo.maxMana)
	{
		DATA->playerInfo.currentMana = DATA->playerInfo.maxMana;
	}
	if (DATA->playerInfo.currentMana <= 0)
	{
		DATA->playerInfo.currentMana = 0;
	}
	//플레이어 레벨업.
	//현재 경험치를 초기화하고 캐릭터의 레벨과 각종 최대 능력치가 오릅니다.
	if (DATA->playerInfo.currentExp >= DATA->playerInfo.maxExp)
	{
		DATA->playerInfo.currentExp = 0;
		DATA->playerInfo.characterLevel += 1;
		DATA->playerInfo.maxHp += 10;
		DATA->playerInfo.maxMana += 10;
		DATA->playerInfo.STR += 1;
		DATA->playerInfo.CON += 1;
		DATA->playerInfo.INT += 1;
		DATA->playerInfo.LCK += 1;
	}

}

void Alucard::AlucardInputKey()
{
	//Move Key Setting
	if(KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		if (_alucard.state == ATTACK || _alucard.state == BACK_DASH || _alucard.state == DUCK || 
			_alucard.state == DUCKINGATTACK || _alucard.state == HIT || _alucard.state == AIRATTACK) return;

		_alucard.direction = DirectionLeft;


		_alucard.state = MOVE;

		if (!_alucard.boolset.moveCheck)
			StartMove();
		else if (_alucard.boolset.moveCheck)
			Moving();
	}

	else if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		if (_alucard.state == ATTACK || _alucard.state == BACK_DASH || _alucard.state == DUCK || 
			_alucard.state == DUCKINGATTACK || _alucard.state == HIT || _alucard.state == AIRATTACK) return;

		_alucard.direction = DirectionRight;


		_alucard.state = MOVE;

		if (!_alucard.boolset.moveCheck)
			StartMove();
		else if (_alucard.boolset.moveCheck)
			Moving();
	}
	if (KEYMANAGER->isOnceKeyUp(VK_LEFT))
	{
		if (_alucard.state == ATTACK || _alucard.state == HIT || _alucard.state == AIRATTACK) return;

		Idle();
		_alucard.state = NONE;
	}
	if (KEYMANAGER->isOnceKeyUp(VK_RIGHT))
	{
		if (_alucard.state == ATTACK || _alucard.state == HIT || _alucard.state == AIRATTACK) return;

		Idle();
		_alucard.state = NONE;
	}
	//JumpKey Setting
	if (KEYMANAGER->isOnceKeyDown('A'))
	{
		if (_alucard.state == HIT) return;

		_alucard.jumpCount++;
		_alucard.state = JUMP;

		if (_alucard.jumpCount == 1)
		{
			_alucard.boolset.aniCheck = false;
			Jump();

			//Map6의 발판 충돌 판정 처리 입니다
			if(SCENEMANAGER->getSceneNumber() == 6 || SCENEMANAGER->getSceneNumber() == 12)
			_alucard.boolset.scaffold = false;
		}
		else if (_alucard.jumpCount == 2)
		{
			_alucard.boolset.aniCheck = false;
			 DoubleJump();
		}
	}
	//BackDash Key Setting
	if (KEYMANAGER->isOnceKeyDown('S'))
	{
		if (_alucard.boolset.jumpCheck) return;

		BackDash();
		_alucard.state = BACK_DASH;
	}
	//Attack Key Setting
	if (KEYMANAGER->isOnceKeyDown('D'))
	{
		if (_alucard.state == ATTACK || _alucard.state == AIRATTACK || _alucard.state == HIT) return;
		
		if (_alucard.state == MOVE || _alucard.state == NONE)
		{
			_alucard.state = ATTACK;
			Attack();
		}

		if (_alucard.boolset.jumpCheck && _alucard.state != AIRATTACK)
		{
			_alucard.boolset.aniCheck = false;
			_alucard.state = AIRATTACK;
			AttackAir();
		}

		if (_alucard.state == DUCK && _alucard.state != DUCKINGATTACK)
		{
			_alucard.boolset.aniCheck = false;
			_alucard.state = DUCKINGATTACK;
			DuckingAttack();
		}
	}
	if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
	{
		if (_alucard.state == MOVE || _alucard.state == HIT) return;

		Ducking();
		_alucard.state = DUCK;
		_alucard.boolset.aniCheck = false;
	}
	if (KEYMANAGER->isOnceKeyUp(VK_DOWN))
	{
		if (_alucard.state == MOVE || _alucard.state == HIT) return;


		Idle();
		_alucard.state = NONE;
	}

	if (KEYMANAGER->isOnceKeyDown('F'))
	{
		if (_alucard.state != NONE || 
			DATA->playerInfo.currentMana < 10) return;
			
		_alucard.state = HELLFIRE;
		Skill();
		DATA->playerInfo.currentMana -= 10;
	}
}

void Alucard::AlucardPositionSet(float* x, float* y)
{
	_alucard.x = *x;
	_alucard.y = *y;
}

void Alucard::GravitySet()
{
	if (_alucard.boolset.gravityCheck)
	{
		if (!_alucard.boolset.gravityCheck) return;

		_alucard.y += GRAVITY;
	}
}

void Alucard::isJump()
{
	if (_alucard.boolset.jumpCheck)
	{
		//점프
		_alucard.y -= _alucard.jumpPower;
		_alucard.jumpPower -= GRAVITY;

		if (_alucard.jumpPower < 0) _alucard.jumpPower = 0;

		//Map6 의 발판 충돌 판정 처리입니다.
		if (SCENEMANAGER->getSceneNumber() == 6 || SCENEMANAGER->getSceneNumber() == 12)
		{
			if (!_alucard.boolset.scaffold)
				_scaffoldCount++;

			if (SCENEMANAGER->getSceneNumber() == 6)
			{
				if (_scaffoldCount >= 45)
				{
					_alucard.boolset.scaffold = true;
					_scaffoldCount = 0;
				}
			}
			else if (SCENEMANAGER->getSceneNumber() == 12)
			{
				if (_scaffoldCount >= 25)
				{
					_alucard.boolset.scaffold = true;
					_scaffoldCount = 0;
				}
			}
		}
		
	}
	else if (!_alucard.boolset.jumpCheck)
	{
		_alucard.jumpPower = 0;
	}
}

void Alucard::State()
{
	switch (_alucard.state)
	{
	case NONE:
		_firecount = 0;

		break;

	case MOVE:
		if (_alucard.direction == DirectionLeft)
			_alucard.x -= MOVESPEED;

		else if (_alucard.direction == DirectionRight)
			_alucard.x += MOVESPEED;

		break;
	case BACK_DASH:
		//백대쉬 방향에 따라 속도.
		if (_alucard.direction == DirectionLeft) 
			_alucard.x += MOVESPEED * 1.3f;

		else if (_alucard.direction == DirectionRight) 
			_alucard.x -= MOVESPEED * 1.3f;

		//백대쉬 프레임 최대 도달하면 상태 교체.
		if (_alucard.ani->getFramePos().x == 3000)
		{
			Idle();
			_alucard.state = NONE;
		}
		break;

	case ATTACK:

		if (_alucard.ani->getFramePos().x >= 1500)
		{
			Idle();
			_alucard.state = NONE;
		}

		break;

	case AIRATTACK:

		if (_alucard.ani->getFramePos().x >= 900)
		{
			Idle();
			_alucard.state = NONE;

		}

		break;

	case FALLING:

		break;
	case HELLFIRE:

		if (_alucard.ani->getFramePos().x >= 3300)
		{
			_alucard.state = NONE;
			_alucard.boolset.getDamage = false;
			Idle();
		}

		AlucardMagicUse();



		break;

	case DUCK:

		if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
		{
			_alucard.boolset.aniCheck = false;
			_alucard.direction = DirectionLeft;
			DuckingDirection();
		}

		else if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
		{
			_alucard.boolset.aniCheck = false;
			_alucard.direction = DirectionRight;
			DuckingDirection();
		}

		break;

	case DUCKINGATTACK:

		if (_alucard.ani->getFramePos().x >= 2500)
		{
			_alucard.boolset.aniCheck = false;
			_alucard.state = DUCK;
			DuckingDirection();
		}

		break;

	case HIT:
		if (_alucard.direction == DirectionLeft)
			_alucard.x += 2.5;
		else if (_alucard.direction == DirectionRight)
			_alucard.x -= 2.5;

		if (_alucard.ani->getFramePos().x >= 1000)
		{
			_alucard.boolset.getDamage = false;
			_alucard.state = NONE;
			Idle();
		}


		break;
	default:

		break;
	}


}

void Alucard::Idle()
{
	_alucard.boolset.aniCheck = false;
	_alucard.boolset.moveCheck = false;

	if (_alucard.boolset.jumpCheck) return;

	if (_alucard.direction == DirectionLeft)
	{
		_alucard.image = IMAGEMANAGER->findImage("Alucard_Idle_Image");
		_alucard.ani = KEYANIMANAGER->findAnimation("Idle_Left");
		_alucard.ani->start();

		_currentY = 1;
	}
	else if (_alucard.direction == DirectionRight)
	{
		_alucard.image = IMAGEMANAGER->findImage("Alucard_Idle_Image");
		_alucard.ani = KEYANIMANAGER->findAnimation("Idle_Right");
		_alucard.ani->start();

		_currentY = 0;
	}

	_currentX = 0;
}

void Alucard::StartMove()
{
	if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
	{
		_alucard.boolset.aniCheck = false;
	}
	else if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
	{
		_alucard.boolset.aniCheck = false;
	}

	if (_alucard.direction == DirectionLeft)
	{
		if (!_alucard.boolset.aniCheck)
		{
			_alucard.image = IMAGEMANAGER->findImage("Alucard_Start_Move_Image");
			_alucard.ani = KEYANIMANAGER->findAnimation("Move_Start_Left");
			_alucard.ani->start();
			_alucard.boolset.aniCheck = true;
		}

		_currentY = 1;
	}
	else if (_alucard.direction == DirectionRight)
	{
		if (!_alucard.boolset.aniCheck)
		{
			_alucard.image = IMAGEMANAGER->findImage("Alucard_Start_Move_Image");
			_alucard.ani = KEYANIMANAGER->findAnimation("Move_Start_Right"); 
			_alucard.ani->start();
			_alucard.boolset.aniCheck = true;
		}

		_currentY = 0;
	}


	if (KEYMANAGER->isOnceKeyDown('D'))
	{
		if (_alucard.jumpCount <= 0)
		{
			_alucard.boolset.aniCheck = false;
			_alucard.state = ATTACK;
			Attack();
		}

		else if (_alucard.jumpCount > 0)
		{
			_alucard.boolset.aniCheck = false;
			_alucard.state = AIRATTACK;
			AttackAir();
		}
	}

	if (_alucard.ani->getFramePos().x == 3000)
	{
		_alucard.boolset.aniCheck = false;
		_alucard.boolset.moveCheck = true;
	}
}

void Alucard::Moving()
{
	if (_alucard.direction == DirectionLeft)
	{

		if (!_alucard.boolset.aniCheck)
		{
			_alucard.image = IMAGEMANAGER->findImage("Alucard_Move_Image");
			_alucard.ani = KEYANIMANAGER->findAnimation("Move_Left");
			_alucard.ani->start();
			_alucard.boolset.aniCheck = true;
		}

		_currentY = 1;
	}
	else if (_alucard.direction == DirectionRight)
	{
		if (!_alucard.boolset.aniCheck)
		{
			_alucard.image = IMAGEMANAGER->findImage("Alucard_Move_Image");
			_alucard.ani = KEYANIMANAGER->findAnimation("Move_Right");
			_alucard.ani->start();
			_alucard.boolset.aniCheck = true;
		}

		_currentY = 0;
	}

	if (KEYMANAGER->isOnceKeyDown('D'))
	{
		if (_alucard.jumpCount <= 0)
		{
			_alucard.boolset.aniCheck = false;
			_alucard.state = ATTACK;
			Attack();
		}

		else if (_alucard.jumpCount > 0)
		{
			_alucard.boolset.aniCheck = false;
			_alucard.state = AIRATTACK;
			AttackAir();
		}
	}
}

void Alucard::Jump()
{
	if (_alucard.jumpCount > 2) return;

	_alucard.boolset.jumpCheck = true;
	_alucard.jumpPower = JUMPPOWER;
	isJump();

	if (_alucard.direction == DirectionLeft)
	{
		if (!_alucard.boolset.aniCheck)
		{
			_alucard.image = IMAGEMANAGER->findImage("Alucard_Jump_Image");
			_alucard.ani = KEYANIMANAGER->findAnimation("Jump_Left");
			_alucard.ani->start();
			_alucard.boolset.aniCheck = true;
		}

		_currentY = 1;
	}

	else if (_alucard.direction == DirectionRight)
	{
		if (!_alucard.boolset.aniCheck)
		{
			_alucard.image = IMAGEMANAGER->findImage("Alucard_Jump_Image");
			_alucard.ani = KEYANIMANAGER->findAnimation("Jump_Right");
			_alucard.ani->start();
			_alucard.boolset.aniCheck = true;
		}

		_currentY = 0;
	}

	_currentX = 0;
}

void Alucard::DoubleJump()
{
	if (_alucard.jumpCount > 2) return;

	_alucard.boolset.jumpCheck = true;
	_alucard.jumpPower = JUMPPOWER;
	isJump();

	if (_alucard.direction == DirectionLeft)
	{
		if (!_alucard.boolset.aniCheck)
		{
			_alucard.image = IMAGEMANAGER->findImage("Alucard_Double_Jump_Image");
			_alucard.ani = KEYANIMANAGER->findAnimation("DJump_Left");
			_alucard.ani->start();
			_alucard.boolset.aniCheck = true;
		}

		_currentY = 1;
	}
	else if (_alucard.direction == DirectionRight)
	{
		if (!_alucard.boolset.aniCheck)
		{
			_alucard.image = IMAGEMANAGER->findImage("Alucard_Double_Jump_Image");
			_alucard.ani = KEYANIMANAGER->findAnimation("DJump_Right");
			_alucard.ani->start();
			_alucard.boolset.aniCheck = true;
		}

		_currentY = 0;
	}

	_currentX = 0;
}

void Alucard::BackDash()
{

	if (_alucard.direction == DirectionLeft)
	{
		if (!_alucard.boolset.aniCheck)
		{
			_alucard.image = IMAGEMANAGER->findImage("Alucard_Back_Dash_Image");
			_alucard.ani = KEYANIMANAGER->findAnimation("BackDash_Right");
			_alucard.ani->start();
			_alucard.boolset.aniCheck = true;
		}

		_currentY = 1;
	}

	else if (_alucard.direction == DirectionRight)
	{
		if (!_alucard.boolset.aniCheck)
		{
			_alucard.image = IMAGEMANAGER->findImage("Alucard_Back_Dash_Image");
			_alucard.ani = KEYANIMANAGER->findAnimation("BackDash_Left");
			_alucard.ani->start();
			_alucard.boolset.aniCheck = true;
		}

		_currentY = 0;
	}

	_currentX = 0;
}

void Alucard::Attack()
{
	if (_alucard.direction == DirectionLeft)
	{
		_attack->SwordAttack(_alucard.x - 80, _alucard.y - 60);

		if (!_alucard.boolset.aniCheck)
		{
			if (DATA->playerInfo.swordType == 0)
			{
				_alucard.image = IMAGEMANAGER->findImage("Alucard_Attack_Image");
				_alucard.ani = KEYANIMANAGER->findAnimation("Attack_Left");
			}
			else if (DATA->playerInfo.swordType == 1)
			{
				_alucard.image = IMAGEMANAGER->findImage("Alucard_Attack_Image_02");
				_alucard.ani = KEYANIMANAGER->findAnimation("Attack2_Left");
			}
			_alucard.ani->start();
			_alucard.boolset.aniCheck = true;
		}

		_currentY = 1;
	}

	else if (_alucard.direction == DirectionRight)
	{
		_attack->SwordAttack(_alucard.x + 80, _alucard.y - 60);

		if (!_alucard.boolset.aniCheck)
		{
			if (DATA->playerInfo.swordType == 0)
			{
				_alucard.image = IMAGEMANAGER->findImage("Alucard_Attack_Image");
				_alucard.ani = KEYANIMANAGER->findAnimation("Attack_Right");
			}
			else if (DATA->playerInfo.swordType == 1)
			{
				_alucard.image = IMAGEMANAGER->findImage("Alucard_Attack_Image_02");
				_alucard.ani = KEYANIMANAGER->findAnimation("Attack2_Right");
			}
			_alucard.ani->start();
			_alucard.boolset.aniCheck = true;
		}

		_currentY = 0;
	}

	_currentX = 0;

}

void Alucard::AttackAir()
{
	if (_alucard.direction == DirectionLeft)
	{
		_attack->SwordAttack(_alucard.x - 80, _alucard.y - 60);

		if (!_alucard.boolset.aniCheck)
		{                                               
			if (DATA->playerInfo.swordType == 0)
			{
				_alucard.image = IMAGEMANAGER->findImage("Alucard_inAir_Attack");
				_alucard.ani = KEYANIMANAGER->findAnimation("Attack_Air_Left");
			}
			else if (DATA->playerInfo.swordType == 1)
			{
				_alucard.image = IMAGEMANAGER->findImage("Alucard_inAir_Attack_02");
				_alucard.ani = KEYANIMANAGER->findAnimation("Attack2_Air_Left");
			}
			_alucard.ani->start();
			_alucard.boolset.aniCheck = true;
		}

		_currentY = 1;
	}

	else if (_alucard.direction == DirectionRight)
	{
		_attack->SwordAttack(_alucard.x + 80, _alucard.y - 60);

		if (!_alucard.boolset.aniCheck)
		{
			if (DATA->playerInfo.swordType == 0)
			{
				_alucard.image = IMAGEMANAGER->findImage("Alucard_inAir_Attack");
				_alucard.ani = KEYANIMANAGER->findAnimation("Attack_Air_Right");
			}
			else if (DATA->playerInfo.swordType == 1)
			{
				_alucard.image = IMAGEMANAGER->findImage("Alucard_inAir_Attack_02");
				_alucard.ani = KEYANIMANAGER->findAnimation("Attack2_Air_Right");
			}
			_alucard.ani->start();
			_alucard.boolset.aniCheck = true;
		}

		_currentY = 0;
	}

	_currentX = 0;
}

void Alucard::Falling()
{

	if (_alucard.direction == DirectionLeft)
	{
		if (!_alucard.boolset.aniCheck)
		{
			_alucard.image = IMAGEMANAGER->findImage("Alucard_Falling_Image");
			_alucard.ani = KEYANIMANAGER->findAnimation("Falling_Left");
			_alucard.ani->start();
			_alucard.boolset.aniCheck = true;
		}

		_currentY = 1;
	}

	else if (_alucard.direction == DirectionRight)
	{
		if (!_alucard.boolset.aniCheck)
		{
			_alucard.image = IMAGEMANAGER->findImage("Alucard_Falling_Image");
			_alucard.ani = KEYANIMANAGER->findAnimation("Falling_Right");
			_alucard.ani->start();
			_alucard.boolset.aniCheck = true;
		}

		_currentY = 0;
	}
}

void Alucard::Ducking()
{
	if (_alucard.direction == DirectionLeft)
	{
		if (!_alucard.boolset.aniCheck)
		{
			_alucard.image = IMAGEMANAGER->findImage("Alucard_Ducking_Image");
			_alucard.ani = KEYANIMANAGER->findAnimation("Ducking_Left");
			_alucard.ani->start();
			_alucard.boolset.aniCheck = true;
		}

		_currentY = 1;
	}

	else if (_alucard.direction == DirectionRight)
	{
		if (!_alucard.boolset.aniCheck)
		{
			_alucard.image = IMAGEMANAGER->findImage("Alucard_Ducking_Image");
			_alucard.ani = KEYANIMANAGER->findAnimation("Ducking_Right");
			_alucard.ani->start();
			_alucard.boolset.aniCheck = true;
		}

		_currentY = 0;
	}

	_currentX = 0;
}

void Alucard::DuckingDirection()
{
	if (_alucard.direction == DirectionLeft)
	{
		if (!_alucard.boolset.aniCheck)
		{
			_alucard.image = IMAGEMANAGER->findImage("Alucard_Ducking_Image");
			_alucard.ani = KEYANIMANAGER->findAnimation("Duck_Left");
			_alucard.ani->start();
			_alucard.boolset.aniCheck = true;
		}

		_currentY = 1;
	}

	else if (_alucard.direction == DirectionRight)
	{
		if (!_alucard.boolset.aniCheck)
		{
			_alucard.image = IMAGEMANAGER->findImage("Alucard_Ducking_Image");
			_alucard.ani = KEYANIMANAGER->findAnimation("Duck_Right");
			_alucard.ani->start();
			_alucard.boolset.aniCheck = true;
		}

		_currentY = 0;
	}
}

void Alucard::DuckingAttack()
{
	if (_alucard.direction == DirectionLeft)
	{
		_attack->SwordAttack(_alucard.x - 70, _alucard.y - 10);

		if (!_alucard.boolset.aniCheck)
		{
			if (DATA->playerInfo.swordType == 0)
			{
				_alucard.image = IMAGEMANAGER->findImage("Alucard_Ducking_Attack_Image");
				_alucard.ani = KEYANIMANAGER->findAnimation("Ducking_Attack_Left");
			}

			else if (DATA->playerInfo.swordType == 1)
			{
				_alucard.image = IMAGEMANAGER->findImage("Alucard_Ducking_Attack_Image_02");
				_alucard.ani = KEYANIMANAGER->findAnimation("Ducking_Attack_02_Left");
				
			}

			_alucard.ani->start();
			_alucard.boolset.aniCheck = true;
		}

		_currentY = 1;
	}

	else if (_alucard.direction == DirectionRight)
	{
		_attack->SwordAttack(_alucard.x + 70, _alucard.y - 10);

		if (!_alucard.boolset.aniCheck)
		{
			if (DATA->playerInfo.swordType == 0)
			{
				_alucard.image = IMAGEMANAGER->findImage("Alucard_Ducking_Attack_Image");
				_alucard.ani = KEYANIMANAGER->findAnimation("Ducking_Attack_Right");
			}

			else if (DATA->playerInfo.swordType == 1)
			{
				_alucard.image = IMAGEMANAGER->findImage("Alucard_Ducking_Attack_Image_02");
				_alucard.ani = KEYANIMANAGER->findAnimation("Ducking_Attack_02_Right");
			}

			_alucard.ani->start();
			_alucard.boolset.aniCheck = true;
		}

		_currentY = 0;
	}

	_currentX = 0;
}

void Alucard::Hit()
{

	_alucard.boolset.aniCheck = false;
	_alucard.boolset.getDamage = true;
	_alucard.state = HIT;

	if (_alucard.direction == DirectionLeft)
	{
		if (!_alucard.boolset.aniCheck)
		{
			_alucard.image = IMAGEMANAGER->findImage("Alucard_Hit_Image");
			_alucard.ani = KEYANIMANAGER->findAnimation("Hit_Left");
			_alucard.ani->start();
			_alucard.boolset.aniCheck = true;
		}

		_currentY = 1;
	}

	else if (_alucard.direction == DirectionRight)
	{
		_alucard.x -= 5;

		if (!_alucard.boolset.aniCheck)
		{
			_alucard.image = IMAGEMANAGER->findImage("Alucard_Hit_Image");
			_alucard.ani = KEYANIMANAGER->findAnimation("Hit_Right");
			_alucard.ani->start();
			_alucard.boolset.aniCheck = true;
		}

		_currentY = 0;
	}

	_currentX = 0;
}

void Alucard::Skill()
{
	//마법시전중에는 방해받지 않습니다.
	_alucard.boolset.getDamage = true;

	if (_alucard.direction == DirectionLeft)
	{
		if (!_alucard.boolset.aniCheck)
		{
			_alucard.image = IMAGEMANAGER->findImage("Alucard_Skill_Image");
			_alucard.ani = KEYANIMANAGER->findAnimation("Skill_Left");
			_alucard.ani->start();
			_alucard.boolset.aniCheck = true;
		}
	}

	else if (_alucard.direction == DirectionRight)
	{
		if (!_alucard.boolset.aniCheck)
		{
			_alucard.image = IMAGEMANAGER->findImage("Alucard_Skill_Image");
			_alucard.ani = KEYANIMANAGER->findAnimation("Skill_Right");
			_alucard.ani->start();
			_alucard.boolset.aniCheck = true;
		}
	}

	_currentX = 0;
}

void Alucard::AlucardAfterImage()
{
	for (int i = 0; i < 6; i++)
	{
		//잔상이 흐려지는 속도.
		_afterimg[i].alpha -= 3;

		//잔상의 알파값 0아래로 떨어지면 150으로 맞춥니다.
		if (_afterimg[i].alpha <= 0)
		{
			_afterimg[i].alpha = 150;
		}

		//잔상의 알파값이 150으로 돌아왔을때 당시의 
		//캐릭터의 이미지와 위치를 저장합니다.
		if (_afterimg[0].alpha == 150)
		{
			_afterimg[0].testimg = _alucard.image;

			_afterimg[0].testPosX = _alucard.x;
			_afterimg[0].testPosY = _alucard.y;

			_afterimg[0].currentX = _currentX;
			_afterimg[0].currentY = _currentY;
		}

		if (_afterimg[1].alpha == 150)
		{
			_afterimg[1].testimg = _alucard.image;

			_afterimg[1].testPosX = _alucard.x;
			_afterimg[1].testPosY = _alucard.y;

			_afterimg[1].currentX = _currentX;
			_afterimg[1].currentY = _currentY;
		}

		if (_afterimg[2].alpha == 150)
		{
			_afterimg[2].testimg = _alucard.image;

			_afterimg[2].testPosX = _alucard.x;
			_afterimg[2].testPosY = _alucard.y;

			_afterimg[2].currentX = _currentX;
			_afterimg[2].currentY = _currentY;
		}

		if (_afterimg[3].alpha == 150)
		{
			_afterimg[3].testimg = _alucard.image;

			_afterimg[3].testPosX = _alucard.x;
			_afterimg[3].testPosY = _alucard.y;

			_afterimg[3].currentX = _currentX;
			_afterimg[3].currentY = _currentY;
		}

		if (_afterimg[4].alpha == 150)
		{
			_afterimg[4].testimg = _alucard.image;

			_afterimg[4].testPosX = _alucard.x;
			_afterimg[4].testPosY = _alucard.y;

			_afterimg[4].currentX = _currentX;
			_afterimg[4].currentY = _currentY;
		}

		if (_afterimg[5].alpha == 150)
		{
			_afterimg[5].testimg = _alucard.image;
		
			_afterimg[5].testPosX = _alucard.x;
			_afterimg[5].testPosY = _alucard.y;
		
			_afterimg[5].currentX = _currentX;
			_afterimg[5].currentY = _currentY;
		}

		//저장했던 위치와 이미지를 대입해줍니다.
		//알파값이 내려가기 시작할때 저장했던 위치와 이미지를 대입해서 
		//캐릭터와 같이 움직이지 않도록 합니다.
		if (_afterimg[0].alpha < 151)
		{
			_afterimg[0].img = _afterimg[0].testimg;

			_afterimg[0].x = _afterimg[0].testPosX;
			_afterimg[0].y = _afterimg[0].testPosY;

			_afterimg[0].currentX2 = _afterimg[0].currentX;
			_afterimg[0].currentY2 = _afterimg[0].currentY;
		}
		if (_afterimg[1].alpha < 151)
		{
			_afterimg[1].img = _afterimg[1].testimg;

			_afterimg[1].x = _afterimg[1].testPosX;
			_afterimg[1].y = _afterimg[1].testPosY;

			_afterimg[1].currentX2 = _afterimg[1].currentX;
			_afterimg[1].currentY2 = _afterimg[1].currentY;
		}
		if (_afterimg[2].alpha < 151)
		{
			_afterimg[2].img = _afterimg[2].testimg;

			_afterimg[2].x = _afterimg[2].testPosX;
			_afterimg[2].y = _afterimg[2].testPosY;

			_afterimg[2].currentX2 = _afterimg[2].currentX;
			_afterimg[2].currentY2 = _afterimg[2].currentY;
		}
		if (_afterimg[3].alpha < 151)
		{
			_afterimg[3].img = _afterimg[3].testimg;

			_afterimg[3].x = _afterimg[3].testPosX;
			_afterimg[3].y = _afterimg[3].testPosY;

			_afterimg[3].currentX2 = _afterimg[3].currentX;
			_afterimg[3].currentY2 = _afterimg[3].currentY;
		}
		if (_afterimg[4].alpha < 151)
		{
			_afterimg[4].img = _afterimg[4].testimg;

			_afterimg[4].x = _afterimg[4].testPosX;
			_afterimg[4].y = _afterimg[4].testPosY;

			_afterimg[4].currentX2 = _afterimg[4].currentX;
			_afterimg[4].currentY2 = _afterimg[4].currentY;
		}
		if (_afterimg[5].alpha < 151)
		{
			_afterimg[5].img = _afterimg[5].testimg;

			_afterimg[5].x = _afterimg[5].testPosX;
			_afterimg[5].y = _afterimg[5].testPosY;

			_afterimg[5].currentX2 = _afterimg[5].currentX;
			_afterimg[5].currentY2 = _afterimg[5].currentY;
		}

	}

}

void Alucard::AlucardMagicUse()
{
	_firecount++;

	if (_firecount % 20 == 0)
	{
		if (_alucard.direction == DirectionRight)
		{
			_attack->HellFire(_alucard.x, _alucard.y - 20,
				getAngle(_alucard.x, _alucard.y - 20,
					_alucard.x,
					_alucard.y - 100),
				2.0f);

			_firecount = 0;
		}

		else if (_alucard.direction == DirectionLeft)
		{
			_attack->HellFire(_alucard.x, _alucard.y - 20,
				getAngle(_alucard.x, _alucard.y - 20,
					_alucard.x,
					_alucard.y + 100),
				2.0f);

			_firecount = 0;
		}
	}

}

void Alucard::AlucardFrameCounter()
{

	if (_alucard.state == NONE)
	{
		if (_alucard.frameCount % 10 == 0)
		{
			_currentX++;

			if (_currentX >= 6)
			{
				_currentX = 0;
			}

			_alucard.frameCount = 0;
		}
	}

	else if (_alucard.state == MOVE)
	{
		if (_alucard.jumpCount <= 0)
		{

			if (_alucard.frameCount % 10 == 0)
			{
				_currentX++;

				if (_currentX >= _alucard.image->getMaxFrameX())
				{
					_currentX = 0;
				}

				_alucard.frameCount = 0;
			}
		}

		if (_alucard.jumpCount == 1)
		{
			if (_alucard.frameCount % 10 == 0)
			{
				_currentX++;

				if (_currentX >= _alucard.image->getMaxFrameX())
				{
					_currentX = 0;
				}

				_alucard.frameCount = 0;
			}
		}

		else if (_alucard.jumpCount == 2)
		{
			if (_alucard.frameCount % 10 == 0)
			{
				_currentX++;

				if (_currentX >= 4)
				{
					_currentX = 4;
				}

				_alucard.frameCount = 0;
			}
		}
	}

	else if (_alucard.state == BACK_DASH)
	{
		if (_alucard.frameCount % 10 == 0)
		{
			_currentX++;

			if (_currentX >= _alucard.image->getMaxFrameX())
			{
				_currentX = 0;
			}

			_alucard.frameCount = 0;
		}
	}

	else if (_alucard.state == HIT)
	{
		if (_alucard.frameCount % 10 == 0)
		{
			_currentX++;

			if (_currentX >= 4)
			{
				_currentX = 0;
			}

			_alucard.frameCount = 0;
		}
	}

	else if (_alucard.state == ATTACK)
	{
		if (_alucard.frameCount % 10 == 0)
		{
			_currentX++;

			if (_currentX >= _alucard.image->getMaxFrameX())
			{
				_currentX = 0;
			}

			_alucard.frameCount = 0;
		}
	}

	else if (_alucard.state == JUMP)
	{
		if (_alucard.frameCount % 10 == 0)
		{
			if (_alucard.jumpCount == 1)
			{
				_currentX++;

				if (_currentX >= _alucard.image->getMaxFrameX())
				{
					_currentX = 0;
				}

				_alucard.frameCount = 0;
			}

			else if (_alucard.jumpCount == 2)
			{
				_currentX++;

				if (_currentX >= 4)
				{
					_currentX = 4;
				}

				_alucard.frameCount = 0;
			}
		}
	}

	else if (_alucard.state == DUCK)
	{
		if (_alucard.frameCount % 10 == 0)
		{
			_currentX = 12;
			_alucard.frameCount = 0;
		}
	}

	else if (_alucard.state == DUCKINGATTACK)
	{
		if (_alucard.frameCount % 10 == 0)
		{
			_currentX++;

			if (_currentX >= _alucard.image->getMaxFrameX())
			{
				_currentX = 0;
			}

			_alucard.frameCount = 0;
		}
	}

	else if (_alucard.state == AIRATTACK)
	{
		if (_alucard.frameCount % 10 == 0)
		{
			_currentX++;

			if (_currentX > _alucard.image->getMaxFrameX())
			{
				_currentX = 0;
			}

			_alucard.frameCount = 0;
		}
	}
}

