#pragma once
#include "gameNode.h"
#include "MapMaster.h"


class Map_05 : public MapMaster
{
private:

	int _loopX, _loopY;

public:
	Map_05() {};
	~Map_05() {};

	HRESULT init();
	virtual void update();
	virtual void release();
	virtual void render();
};

