#pragma once
#include "gameNode.h"
#include "MapMaster.h"

class Map_13_1 : public MapMaster
{
private:

	GROUND _ground;

public:
	Map_13_1() {};
	~Map_13_1() {};

	HRESULT init();
	virtual void update();
	virtual void release();
	virtual void render();
};

