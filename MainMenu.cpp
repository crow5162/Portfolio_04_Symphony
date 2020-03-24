#include "stdafx.h"
#include "MainMenu.h"

HRESULT MainMenu::init()
{
	_isStart = false;
	_startGame = false;
	_alphaVal = 0;
	_pressButtonCount = 0;
	_startLightAlphaval = 255;
	_gameStartBlackAlpha = 0;

	_selectBat = IMAGEMANAGER->findImage("Main_SelectBat");
	_currentX = _currentY = 0;
	_frameCount = 0;

	_select = StartGame;

	return S_OK;
}

void MainMenu::update()
{
	if (!_isStart)
	{
		_pressButtonCount++;

		if (_pressButtonCount > 50 && _pressButtonCount < 100)
		{
			_alphaVal = 0;
		}
		else if (_pressButtonCount < 50)
		{
			_alphaVal = 255;
		}
		else if (_pressButtonCount > 100)
		{
			_pressButtonCount = 0;
		}

		_startLightAlphaval--;

		if (_startLightAlphaval < 0)
		{
			_startLightAlphaval = 0;
		}

		if (KEYMANAGER->isOnceKeyDown('A'))
		{
			_isStart = true;
		}
	}

	if (_isStart && !_startGame)
	{
		_startLightAlphaval = 0;

		SelectBatFrameCounter();

		if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
		{
			_select = ExitGame;
		}
		else if (KEYMANAGER->isOnceKeyDown(VK_UP))
		{
			_select = StartGame;
		}

		if (_select == ExitGame)
		{
			if (KEYMANAGER->isOnceKeyDown('A'))
			{
				PostQuitMessage(0);
			}
		}
		else if (_select == StartGame)
		{
			if (KEYMANAGER->isOnceKeyDown('A'))
			{
				_startGame = true;
			}
		}
	}

	if (_startGame)
	{
		_gameStartBlackAlpha += 2;
	}

	if (_startGame && _gameStartBlackAlpha == 250)
	{
		SCENEMANAGER->changeScene("Map_01");
	}
}

void MainMenu::render()
{
	IMAGEMANAGER->findImage("Main_Background")->render(getMemDC(), 0, 0);
	IMAGEMANAGER->findImage("Main_Logo")->render(getMemDC(), 50, 25);
	IMAGEMANAGER->findImage("Main_Konami")->render(getMemDC(), 25, 700);

	//Press Button Flashing
	if (!_isStart)
	{
		IMAGEMANAGER->findImage("Main_Pressbutton")->alphaRender(getMemDC(), 150, 600, _alphaVal);
		IMAGEMANAGER->findImage("Main_StartLight")->alphaRender(getMemDC(), 0, 0, _startLightAlphaval);
	}
	if (_isStart)
	{
		IMAGEMANAGER->findImage("Main_StartButton")->render(getMemDC(), 300, 480);
		IMAGEMANAGER->findImage("Main_ExitButton")->render(getMemDC(), 300, 570);

		//게임 선택하는 프레임 이미지 박쥐
		if (_select == StartGame)
		{
			_selectBat->frameRender(getMemDC(), 220, 480, _currentX, _currentY);
		}
		else if (_select == ExitGame)
		{
			_selectBat->frameRender(getMemDC(), 220, 570, _currentX, _currentY);
		}
	}

	IMAGEMANAGER->findImage("UIStart")->alphaRender(getMemDC(), 0, 0, _gameStartBlackAlpha);
}

void MainMenu::release()
{
}

void MainMenu::SelectBatFrameCounter()
{
	_frameCount++;
	_currentY = 0;

	if(_frameCount % 10 == 0)
	{
		_currentX++;

		if (_currentX > _selectBat->getMaxFrameX())
		{
			_currentX = 0;
		}
	}
}
