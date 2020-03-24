#pragma once
#include "gameNode.h"
#include "MainMenu.h"
#include "MapMaster.h"
#include "Map_01.h"
#include "Map_02.h"
#include "Map_03.h"
#include "Map_04.h"
#include "Map_05.h"
#include "Map_06.h"
#include "Map_07.h"
#include "Map_08.h"
#include "Map_08_1.h"
#include "Map_09.h"
#include "Map_10.h"
#include "Map_11.h"
#include "Map_12.h"
#include "Map_13.h"
#include "Map_13_1.h"
#include "Map_14.h"
#include "Map_15.h"
#include "Map_16.h"

class MapManager : public gameNode
{
private:
	int _sceneChange;

public:
	MapManager();
	~MapManager();

	HRESULT init();
	virtual void update();
	virtual void release();
	virtual void render();
};

