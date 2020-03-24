#pragma once
#include "gameNode.h"
#include "MapMaster.h"

#define GROUNDNUMBER 5

class Map_11 : public MapMaster
{
private:

	GROUND _ground[GROUNDNUMBER];
	GROUND _wall[6];

	//������Ʈ ������ ī��Ʈ. �̹���.
	int _currentFrameX, _currentFrameY;
	int _frameCount;
	int _fireFrameX, _fireFrameY;
	int _fireCount;
	image* _candle[6];
	image* _alchemiFire;

public:
	Map_11() {};
	~Map_11() {};

	HRESULT init();
	virtual void update();
	virtual void release();
	virtual void render();

	virtual void ObjectFrameCount();
	void Collision();
};

