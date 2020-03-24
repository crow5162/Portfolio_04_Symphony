#pragma once
#include "gameNode.h"
#include "MapMaster.h"

#define GROUNDHEIGHT 50
#define GROUNDNUMBER 6

class Map_10 : public MapMaster
{
private:

	int _currentFrameX, _currentFrameY;
	int _frameCount;
	image* _candle[3];

	GROUND _ground[GROUNDNUMBER];
	GROUND _wall[4];

public:
	Map_10() {};
	~Map_10() {};

	HRESULT init();
	virtual void update();
	virtual void release();
	virtual void render();

	void ObjectFrameCount();
	void CollisionTest();
};

