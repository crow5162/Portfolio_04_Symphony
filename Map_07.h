#pragma once
#include "gameNode.h"
#include "MapMaster.h"

class Map_07 : public MapMaster
{
private:
	RECT _testRc;
	float _x, _y;

	int _loopX, _loopY;
public:
	Map_07() {};
	~Map_07() {};

	HRESULT init();
	virtual void update();
	virtual void release();
	virtual void render();
};

