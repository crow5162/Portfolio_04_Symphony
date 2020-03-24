#pragma once
#include "gameNode.h"
#include "MapMaster.h"

#define GROUNDWIDTH 5700
#define GROUNDHEIGHT 30

class Map_04 : public MapMaster
{
private:

	image* _candle[8];
	int _currentFrameX, _currentFrameY;
	int _frameCount;

	GROUND _ground;

public:
	Map_04() {};
	~Map_04() {};

	HRESULT init();
	virtual void update();
	virtual void release();
	virtual void render();

	virtual void ObjectFrameCount();
	virtual void Collision();
};

