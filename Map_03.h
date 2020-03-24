#pragma once
#include "gameNode.h"
#include "MapMaster.h"

#define GROUNDWIDTH 2350
#define GROUNDHEIGHT 30

class Map_03 :public MapMaster
{
private:
	RECT _testRc;
	float _x, _y;

	image* _candle[4];
	int _currentFrameX, _currentFrameY;
	int _frameCount;
	int _probeX, _probeY;

	GROUND _ground;

public:
	Map_03() {};
	~Map_03() {};

	HRESULT init();
	virtual void update();
	virtual void release();
	virtual void render();

	void ObjectFrameCount();
	void Collision();
};

