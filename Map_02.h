#pragma once
#include "gameNode.h"
#include "MapMaster.h"

#define GROUNDWIDTH 6650
#define GROUNDHEIGHT 50

class Map_02 : public MapMaster
{
private:
	int _loopX, _loopY;

	image* _candle[6];
	int _currentFrameX, _currentFrameY;
	int _frameCount;
	int _probeX, _probeY;

	GROUND _ground;

public:
	Map_02() {};
	~Map_02() {};

	HRESULT init();
	virtual void update();
	virtual void release();
	virtual void render();

	virtual void ObjectFrameCount();
	virtual void CollisionTest();
};

