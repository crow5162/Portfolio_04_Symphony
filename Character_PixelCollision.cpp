#include "stdafx.h"
#include "Alucard.h"

//Ground Pixel Collision
void Alucard::CharacterPixelGround()
{
	_probeY = _alucard.y + _alucard.height / 2;
	
	for (int i = _probeY - 7; i < _probeY + 5; ++i)
	{
		//Map_01 �� �ȼ� �浹 �����Դϴ�.
		if (SCENEMANAGER->getSceneNumber() == 1)
		{
			COLORREF color = GetPixel(IMAGEMANAGER->findImage("Map_01_Pixel")->getMemDC(), _alucard.x, i);

			int r = GetRValue(color);
			int g = GetGValue(color);
			int b = GetBValue(color);

			if ((r == 0 && g == 42 && b == 254))
			{
				if (_alucard.boolset.jumpCheck)
				{
					_alucard.boolset.jumpCheck = false;
					_alucard.jumpCount = 0;
					
					if (!_alucard.boolset.getDamage)
					Idle();
				}

				_alucard.boolset.gravityCheck = false;
				_alucard.y = i - _alucard.height / 2;

				break;
			}

			else if (!(r == 0 && g == 42 && b == 254))
			{
				_alucard.boolset.gravityCheck = true;

				if (!_alucard.boolset.jumpCheck)
				{
					_alucard.y += 0.6f;
				}
				else if (_alucard.boolset.jumpCheck)
				{
					_alucard.y += 2.5f;
				}
			}
		}
		//Map_02 �� �ȼ� �浹 �����Դϴ�.
		if (SCENEMANAGER->getSceneNumber() == 2)
		{
			COLORREF color = GetPixel(IMAGEMANAGER->findImage("Map_02_Pixel")->getMemDC(), _alucard.x, i);

			int r = GetRValue(color);
			int g = GetGValue(color);
			int b = GetBValue(color);

			if ((r == 0 && g == 42 && b == 254))
			{
				if (_alucard.boolset.jumpCheck)
				{
					_alucard.boolset.jumpCheck = false;
					_alucard.jumpCount = 0;

					if (!_alucard.boolset.getDamage)
					Idle();
				}

				_alucard.boolset.gravityCheck = false;
				_alucard.y = i - _alucard.height / 2;

				break;
			}

			else if (!(r == 0 && g == 42 && b == 254))
			{
				_alucard.boolset.gravityCheck = true;

				if (!_alucard.boolset.jumpCheck)
				{
					_alucard.y += 0.6f;
				}
				else if (_alucard.boolset.jumpCheck)
				{
					_alucard.y += 2.5f;
				}
			}
		}
		//Map_03 �� �ȼ� �浹 �����Դϴ�.
		if (SCENEMANAGER->getSceneNumber() == 3)
		{
			COLORREF color = GetPixel(IMAGEMANAGER->findImage("Map_03_Pixel")->getMemDC(), _alucard.x, i);

			int r = GetRValue(color);
			int g = GetGValue(color);
			int b = GetBValue(color);

			if ((r == 0 && g == 42 && b == 254))
			{
				if (_alucard.boolset.jumpCheck)
				{
					_alucard.boolset.jumpCheck = false;
					_alucard.jumpCount = 0;

					if (!_alucard.boolset.getDamage)
					Idle();
				}

				_alucard.boolset.gravityCheck = false;
				_alucard.y = i - _alucard.height / 2;

				break;
			}

			else if (!(r == 0 && g == 42 && b == 254))
			{
				_alucard.boolset.gravityCheck = true;

				if (!_alucard.boolset.jumpCheck)
				{
					_alucard.y += 0.6f;
				}
				else if (_alucard.boolset.jumpCheck)
				{
					_alucard.y += 2.5f;
				}
			}
		}
		//Map_04 �� �ȼ� �浹 �����Դϴ�.
		if (SCENEMANAGER->getSceneNumber() == 4)
		{
			COLORREF color = GetPixel(IMAGEMANAGER->findImage("Map_04_Pixel")->getMemDC(), _alucard.x, i);

			int r = GetRValue(color);
			int g = GetGValue(color);
			int b = GetBValue(color);

			if ((r == 0 && g == 42 && b == 254))
			{
				if (_alucard.boolset.jumpCheck)
				{
					_alucard.boolset.jumpCheck = false;
					_alucard.jumpCount = 0;

					if (!_alucard.boolset.getDamage)
					Idle();
				}

				_alucard.boolset.gravityCheck = false;
				_alucard.y = i - _alucard.height / 2;

				break;
			}

			else if (!(r == 0 && g == 42 && b == 254))
			{
				_alucard.boolset.gravityCheck = true;

				if (!_alucard.boolset.jumpCheck)
				{
					_alucard.y += 0.6f;
				}
				else if (_alucard.boolset.jumpCheck)
				{
					_alucard.y += 2.5f;
				}
			}
		}
		//Map_05 �� �ȼ� �浹 �����Դϴ�.
		if (SCENEMANAGER->getSceneNumber() == 5)
		{
			COLORREF color = GetPixel(IMAGEMANAGER->findImage("Map_05_Pixel")->getMemDC(), _alucard.x, i);

			int r = GetRValue(color);
			int g = GetGValue(color);
			int b = GetBValue(color);

			if ((r == 0 && g == 42 && b == 254))
			{
				if (_alucard.boolset.jumpCheck)
				{
					_alucard.boolset.jumpCheck = false;
					_alucard.jumpCount = 0;

					if (!_alucard.boolset.getDamage)
					Idle();
				}

				_alucard.boolset.gravityCheck = false;
				_alucard.y = i - _alucard.height / 2;

				break;
			}

			else if (!(r == 0 && g == 42 && b == 254))
			{
				_alucard.boolset.gravityCheck = true;

				if (!_alucard.boolset.jumpCheck)
				{
					_alucard.y += 0.6f;
				}
				else if (_alucard.boolset.jumpCheck)
				{
					_alucard.y += 2.5f;
				}
			}
		}
		//Map_06 �� �ȼ� �浹 �����Դϴ�.
		if (SCENEMANAGER->getSceneNumber() == 6)
		{
			COLORREF color = GetPixel(IMAGEMANAGER->findImage("Map_06_Pixel")->getMemDC(), _alucard.x, i);

			int r = GetRValue(color);
			int g = GetGValue(color);
			int b = GetBValue(color);

			//������ �浹.
			if ((r == 0 && g == 42 && b == 254))
			{
				if (_alucard.boolset.jumpCheck)
				{
					_alucard.boolset.jumpCheck = false;
					_alucard.jumpCount = 0;

					if (!_alucard.boolset.getDamage)
					Idle();
				}

				_alucard.boolset.gravityCheck = false;
				_alucard.y = i - _alucard.height / 2;

				break;
			}

			else if (!(r == 0 && g == 42 && b == 254))
			{
				_alucard.boolset.gravityCheck = true;

				if (!_alucard.boolset.jumpCheck)
				{
					_alucard.y += 0.6f;

				}
				else if (_alucard.boolset.jumpCheck)
				{
					_alucard.y += 2.5f;
				}
			}

			//���ǰ� �浹.
			if ((r == 239 && g == 219 && b == 0))
			{
				if (_alucard.boolset.scaffold)
				{
					if (_alucard.boolset.jumpCheck)
					{
						_alucard.boolset.jumpCheck = false;
						_alucard.jumpCount = 0;
						Idle();
					}

					_alucard.boolset.gravityCheck = false;
					_alucard.y = i - _alucard.height / 2;
				}
			}
		}
		//Map_07 �� �ȼ� �浹 �����Դϴ�.
		if (SCENEMANAGER->getSceneNumber() == 7)
		{
			COLORREF color = GetPixel(IMAGEMANAGER->findImage("Map_07_Pixel")->getMemDC(), _alucard.x, i);

			int r = GetRValue(color);
			int g = GetGValue(color);
			int b = GetBValue(color);

			if ((r == 0 && g == 42 && b == 254))
			{
				if (_alucard.boolset.jumpCheck)
				{
					_alucard.boolset.jumpCheck = false;
					_alucard.jumpCount = 0;

					if (!_alucard.boolset.getDamage)
					Idle();
				}

				_alucard.boolset.gravityCheck = false;
				_alucard.y = i - _alucard.height / 2;

				break;
			}

			else if (!(r == 0 && g == 42 && b == 254))
			{
				_alucard.boolset.gravityCheck = true;

				if (!_alucard.boolset.jumpCheck)
				{
					_alucard.y += 0.6f;
				}
				else if (_alucard.boolset.jumpCheck)
				{
					_alucard.y += 2.5f;
				}
			}
		}
		//Map_08 �� �ȼ� �浹 �����Դϴ�.
		if (SCENEMANAGER->getSceneNumber() == 8)
		{
			COLORREF color = GetPixel(IMAGEMANAGER->findImage("Map_08_Pixel")->getMemDC(), _alucard.x, i);

			int r = GetRValue(color);
			int g = GetGValue(color);
			int b = GetBValue(color);

			if ((r == 0 && g == 42 && b == 254))
			{
				if (_alucard.boolset.jumpCheck)
				{
					_alucard.boolset.jumpCheck = false;
					_alucard.jumpCount = 0;

					if (!_alucard.boolset.getDamage)
					Idle();
				}

				_alucard.boolset.gravityCheck = false;
				_alucard.y = i - _alucard.height / 2;

				break;
			}

			else if (!(r == 0 && g == 42 && b == 254))
			{
				_alucard.boolset.gravityCheck = true;

				if (!_alucard.boolset.jumpCheck)
				{
					_alucard.y += 0.6f;
				}
				else if (_alucard.boolset.jumpCheck)
				{
					_alucard.y += 2.5f;
				}
			}
		}
		//Map_09 �� �ȼ� �浹 �����Դϴ�.
		if (SCENEMANAGER->getSceneNumber() == 9)
		{
			COLORREF color = GetPixel(IMAGEMANAGER->findImage("Map_08_1_Pixel")->getMemDC(), _alucard.x, i);

			int r = GetRValue(color);
			int g = GetGValue(color);
			int b = GetBValue(color);

			if ((r == 0 && g == 42 && b == 254))
			{
				if (_alucard.boolset.jumpCheck)
				{
					_alucard.boolset.jumpCheck = false;
					_alucard.jumpCount = 0;

					if (!_alucard.boolset.getDamage)
					Idle();
				}

				_alucard.boolset.gravityCheck = false;
				_alucard.y = i - _alucard.height / 2;

				break;
			}

			else if (!(r == 0 && g == 42 && b == 254))
			{
				_alucard.boolset.gravityCheck = true;

				if (!_alucard.boolset.jumpCheck)
				{
					_alucard.y += 0.6f;
				}
				else if (_alucard.boolset.jumpCheck)
				{
					_alucard.y += 2.5f;
				}
			}
		}
		//Map_10 �� �ȼ� �浹 �����Դϴ�.
		if(SCENEMANAGER->getSceneNumber() == 10)
		{
			COLORREF color = GetPixel(IMAGEMANAGER->findImage("Map_09_Pixel")->getMemDC(), _alucard.x, i);

			int r = GetRValue(color);
			int g = GetGValue(color);
			int b = GetBValue(color);

			if ((r == 0 && g == 42 && b == 254))
			{
				if (_alucard.boolset.jumpCheck)
				{
					_alucard.boolset.jumpCheck = false;
					_alucard.jumpCount = 0;

					if (!_alucard.boolset.getDamage)
					Idle();
				}

				_alucard.boolset.gravityCheck = false;
				_alucard.y = i - _alucard.height / 2;

				break;
			}

			else if (!(r == 0 && g == 42 && b == 254))
			{
				_alucard.boolset.gravityCheck = true;

				if (!_alucard.boolset.jumpCheck)
				{
					_alucard.y += 0.6f;
				}
				else if (_alucard.boolset.jumpCheck)
				{
					_alucard.y += 2.5f;
				}
			}
		}
		//Map_11 �� �ȼ� �浹 �����Դϴ�.
		if (SCENEMANAGER->getSceneNumber() == 11)
		{
			COLORREF color = GetPixel(IMAGEMANAGER->findImage("Map_10_Pixel")->getMemDC(), _alucard.x, i);

			int r = GetRValue(color);
			int g = GetGValue(color);
			int b = GetBValue(color);

			if ((r == 0 && g == 42 && b == 254))
			{
				if (_alucard.boolset.jumpCheck)
				{
					_alucard.boolset.jumpCheck = false;
					_alucard.jumpCount = 0;

					if (!_alucard.boolset.getDamage)
					Idle();
				}

				_alucard.boolset.gravityCheck = false;
				_alucard.y = i - _alucard.height / 2;

				break;
			}

			else if (!(r == 0 && g == 42 && b == 254))
			{
				_alucard.boolset.gravityCheck = true;

				if (!_alucard.boolset.jumpCheck)
				{
					_alucard.y += 0.6f;
				}
				else if (_alucard.boolset.jumpCheck)
				{
					_alucard.y += 2.5f;
				}
			}
		}
		//Map_12 �� �ȼ� �浹 �����Դϴ�.
		if (SCENEMANAGER->getSceneNumber() == 12)
		{
			COLORREF color = GetPixel(IMAGEMANAGER->findImage("Map_11_Pixel")->getMemDC(), _alucard.x, i);

			int r = GetRValue(color);
			int g = GetGValue(color);
			int b = GetBValue(color);

			if ((r == 0 && g == 42 && b == 254))
			{
				if (_alucard.boolset.jumpCheck)
				{
					_alucard.boolset.jumpCheck = false;
					_alucard.jumpCount = 0;

					if (!_alucard.boolset.getDamage)
					Idle();
				}

				_alucard.boolset.gravityCheck = false;
				_alucard.y = i - _alucard.height / 2;

				break;
			}

			else if (!(r == 0 && g == 42 && b == 254))
			{
				_alucard.boolset.gravityCheck = true;

				if (!_alucard.boolset.jumpCheck)
				{
					_alucard.y += 0.6f;
				}
				else if (_alucard.boolset.jumpCheck)
				{
					_alucard.y += 2.5f;
				}
			}

			if ((r == 239 && g == 219 && b == 0))
			{
				if (_alucard.boolset.scaffold)
				{
					if (_alucard.boolset.jumpCheck)
					{
						_alucard.boolset.jumpCheck = false;
						_alucard.jumpCount = 0;
						Idle();
					}

					_alucard.boolset.gravityCheck = false;
					_alucard.y = i - _alucard.height / 2;
				}
			}
		}
		//Map_13 �� �ȼ� �浹 �����Դϴ�.
		if (SCENEMANAGER->getSceneNumber() == 13)
		{
			COLORREF color = GetPixel(IMAGEMANAGER->findImage("Map_12_Pixel")->getMemDC(), _alucard.x, i);

			int r = GetRValue(color);
			int g = GetGValue(color);
			int b = GetBValue(color);

			if ((r == 0 && g == 42 && b == 254))
			{
				if (_alucard.boolset.jumpCheck)
				{
					_alucard.boolset.jumpCheck = false;
					_alucard.jumpCount = 0;

					if(!_alucard.boolset.getDamage)
					Idle();
				}

				_alucard.boolset.gravityCheck = false;
				_alucard.y = i - _alucard.height / 2;

				break;
			}

			else if (!(r == 0 && g == 42 && b == 254))
			{
				_alucard.boolset.gravityCheck = true;

				if (!_alucard.boolset.jumpCheck)
				{
					_alucard.y += 0.6f;
				}
				else if (_alucard.boolset.jumpCheck)
				{
					_alucard.y += 2.5f;
				}
			}
		}
		//Map_14 �� �ȼ� �浹 �����Դϴ�.
		if (SCENEMANAGER->getSceneNumber() == 14)
		{
			COLORREF color = GetPixel(IMAGEMANAGER->findImage("Map_13_Pixel")->getMemDC(), _alucard.x, i);

			int r = GetRValue(color);
			int g = GetGValue(color);
			int b = GetBValue(color);

			if ((r == 0 && g == 42 && b == 254))
			{
				if (_alucard.boolset.jumpCheck)
				{
					_alucard.boolset.jumpCheck = false;
					_alucard.jumpCount = 0;

					if (!_alucard.boolset.getDamage)
					Idle();
				}

				_alucard.boolset.gravityCheck = false;
				_alucard.y = i - _alucard.height / 2;

				break;
			}

			else if (!(r == 0 && g == 42 && b == 254))
			{
				_alucard.boolset.gravityCheck = true;

				if (!_alucard.boolset.jumpCheck)
				{
					_alucard.y += 0.6f;
				}
				else if (_alucard.boolset.jumpCheck)
				{
					_alucard.y += 2.5f;
				}
			}
		}
		//Map_15 �� �ȼ� �浹 �����Դϴ�.
		if (SCENEMANAGER->getSceneNumber() == 15)
		{
			COLORREF color = GetPixel(IMAGEMANAGER->findImage("Map_13_1_Pixel")->getMemDC(), _alucard.x, i);

			int r = GetRValue(color);
			int g = GetGValue(color);
			int b = GetBValue(color);

			if ((r == 0 && g == 42 && b == 254))
			{
				if (_alucard.boolset.jumpCheck)
				{
					_alucard.boolset.jumpCheck = false;
					_alucard.jumpCount = 0;

					if (!_alucard.boolset.getDamage)
					Idle();
				}

				_alucard.boolset.gravityCheck = false;
				_alucard.y = i - _alucard.height / 2;

				break;
			}

			else if (!(r == 0 && g == 42 && b == 254))
			{
				_alucard.boolset.gravityCheck = true;

				if (!_alucard.boolset.jumpCheck)
				{
					_alucard.y += 0.6f;
				}
				else if (_alucard.boolset.jumpCheck)
				{
					_alucard.y += 2.5f;
				}
			}
		}
		//Map_16 �� �ȼ� �浹 �����Դϴ�.
		if (SCENEMANAGER->getSceneNumber() == 16)
		{
			COLORREF color = GetPixel(IMAGEMANAGER->findImage("Map_14_Pixel")->getMemDC(), _alucard.x, i);

			int r = GetRValue(color);
			int g = GetGValue(color);
			int b = GetBValue(color);

			if ((r == 0 && g == 42 && b == 254))
			{
				if (_alucard.boolset.jumpCheck)
				{
					_alucard.boolset.jumpCheck = false;
					_alucard.jumpCount = 0;

					if (!_alucard.boolset.getDamage)
					Idle();
				}

				_alucard.boolset.gravityCheck = false;
				_alucard.y = i - _alucard.height / 2;

				break;
			}

			else if (!(r == 0 && g == 42 && b == 254))
			{
				_alucard.boolset.gravityCheck = true;

				if (!_alucard.boolset.jumpCheck)
				{
					_alucard.y += 0.6f;
				}
				else if (_alucard.boolset.jumpCheck)
				{
					_alucard.y += 2.5f;
				}
			}
		}
		//Map_17 �� �ȼ� �浹 �����Դϴ�
		if (SCENEMANAGER->getSceneNumber() == 17)
		{
			COLORREF color = GetPixel(IMAGEMANAGER->findImage("Map_15_Pixel")->getMemDC(), _alucard.x, i);

			int r = GetRValue(color);
			int g = GetGValue(color);
			int b = GetBValue(color);

			if ((r == 0 && g == 42 && b == 254))
			{
				if (_alucard.boolset.jumpCheck)
				{
					_alucard.boolset.jumpCheck = false;
					_alucard.jumpCount = 0;

					if (!_alucard.boolset.getDamage)
					Idle();
				}

				_alucard.boolset.gravityCheck = false;
				_alucard.y = i - _alucard.height / 2;

				break;
			}

			else if (!(r == 0 && g == 42 && b == 254))
			{
				_alucard.boolset.gravityCheck = true;

				if (!_alucard.boolset.jumpCheck)
				{
					_alucard.y += 0.6f;
				}
				else if (_alucard.boolset.jumpCheck)
				{
					_alucard.y += 2.5f;
				}
			}
		}
		//Map_18 �� �ȼ� �浹 �����Դϴ�.
		if (SCENEMANAGER->getSceneNumber() == 18)
		{
			COLORREF color = GetPixel(IMAGEMANAGER->findImage("Map_16_Pixel")->getMemDC(), _alucard.x, i);

			int r = GetRValue(color);
			int g = GetGValue(color);
			int b = GetBValue(color);

			if ((r == 0 && g == 42 && b == 254))
			{
				if (_alucard.boolset.jumpCheck)
				{
					_alucard.boolset.jumpCheck = false;
					_alucard.jumpCount = 0;

					if (!_alucard.boolset.getDamage)
					Idle();
				}

				_alucard.boolset.gravityCheck = false;
				_alucard.y = i - _alucard.height / 2;

				break;
			}

			else if (!(r == 0 && g == 42 && b == 254))
			{
				_alucard.boolset.gravityCheck = true;

				if (!_alucard.boolset.jumpCheck)
				{
					_alucard.y += 0.6f;
				}
				else if (_alucard.boolset.jumpCheck)
				{
					_alucard.y += 2.5f;
				}
			}
		}
	}
}
//Wall Pixel Collision
void Alucard::CharacterPixelWall()
{
	_probeX = _alucard.x;

	for (int i = _probeX - 24; i < _probeX + 24; ++i)
	{
		//Map_01 �� �ȼ� �浹 �����Դϴ�.
		if (SCENEMANAGER->getSceneNumber() == 1)
		{
			COLORREF color = GetPixel(IMAGEMANAGER->findImage("Map_01_Pixel")->getMemDC(), i, _alucard.y);

			int r = GetRValue(color);
			int g = GetGValue(color);
			int b = GetBValue(color);

			if ((r == 150 && g == 254 && b == 0))
			{
				if (KEYMANAGER->isStayKeyDown(VK_LEFT))
				{
					_alucard.x = _probeX + _alucard.moveSpeed;
				}

				else if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
				{
					_alucard.x = _probeX - _alucard.moveSpeed;
				}

				break;
			}

			else if ((r == 150 && g == 254 && b == 0))
			{

			}
		}
		//Map_02 �� �ȼ� �浹 �����Դϴ�.
		if (SCENEMANAGER->getSceneNumber() == 2)
		{
			COLORREF color = GetPixel(IMAGEMANAGER->findImage("Map_02_Pixel")->getMemDC(), i, _alucard.y);

			int r = GetRValue(color);
			int g = GetGValue(color);
			int b = GetBValue(color);

			if ((r == 150 && g == 254 && b == 0))
			{
				if (_alucard.direction == DirectionLeft)
				{
					_alucard.x = _probeX + _alucard.moveSpeed;
				}

				else if (_alucard.direction == DirectionRight)
				{
					_alucard.x = _probeX - _alucard.moveSpeed;
				}

				break;
			}

			else if ((r == 150 && g == 254 && b == 0))
			{

			}
		}
		//Map_03 �� �ȼ� �浹 �����Դϴ�.
		if (SCENEMANAGER->getSceneNumber() == 3)
		{
			COLORREF color = GetPixel(IMAGEMANAGER->findImage("Map_03_Pixel")->getMemDC(), i, _alucard.y);

			int r = GetRValue(color);
			int g = GetGValue(color);
			int b = GetBValue(color);

			if ((r == 150 && g == 254 && b == 0))
			{
				if (_alucard.direction == DirectionLeft)
				{
					_alucard.x = _probeX + _alucard.moveSpeed;
				}

				else if (_alucard.direction == DirectionRight)
				{
					_alucard.x = _probeX - _alucard.moveSpeed;
				}

				break;
			}

			else if ((r == 150 && g == 254 && b == 0))
			{

			}
		}
		//Map_04 �� �ȼ� �浹 �����Դϴ�.
		if (SCENEMANAGER->getSceneNumber() == 4)
		{
			COLORREF color = GetPixel(IMAGEMANAGER->findImage("Map_04_Pixel")->getMemDC(), i, _alucard.y);

			int r = GetRValue(color);
			int g = GetGValue(color);
			int b = GetBValue(color);

			if ((r == 150 && g == 254 && b == 0))
			{
				if (_alucard.direction == DirectionLeft)
				{
					_alucard.x = _probeX + _alucard.moveSpeed;
				}

				else if (_alucard.direction == DirectionRight)
				{
					_alucard.x = _probeX - _alucard.moveSpeed;
				}

				break;
			}

			else if ((r == 150 && g == 254 && b == 0))
			{

			}
		}
		//Map_05 �� �ȼ� �浹 �����Դϴ�.
		if (SCENEMANAGER->getSceneNumber() == 5)
		{
			COLORREF color = GetPixel(IMAGEMANAGER->findImage("Map_05_Pixel")->getMemDC(), i, _alucard.y);

			int r = GetRValue(color);
			int g = GetGValue(color);
			int b = GetBValue(color);

			if ((r == 150 && g == 254 && b == 0))
			{
				if (_alucard.direction == DirectionLeft)
				{
					_alucard.x = _probeX + _alucard.moveSpeed;
				}

				else if (_alucard.direction == DirectionRight)
				{
					_alucard.x = _probeX - _alucard.moveSpeed;
				}

				break;
			}

			else if ((r == 150 && g == 254 && b == 0))
			{

			}
		}
		//Map_06 �� �ȼ� �浹 �����Դϴ�.
		if (SCENEMANAGER->getSceneNumber() == 6)
		{
			COLORREF color = GetPixel(IMAGEMANAGER->findImage("Map_06_Pixel")->getMemDC(), i, _alucard.y);

			int r = GetRValue(color);
			int g = GetGValue(color);
			int b = GetBValue(color);

			if ((r == 150 && g == 254 && b == 0))
			{

				if (_alucard.direction == DirectionLeft)
				{
					_alucard.x = _probeX + _alucard.moveSpeed;
				}

				else if (_alucard.direction == DirectionRight)
				{
					_alucard.x = _probeX - _alucard.moveSpeed;
				}

				break;
			}

			else if ((r == 150 && g == 254 && b == 0))
			{

			}
		}
		//Map_07 �� �ȼ� �浹 �����Դϴ�.
		if (SCENEMANAGER->getSceneNumber() == 7)
		{
			COLORREF color = GetPixel(IMAGEMANAGER->findImage("Map_07_Pixel")->getMemDC(), i, _alucard.y);

			int r = GetRValue(color);
			int g = GetGValue(color);
			int b = GetBValue(color);

			if ((r == 150 && g == 254 && b == 0))
			{
				if (_alucard.direction == DirectionLeft)
				{
					_alucard.x = _probeX + _alucard.moveSpeed;
				}

				else if (_alucard.direction == DirectionRight)
				{
					_alucard.x = _probeX - _alucard.moveSpeed;
				}

				break;
			}

			else if ((r == 150 && g == 254 && b == 0))
			{

			}
		}
		//Map_08 �� �ȼ� �浹 �����Դϴ�.
		if (SCENEMANAGER->getSceneNumber() == 8)
		{
			COLORREF color = GetPixel(IMAGEMANAGER->findImage("Map_08_Pixel")->getMemDC(), i, _alucard.y);

			int r = GetRValue(color);
			int g = GetGValue(color);
			int b = GetBValue(color);

			if ((r == 150 && g == 254 && b == 0))
			{
				if (_alucard.direction == DirectionLeft)
				{
					_alucard.x = _probeX + _alucard.moveSpeed;
				}

				else if (_alucard.direction == DirectionRight)
				{
					_alucard.x = _probeX - _alucard.moveSpeed;
				}

				break;
			}

			else if ((r == 150 && g == 254 && b == 0))
			{

			}
		}
		//Map_09 �� �ȼ� �浹 �����Դϴ�.
		if (SCENEMANAGER->getSceneNumber() == 9)
		{
			COLORREF color = GetPixel(IMAGEMANAGER->findImage("Map_08_1_Pixel")->getMemDC(), i, _alucard.y);

			int r = GetRValue(color);
			int g = GetGValue(color);
			int b = GetBValue(color);

			if ((r == 150 && g == 254 && b == 0))
			{
				if (_alucard.direction == DirectionLeft)
				{
					_alucard.x = _probeX + _alucard.moveSpeed;
				}

				else if (_alucard.direction == DirectionRight)
				{
					_alucard.x = _probeX - _alucard.moveSpeed;
				}

				break;
			}

			else if ((r == 150 && g == 254 && b == 0))
			{

			}
		}
		//Map_10 �� �ȼ� �浹 �����Դϴ�.
		if (SCENEMANAGER->getSceneNumber() == 10)
		{
			COLORREF color = GetPixel(IMAGEMANAGER->findImage("Map_09_Pixel")->getMemDC(), i, _alucard.y);

			int r = GetRValue(color);
			int g = GetGValue(color);
			int b = GetBValue(color);

			if ((r == 150 && g == 254 && b == 0))
			{
				if (_alucard.direction == DirectionLeft)
				{
					_alucard.x = _probeX + _alucard.moveSpeed;
				}

				else if (_alucard.direction == DirectionRight)
				{
					_alucard.x = _probeX - _alucard.moveSpeed;
				}

				break;
			}

			else if ((r == 150 && g == 254 && b == 0))
			{

			}
		}
		//Map_11 �� �ȼ� �浹 �����Դϴ�.
		if (SCENEMANAGER->getSceneNumber() == 11)
		{
			COLORREF color = GetPixel(IMAGEMANAGER->findImage("Map_10_Pixel")->getMemDC(), i, _alucard.y);

			int r = GetRValue(color);
			int g = GetGValue(color);
			int b = GetBValue(color);

			if ((r == 150 && g == 254 && b == 0))
			{
				if (_alucard.direction == DirectionLeft)
				{
					_alucard.x = _probeX + _alucard.moveSpeed;
				}

				else if (_alucard.direction == DirectionRight)
				{
					_alucard.x = _probeX - _alucard.moveSpeed;
				}

				break;
			}

			else if ((r == 150 && g == 254 && b == 0))
			{

			}
		}
		//Map_12 �� �ȼ� �浹 �����Դϴ�.
		if (SCENEMANAGER->getSceneNumber() == 12)
		{
			COLORREF color = GetPixel(IMAGEMANAGER->findImage("Map_11_Pixel")->getMemDC(), i, _alucard.y + 15);

			int r = GetRValue(color);
			int g = GetGValue(color);
			int b = GetBValue(color);

			if ((r == 150 && g == 254 && b == 0))
			{
				if (_alucard.direction == DirectionLeft)
				{
					_alucard.x = _probeX + _alucard.moveSpeed;
				}

				else if (_alucard.direction == DirectionRight)
				{
					_alucard.x = _probeX - _alucard.moveSpeed;
				}

				break;
			}

			else if ((r == 150 && g == 254 && b == 0))
			{

			}
		}
		//Map_13 �� �ȼ� �浹 �����Դϴ�.
		if (SCENEMANAGER->getSceneNumber() == 13)
		{
			COLORREF color = GetPixel(IMAGEMANAGER->findImage("Map_12_Pixel")->getMemDC(), i, _alucard.y);

			int r = GetRValue(color);
			int g = GetGValue(color);
			int b = GetBValue(color);

			if ((r == 150 && g == 254 && b == 0))
			{
				if (_alucard.direction == DirectionLeft)
				{
					_alucard.x = _probeX + _alucard.moveSpeed;
				}

				else if (_alucard.direction == DirectionRight)
				{
					_alucard.x = _probeX - _alucard.moveSpeed;
				}

				break;
			}

			else if ((r == 150 && g == 254 && b == 0))
			{

			}
		}//Map_14 �� �ȼ� �浹 �����Դϴ�.
		//Map_14 �� �ȼ� �浹 �����Դϴ�.
		if (SCENEMANAGER->getSceneNumber() == 14)
		{
			COLORREF color = GetPixel(IMAGEMANAGER->findImage("Map_13_Pixel")->getMemDC(), i, _alucard.y);

			int r = GetRValue(color);
			int g = GetGValue(color);
			int b = GetBValue(color);

			if ((r == 150 && g == 254 && b == 0))
			{
				if (_alucard.direction == DirectionLeft)
				{
					_alucard.x = _probeX + _alucard.moveSpeed;
				}

				else if (_alucard.direction == DirectionRight)
				{
					_alucard.x = _probeX - _alucard.moveSpeed;
				}

				break;
			}

			else if ((r == 150 && g == 254 && b == 0))
			{

			}
		}
		//Map_15 �� �ȼ� �浹 �����Դϴ�.
		if (SCENEMANAGER->getSceneNumber() == 15)
		{
			COLORREF color = GetPixel(IMAGEMANAGER->findImage("Map_13_1_Pixel")->getMemDC(), i, _alucard.y);

			int r = GetRValue(color);
			int g = GetGValue(color);
			int b = GetBValue(color);

			if ((r == 150 && g == 254 && b == 0))
			{
				if (_alucard.direction == DirectionLeft)
				{
					_alucard.x = _probeX + _alucard.moveSpeed;
				}

				else if (_alucard.direction == DirectionRight)
				{
					_alucard.x = _probeX - _alucard.moveSpeed;
				}

				break;
			}

			else if ((r == 150 && g == 254 && b == 0))
			{

			}
		}
		//Map_16 �� �ȼ� �浹 �����Դϴ�.
		if (SCENEMANAGER->getSceneNumber() == 16)
		{
			COLORREF color = GetPixel(IMAGEMANAGER->findImage("Map_14_Pixel")->getMemDC(), i, _alucard.y);

			int r = GetRValue(color);
			int g = GetGValue(color);
			int b = GetBValue(color);

			if ((r == 150 && g == 254 && b == 0))
			{
				if (_alucard.direction == DirectionLeft)
				{
					_alucard.x = _probeX + _alucard.moveSpeed;
				}

				else if (_alucard.direction == DirectionRight)
				{
					_alucard.x = _probeX - _alucard.moveSpeed;
				}

				break;
			}

			else if ((r == 150 && g == 254 && b == 0))
			{

			}
		}
		//Map_17 �� �ȼ� �浹 �����Դϴ�.
		if (SCENEMANAGER->getSceneNumber() == 17)
		{
			COLORREF color = GetPixel(IMAGEMANAGER->findImage("Map_15_Pixel")->getMemDC(), i, _alucard.y);

			int r = GetRValue(color);
			int g = GetGValue(color);
			int b = GetBValue(color);

			if ((r == 150 && g == 254 && b == 0))
			{
				if (_alucard.direction == DirectionLeft)
				{
					_alucard.x = _probeX + _alucard.moveSpeed;
				}

				else if (_alucard.direction == DirectionRight)
				{
					_alucard.x = _probeX - _alucard.moveSpeed;
				}

				break;
			}

			else if ((r == 150 && g == 254 && b == 0))
			{

			}
		}
		//Map_18 �� �ȼ� �浹 �����Դϴ�.
		if (SCENEMANAGER->getSceneNumber() == 18)
		{
			COLORREF color = GetPixel(IMAGEMANAGER->findImage("Map_16_Pixel")->getMemDC(), i, _alucard.y);

			int r = GetRValue(color);
			int g = GetGValue(color);
			int b = GetBValue(color);

			if ((r == 150 && g == 254 && b == 0))
			{
				if (_alucard.direction == DirectionLeft)
				{
					_alucard.x = _probeX + _alucard.moveSpeed;
				}

				else if (_alucard.direction == DirectionRight)
				{
					_alucard.x = _probeX - _alucard.moveSpeed;
				}

				break;
			}

			else if ((r == 150 && g == 254 && b == 0))
			{

			}
		}
	}
}
//Top Pixel Collision
void Alucard::CharacterPixelTop()
{
	_probeY2 = _alucard.y - _alucard.height / 2;

	for (int i = _probeY2 - 4; i < _probeY2 + 5; ++i)
	{
		//Map_01 �ȼ� �浹 
		if (SCENEMANAGER->getSceneNumber() == 1)
		{
			COLORREF color = GetPixel(IMAGEMANAGER->findImage("Map_01_Pixel")->getMemDC(), _alucard.x, i);

			int r = GetRValue(color);
			int g = GetGValue(color);
			int b = GetBValue(color);

			if ((r == 246 && g == 14 && b == 14))
			{
				//�̰� ���߿� �� ã�ƺ���..�Ϻ��ϰ� õ�忡 �پ��������ִ� �ڵ�.
				//�Ӹ��� �ȼ� ����Ǹ� ����ī��Ʈ ���� ���ҽ��ϴ�.
				_alucard.y = i + _alucard.height / 2 + _alucard.jumpPower / 3.5;
				_alucard.jumpCount = 2;

			}

			else if ((r == 150 && g == 254 && b == 0))
			{

			}

			break;
		}
		//Map_02 �ȼ� �浹
		if (SCENEMANAGER->getSceneNumber() == 2)
		{
			COLORREF color = GetPixel(IMAGEMANAGER->findImage("Map_02_Pixel")->getMemDC(), _alucard.x, i);

			int r = GetRValue(color);
			int g = GetGValue(color);
			int b = GetBValue(color);

			if ((r == 246 && g == 14 && b == 14))
			{
				_alucard.y = i + _alucard.height / 2 + _alucard.jumpPower / 3.5;
				//_alucard.jumpCount = 2;
			}

			else if ((r == 150 && g == 254 && b == 0))
			{

			}
		}
		//Map_03 �ȼ� �浹
		if (SCENEMANAGER->getSceneNumber() == 3)
		{
			COLORREF color = GetPixel(IMAGEMANAGER->findImage("Map_03_Pixel")->getMemDC(), _alucard.x, i);

			int r = GetRValue(color);
			int g = GetGValue(color);
			int b = GetBValue(color);

			if ((r == 246 && g == 14 && b == 14))
			{
				_alucard.y = i + _alucard.height / 2 + _alucard.jumpPower / 3.5;
				//_alucard.jumpCount = 2;
			}

			else if ((r == 150 && g == 254 && b == 0))
			{

			}
		}
		//Map_04 �ȼ� �浹
		if (SCENEMANAGER->getSceneNumber() == 4)
		{
			COLORREF color = GetPixel(IMAGEMANAGER->findImage("Map_04_Pixel")->getMemDC(), _alucard.x, i);

			int r = GetRValue(color);
			int g = GetGValue(color);
			int b = GetBValue(color);

			if ((r == 246 && g == 14 && b == 14))
			{
				_alucard.y = i + _alucard.height / 2 + _alucard.jumpPower / 3.5;
			}

			else if ((r == 150 && g == 254 && b == 0))
			{

			}
		}
		//Map_05 �ȼ� �浹 ����
		if (SCENEMANAGER->getSceneNumber() == 5)
		{
			COLORREF color = GetPixel(IMAGEMANAGER->findImage("Map_05_Pixel")->getMemDC(), _alucard.x, i);

			int r = GetRValue(color);
			int g = GetGValue(color);
			int b = GetBValue(color);

			if ((r == 246 && g == 14 && b == 14))
			{
				_alucard.y = i + _alucard.height / 2 + _alucard.jumpPower / 3.5;
			}

			else if ((r == 150 && g == 254 && b == 0))
			{

			}
		}
		//Map_06 �ȼ� �浹 ����
		if (SCENEMANAGER->getSceneNumber() == 6)
		{
			COLORREF color = GetPixel(IMAGEMANAGER->findImage("Map_06_Pixel")->getMemDC(), _alucard.x, i);

			int r = GetRValue(color);
			int g = GetGValue(color);
			int b = GetBValue(color);

			if ((r == 246 && g == 14 && b == 14))
			{
				_alucard.y = i + _alucard.height / 2 + _alucard.jumpPower / 3.5;
			}

			else if ((r == 150 && g == 254 && b == 0))
			{

			}
		}
		//Map_07 �ȼ� �浹 ����.
		if (SCENEMANAGER->getSceneNumber() == 7)
		{
			COLORREF color = GetPixel(IMAGEMANAGER->findImage("Map_07_Pixel")->getMemDC(), _alucard.x, i);

			int r = GetRValue(color);
			int g = GetGValue(color);
			int b = GetBValue(color);

			if ((r == 246 && g == 14 && b == 14))
			{
				_alucard.y = i + _alucard.height / 2 + _alucard.jumpPower / 3.5;
			}

			else if ((r == 150 && g == 254 && b == 0))
			{

			}
		}
		//Map_08 �ȼ� �浹 ����.
		if (SCENEMANAGER->getSceneNumber() == 8)
		{
			COLORREF color = GetPixel(IMAGEMANAGER->findImage("Map_08_Pixel")->getMemDC(), _alucard.x, i);

			int r = GetRValue(color);
			int g = GetGValue(color);
			int b = GetBValue(color);

			if ((r == 246 && g == 14 && b == 14))
			{
				_alucard.y = i + _alucard.height / 2 + _alucard.jumpPower / 3.5;
			}

			else if ((r == 150 && g == 254 && b == 0))
			{

			}
		}
		//Map_09 �ȼ� �浹 ����.
		if (SCENEMANAGER->getSceneNumber() == 9)
		{
			COLORREF color = GetPixel(IMAGEMANAGER->findImage("Map_08_1_Pixel")->getMemDC(), _alucard.x, i);

			int r = GetRValue(color);
			int g = GetGValue(color);
			int b = GetBValue(color);

			if ((r == 246 && g == 14 && b == 14))
			{
				_alucard.y = i + _alucard.height / 2 + _alucard.jumpPower / 3.5;
			}

			else if ((r == 150 && g == 254 && b == 0))
			{

			}
		}
		//Map_10 �ȼ� �浹 ����
		if (SCENEMANAGER->getSceneNumber() == 10)
		{
			COLORREF color = GetPixel(IMAGEMANAGER->findImage("Map_09_Pixel")->getMemDC(), _alucard.x, i);

			int r = GetRValue(color);
			int g = GetGValue(color);
			int b = GetBValue(color);

			if ((r == 246 && g == 14 && b == 14))
			{
				_alucard.y = i + _alucard.height / 2 + _alucard.jumpPower / 3.5;
			}

			else if ((r == 150 && g == 254 && b == 0))
			{

			}
		}
		//Map_11 �ȼ� �浹 ����.
		if (SCENEMANAGER->getSceneNumber() == 11)
		{
			COLORREF color = GetPixel(IMAGEMANAGER->findImage("Map_10_Pixel")->getMemDC(), _alucard.x, i);

			int r = GetRValue(color);
			int g = GetGValue(color);
			int b = GetBValue(color);

			if ((r == 246 && g == 14 && b == 14))
			{
				_alucard.y = i + _alucard.height / 2 + _alucard.jumpPower / 3.5;
			}

			else if ((r == 150 && g == 254 && b == 0))
			{

			}
		}
		//Map_12 �ȼ� �浹 ����
		if (SCENEMANAGER->getSceneNumber() == 12)
		{
			COLORREF color = GetPixel(IMAGEMANAGER->findImage("Map_11_Pixel")->getMemDC(), _alucard.x, i);

			int r = GetRValue(color);
			int g = GetGValue(color);
			int b = GetBValue(color);

			if ((r == 246 && g == 14 && b == 14))
			{
				_alucard.y = i + _alucard.height / 2 + _alucard.jumpPower / 3.5;
			}

			else if ((r == 150 && g == 254 && b == 0))
			{

			}
		}
		//Map_13 �ȼ� �浹 ����
		if (SCENEMANAGER->getSceneNumber() == 13)
		{
			COLORREF color = GetPixel(IMAGEMANAGER->findImage("Map_12_Pixel")->getMemDC(), _alucard.x, i);

			int r = GetRValue(color);
			int g = GetGValue(color);
			int b = GetBValue(color);

			if ((r == 246 && g == 14 && b == 14))
			{
				_alucard.y = i + _alucard.height / 2 + _alucard.jumpPower / 3.5;
			}

			else if ((r == 150 && g == 254 && b == 0))
			{

			}
		}
		//Map_14 �ȼ� �浹 ����
		if (SCENEMANAGER->getSceneNumber() == 14)
		{
			COLORREF color = GetPixel(IMAGEMANAGER->findImage("Map_13_Pixel")->getMemDC(), _alucard.x, i);

			int r = GetRValue(color);
			int g = GetGValue(color);
			int b = GetBValue(color);

			if ((r == 246 && g == 14 && b == 14))
			{
				_alucard.y = i + _alucard.height / 2 + _alucard.jumpPower / 3.5;
			}

			else if ((r == 150 && g == 254 && b == 0))
			{

			}
		}
		//Map_15 �ȼ� �浹 ����
		if (SCENEMANAGER->getSceneNumber() == 15)
		{
			COLORREF color = GetPixel(IMAGEMANAGER->findImage("Map_13_1_Pixel")->getMemDC(), _alucard.x, i);

			int r = GetRValue(color);
			int g = GetGValue(color);
			int b = GetBValue(color);

			if ((r == 246 && g == 14 && b == 14))
			{
				_alucard.y = i + _alucard.height / 2 + _alucard.jumpPower / 3.5;
			}

			else if ((r == 150 && g == 254 && b == 0))
			{

			}
		}
		//Map_16 �ȼ� �浹 ����
		if (SCENEMANAGER->getSceneNumber() == 16)
		{
			COLORREF color = GetPixel(IMAGEMANAGER->findImage("Map_14_Pixel")->getMemDC(), _alucard.x, i);

			int r = GetRValue(color);
			int g = GetGValue(color);
			int b = GetBValue(color);

			if ((r == 246 && g == 14 && b == 14))
			{
				_alucard.y = i + _alucard.height / 2 + _alucard.jumpPower / 3.5;
			}

			else if ((r == 150 && g == 254 && b == 0))
			{

			}
		}
		//Map_17 �ȼ� �浹 ����
		if (SCENEMANAGER->getSceneNumber() == 17)
		{
			COLORREF color = GetPixel(IMAGEMANAGER->findImage("Map_15_Pixel")->getMemDC(), _alucard.x, i);

			int r = GetRValue(color);
			int g = GetGValue(color);
			int b = GetBValue(color);

			if ((r == 246 && g == 14 && b == 14))
			{
				_alucard.y = i + _alucard.height / 2 + _alucard.jumpPower / 3.5;
			}

			else if ((r == 150 && g == 254 && b == 0))
			{

			}
		}
		//Map_18 �ȼ� �浹 ����
		if (SCENEMANAGER->getSceneNumber() == 18)
		{
			COLORREF color = GetPixel(IMAGEMANAGER->findImage("Map_16_Pixel")->getMemDC(), _alucard.x, i);

			int r = GetRValue(color);
			int g = GetGValue(color);
			int b = GetBValue(color);

			if ((r == 246 && g == 14 && b == 14))
			{
				_alucard.y = i + _alucard.height / 2 + _alucard.jumpPower / 3.5;
			}

			else if ((r == 150 && g == 254 && b == 0))
			{

			}
		}
	}

}


