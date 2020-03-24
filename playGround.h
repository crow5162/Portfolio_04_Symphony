#pragma once
#include "gameNode.h"
#include "MapManager.h"


class playGround : public gameNode
{
private:

	MapManager* _mapManager;
	int _sceneChange;
	
public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();


	playGround();
	~playGround();
};

