#include "stdafx.h"
#include "Alucard.h"

//Ground Pixel Collision
void Alucard::CharacterPixelGround()
{
	_probeY = _alucard.y + _alucard.height / 2;
	
	for (int i = _probeY - 7; i < _probeY + 5; ++i)
	{
		//Map_01 의 픽셀 충돌 설정입니다.
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
		//Map_02 의 픽셀 충돌 설정입니다.
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
		//Map_03 의 픽셀 충돌 설정입니다.
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
		//Map_04 의 픽셀 충돌 설정입니다.
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
		//Map_05 의 픽셀 충돌 설정입니다.
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
		//Map_06 의 픽셀 충돌 설정입니다.
		if (SCENEMANAGER->getSceneNumber() == 6)
		{
			COLORREF color = GetPixel(IMAGEMANAGER->findImage("Map_06_Pixel")->getMemDC(), _alucard.x, i);

			int r = GetRValue(color);
			int g = GetGValue(color);
			int b = GetBValue(color);

			//땅과의 충돌.
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

			//발판과 충돌.
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
		//Map_07 의 픽셀 충돌 설정입니다.
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
		//Map_08 의 픽셀 충돌 설정입니다.
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
		//Map_09 의 픽셀 충돌 설정입니다.
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
		//Map_10 의 픽셀 충돌 설정입니다.
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
		//Map_11 의 픽셀 충돌 설정입니다.
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
		//Map_12 의 픽셀 충돌 설정입니다.
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
		//Map_13 의 픽셀 충돌 설정입니다.
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
		//Map_14 의 픽셀 충돌 설정입니다.
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
		//Map_15 의 픽셀 충돌 설정입니다.
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
		//Map_16 의 픽셀 충돌 설정입니다.
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
		//Map_17 의 픽셀 충돌 설정입니다
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
		//Map_18 의 픽셀 충돌 설정입니다.
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
		//Map_01 의 픽셀 충돌 설정입니다.
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
		//Map_02 의 픽셀 충돌 설정입니다.
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
		//Map_03 의 픽셀 충돌 설정입니다.
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
		//Map_04 의 픽셀 충돌 설정입니다.
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
		//Map_05 의 픽셀 충돌 설정입니다.
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
		//Map_06 의 픽셀 충돌 설정입니다.
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
		//Map_07 의 픽셀 충돌 설정입니다.
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
		//Map_08 의 픽셀 충돌 설정입니다.
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
		//Map_09 의 픽셀 충돌 설정입니다.
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
		//Map_10 의 픽셀 충돌 설정입니다.
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
		//Map_11 의 픽셀 충돌 설정입니다.
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
		//Map_12 의 픽셀 충돌 설정입니다.
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
		//Map_13 의 픽셀 충돌 설정입니다.
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
		}//Map_14 의 픽셀 충돌 설정입니다.
		//Map_14 의 픽셀 충돌 설정입니다.
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
		//Map_15 의 픽셀 충돌 설정입니다.
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
		//Map_16 의 픽셀 충돌 설정입니다.
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
		//Map_17 의 픽셀 충돌 설정입니다.
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
		//Map_18 의 픽셀 충돌 설정입니다.
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
		//Map_01 픽셀 충돌 
		if (SCENEMANAGER->getSceneNumber() == 1)
		{
			COLORREF color = GetPixel(IMAGEMANAGER->findImage("Map_01_Pixel")->getMemDC(), _alucard.x, i);

			int r = GetRValue(color);
			int g = GetGValue(color);
			int b = GetBValue(color);

			if ((r == 246 && g == 14 && b == 14))
			{
				//이거 나중에 꼭 찾아보자..완벽하게 천장에 붙어있을수있는 코드.
				//머리에 픽셀 검출되면 점프카운트 막아 놓았습니다.
				_alucard.y = i + _alucard.height / 2 + _alucard.jumpPower / 3.5;
				_alucard.jumpCount = 2;

			}

			else if ((r == 150 && g == 254 && b == 0))
			{

			}

			break;
		}
		//Map_02 픽셀 충돌
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
		//Map_03 픽셀 충돌
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
		//Map_04 픽셀 충돌
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
		//Map_05 픽셀 충돌 설정
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
		//Map_06 픽셀 충돌 설정
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
		//Map_07 픽셀 충돌 설정.
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
		//Map_08 픽셀 충돌 설정.
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
		//Map_09 픽셀 충돌 설정.
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
		//Map_10 픽셀 충돌 설정
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
		//Map_11 픽셀 충돌 설정.
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
		//Map_12 픽셀 충돌 설정
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
		//Map_13 픽셀 충돌 설정
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
		//Map_14 픽셀 충돌 설정
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
		//Map_15 픽셀 충돌 설정
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
		//Map_16 픽셀 충돌 설정
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
		//Map_17 픽셀 충돌 설정
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
		//Map_18 픽셀 충돌 설정
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


