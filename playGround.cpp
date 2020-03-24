#include "stdafx.h"
#include "playGround.h"

playGround::playGround()
{
}


playGround::~playGround()
{
}


HRESULT playGround::init()
{
	gameNode::init(true);
	
	_mapManager = new MapManager;
	_mapManager->init();


	return S_OK;
}


void playGround::release()
{
	gameNode::release();

	_mapManager->release();
	SAFE_DELETE(_mapManager);

}


void playGround::update()
{
	gameNode::update();

	_mapManager->update();

}



void playGround::render()
{
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, BLACKNESS);
	//PatBlt(CAMERAMANAGER->getWorldDC(), CAMERAMANAGER->get_CameraX(), CAMERAMANAGER->get_CameraY(), WINSIZEX, WINSIZEY, BLACKNESS);

	_mapManager->render();

	//TIMEMANAGER->render(getMemDC());
	//===========================================================
	_backBuffer->render(getHDC(), 0, 0);
}
