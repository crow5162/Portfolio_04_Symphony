#pragma once
#include "gameNode.h"
#include "MapMaster.h"

#define GROUNDWIDTH 1300
#define GROUNDHEIGHT 50.f

class Map_01 : public MapMaster
{
private:

	int _gameStartAlpha;

	int _loopX, _loopY;

	image* _backGround;
	image* _testPlayer;
	GROUND _ground;

public:
	Map_01();
	~Map_01();

	virtual HRESULT init();
	virtual void update();
	virtual void release();
	virtual void render();

	//Ground, Monster 충돌 테스트 함수.
	void CollisionTest();	
};

