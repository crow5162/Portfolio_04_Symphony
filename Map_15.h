#pragma once
#include "gameNode.h"
#include "MapMaster.h"

class Map_15 : public MapMaster
{
private:

public:
	Map_15() {};
	~Map_15() {};

	HRESULT init();
	virtual void update();
	virtual void release();
	virtual void render();
};

