#pragma once
#include "gameNode.h"
#include "MapMaster.h"

class Map_08_1 : public MapMaster
{
private:
	RECT _testRc;
	float _x, _y;
	GROUND _ground[2];

public:
	Map_08_1() {};
	~Map_08_1() {};

	HRESULT init();
	virtual void update();
	virtual void releasse();
	virtual void render();
};

