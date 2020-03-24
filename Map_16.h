#pragma once
#include "gameNode.h"
#include "MapMaster.h"

class Map_16 : public MapMaster
{
private:
	GROUND _ground;

public:
	Map_16() {};
	~Map_16() {};
	
	HRESULT init();
	virtual void update();
	virtual void release();
	virtual void render();
};

