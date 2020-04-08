#pragma once
#include "gameNode.h"

enum GameModeSelect
{
	StartGame,
	ExitGame
};

class MainMenu : public gameNode
{
private:

	bool _isStart;
	bool _startGame;
	int _alphaVal;
	int _pressButtonCount;
	int _startLightAlphaval;
	int _gameStartBlackAlpha;

	image* _selectBat;
	int _currentX, _currentY;
	int _frameCount;

	GameModeSelect _select;

public:
	virtual HRESULT init();
	virtual void update();
	virtual void render();
	virtual void release();

	void SelectBatFrameCounter();
};

