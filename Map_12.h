#pragma once
#include "gameNode.h"
#include "MapMaster.h"

#define GROUNDNUMBER 10

class Map_12 : public MapMaster
{
private:
	int _currentFrameX, _currentFrameY;
	int _frameCount;
	image* _torchLight[4];

	GROUND _ground[GROUNDNUMBER];

	int _spawnCount = 0;

public:
	Map_12() {};
	~Map_12() {};

	HRESULT init(); 
	virtual void update();
	virtual void release();
	virtual void render();

	void MedusaSpawn();
	virtual void ObjectFrameCount();
};

