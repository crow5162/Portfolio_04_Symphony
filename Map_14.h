#pragma once
#include "gameNode.h"
#include "MapMaster.h"

#define GROUNDNUMBER 4

class Map_14 : public MapMaster
{
private:
	GROUND _ground[GROUNDNUMBER];

public:
	Map_14() {};
	~Map_14() {};

	HRESULT init();
	virtual void update();
	virtual void release();
	virtual void render();

	void GroundCollision();
};

