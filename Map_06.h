#pragma once
#include "gameNode.h"
#include "MapMaster.h"

#define GROUNDWIDTH 190
#define GROUNDHEIGHT 65
#define GROUNDNUMBER 7

class Map_06 : public MapMaster
{
private:

	GROUND _ground[GROUNDNUMBER];
	GROUND _wall;
	GROUND _scaffold;

	int _spawnCount;
	bool _characterInScaffold;

public:
	Map_06() {};
	~Map_06() {};

	HRESULT init();
	virtual void update();
	virtual void release();
	virtual void render();

	void MedusaSpawn();
	void Collision();
};

