#pragma once
#include "singletonBase.h"
#include <map>

class gameNode;

class sceneManager : public singletonBase<sceneManager>
{
public:
	typedef map<string, gameNode*>				mapSceneList;
	typedef map<string, gameNode*>::iterator	mapSceneIter;

private:
	static gameNode* _currentScene;
	mapSceneList _mSceneList;
	int _sceneNumber;

public:
	sceneManager();
	~sceneManager();

	HRESULT init();
	void release();
	void update();
	void render();

	//현재 씬 번호 불러옵니다
	int getSceneNumber() { return _sceneNumber; }
	//현재 씬 번호 정합니다.
	void setSceneNumber(int scenenumber) { _sceneNumber = scenenumber; }

	gameNode* addScene(string sceneName, gameNode* scene);

	HRESULT changeScene(string sceneName);
};

