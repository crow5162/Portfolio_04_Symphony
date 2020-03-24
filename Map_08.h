#pragma once
#include "gameNode.h"
#include "MapMaster.h"

#define GROUNDWIDTH 430
#define GROUNDHEIGHT 45
#define GROUNDNUMBER 3

class Map_08 : public MapMaster
{
private:

	image* _candle[5];
	int _currentFrameX, _currentFrameY;
	int _frameCount;

	GROUND _ground[GROUNDNUMBER];
	GROUND _wall[4];

public:
	Map_08() {};
	~Map_08() {};

	HRESULT init();
	virtual void update();
	virtual void release();
	virtual void render();

	virtual void ObjectFrameCount();
	void Collision();
};

