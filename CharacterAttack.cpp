#include "stdafx.h"
#include "CharacterAttack.h"

HRESULT CharacterAttack::init()
{
	IMAGEMANAGER->addFrameImage("FireBall", "Image/AlucardImage/Fire_Ball.bmp", 240, 48, 5, 1, true, RGB(255, 0, 255));

	return S_OK;
}

void CharacterAttack::update()
{

	for (int i = 0; i < _vAttack.size(); i++)
	{
		if (_vAttack.size() == 0) return;

		_vAttack[i].duration++;

		if (_vAttack[i].type == MagicAttack)
		{
			//공격프레임 이미지 돌려주는곳. (마법 공격)
			_vAttack[i].frameCount++;
			if (_vAttack[i].frameCount % 4 == 0)
			{
				_vAttack[i].currentX++;
				if (_vAttack[i].currentX >= _vAttack[i].img->getMaxFrameX())
				{
					_vAttack[i].currentX = 0;
				}
				_vAttack[i].frameCount = 0;
			}
		}

	}

	CharacterMagicMove();
	EraseAttack();
	EraseAttack2();
}

void CharacterAttack::release()
{

}

void CharacterAttack::render()
{
	for (int i = 0; i < _vAttack.size(); i++)
	{
		if (_vAttack.size() == 0) return;

		//Rectangle(CAMERAMANAGER->getWorldDC(), _vAttack[i].rc);

		if (_vAttack[i].type != MagicAttack) return;

		_vAttack[i].img->frameRender(CAMERAMANAGER->getWorldDC(), _vAttack[i].rc.left, _vAttack[i].rc.top,
			_vAttack[i].currentX, _vAttack[i].currentY);

	}
}

void CharacterAttack::SwordAttack(float x, float y)
{
	AlucardAttack attack;

	ZeroMemory(&attack, sizeof(AlucardAttack));

	attack.x = x;
	attack.y = y;

	attack.rc = RectMakeCenter(attack.x, attack.y, 110, 30);
	attack.type = NormalAttack;

	_vAttack.push_back(attack);
}

void CharacterAttack::HellFire(float x, float y, float angle, float speed)
{
	AlucardAttack fire;

	ZeroMemory(&fire, sizeof(AlucardAttack));

	fire.x = x;
	fire.y = y;

	fire.speed = speed;
	fire.img = IMAGEMANAGER->findImage("FireBall");

	fire.currentX = 0;
	fire.currentY = 0;
	fire.frameCount = 0;
	fire.type = MagicAttack;
	fire.duration = 0;

	fire.angle = angle;

	fire.rc = RectMakeCenter(fire.x, fire.y, fire.img->getFrameWidth(), fire.img->getFrameHeight());

	_vAttack.push_back(fire);
}

void CharacterAttack::CharacterMagicMove()
{
	for (int i = 0; i < _vAttack.size(); i++)
	{
		if (_vAttack.size() == 0) return;

		if (_vAttack[i].type == MagicAttack)
		{
			if (_vAttack[i].duration < 25) _vAttack[i].speed = 2.0f;
			if (_vAttack[i].duration > 25) _vAttack[i].speed += 0.2;

			_vAttack[i].x +=  sinf(_vAttack[i].angle) * _vAttack[i].speed;
			_vAttack[i].y += -cosf(_vAttack[i].angle) * _vAttack[i].speed;

			_vAttack[i].rc = RectMakeCenter(_vAttack[i].x, _vAttack[i].y,
				_vAttack[i].img->getFrameWidth(), _vAttack[i].img->getFrameHeight());
		}
	}
}

void CharacterAttack::EraseAttack()
{
	for (_viAttack = _vAttack.begin(); _viAttack != _vAttack.end();)
	{
		if (_vAttack.size() == 0) return;
		if ((*_viAttack).type == MagicAttack) return;

		if ((*_viAttack).duration > 15)
		{
			_viAttack = _vAttack.erase(_viAttack);
		}

		else
		{
			_viAttack++;
		}
	}
}

void CharacterAttack::EraseAttack2()
{
	for (_viAttack = _vAttack.begin(); _viAttack != _vAttack.end();)
	{
		if (_vAttack.size() == 0) return;
		if ((*_viAttack).type == NormalAttack) return;

		if ((*_viAttack).duration > 200)
		{
			_viAttack = _vAttack.erase(_viAttack);
		}

		else
		{
			_viAttack++;
		}
	}
}

void CharacterAttack::AttackDelete(int arrNum)
{
	_vAttack.erase(_vAttack.begin() + arrNum);
}
