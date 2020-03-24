#pragma once
#include "gameNode.h"
#include "MapMaster.h"

class UiManager : public gameNode
{
private:

public:
	UiManager();
	~UiManager();

	virtual HRESULT init();
	virtual void update();
	virtual void release();
	virtual void render();
};

