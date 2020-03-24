#pragma once
#include "gameNode.h"
#include "MapMaster.h"

#define GROUNDNUMBER 4

class Map_13 : public MapMaster
{
private:
	int _currentFrameX, _currentFrameY;
	int _frameCount;
	image* _torchLight[4];

	GROUND _ground[GROUNDNUMBER];
	GROUND _wall[4];

public:
	Map_13() {};
	~Map_13() {};

	HRESULT init();
	virtual void update();
	virtual void release();
	virtual void render();

	virtual void ObjectFrameCount();
	void Collision();
	void NextStage();
};

