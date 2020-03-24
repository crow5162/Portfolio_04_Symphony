#pragma once
#include "gameNode.h"
#include "MapMaster.h"

class Map_09 : public MapMaster
{
private:

public:
	Map_09() {};
	~Map_09() {};

	HRESULT init();
	virtual void update();
	virtual void release();
	virtual void render();
};

