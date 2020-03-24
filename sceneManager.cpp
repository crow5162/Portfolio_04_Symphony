#include "stdafx.h"
#include "sceneManager.h"
#include "gameNode.h"

sceneManager::sceneManager()
{
}


sceneManager::~sceneManager()
{
}

gameNode* sceneManager::_currentScene = NULL;

HRESULT sceneManager::init()
{
	_currentScene = NULL;

	return S_OK;
}

void sceneManager::release()
{
	mapSceneIter miSceneList = _mSceneList.begin();

	for (; miSceneList != _mSceneList.end();)
	{
		if (miSceneList->second != NULL)
		{
			if (miSceneList->second == _currentScene) miSceneList->second->release();
			SAFE_DELETE(miSceneList->second);
			miSceneList = _mSceneList.erase(miSceneList);
		}
		else ++miSceneList;
	}

	_mSceneList.clear();
}

void sceneManager::update()
{
	if (_currentScene) _currentScene->update();
}

void sceneManager::render()
{
	if (_currentScene) _currentScene->render();
}

gameNode * sceneManager::addScene(string sceneName, gameNode * scene)
{
	if(!scene) return nullptr;

	_mSceneList.insert(make_pair(sceneName, scene));

	return scene;
}

HRESULT sceneManager::changeScene(string sceneName)
{
	mapSceneIter find = _mSceneList.find(sceneName);

	if (find == _mSceneList.end()) return E_FAIL;
	if (find->second == _currentScene) return S_OK;

	if (SUCCEEDED(find->second->init()))
	{
		//어떤 씬의 정보가 처음에 들어있기 때문에 릴리즈 시켜줘라
		if (_currentScene) _currentScene->release();

		//현재 씬에 바꾸려는 씬을 담는다
		gameNode* oldScene = _currentScene;
		_currentScene = find->second;
		
		GameData* oldData = static_cast<MapMaster*>(oldScene)->GetData();
		
		MapMaster* newScene = static_cast<MapMaster*>(_currentScene);

		//Init되지 않아야할 정보는 올드씬에서 데이터를 옮겨와서 유지해준다.
		//현재 레벨과 경험치
		newScene->GetData()->playerInfo.characterLevel =
			oldData->playerInfo.characterLevel;
		newScene->GetData()->playerInfo.currentExp =
			oldData->playerInfo.currentExp;
		newScene->GetData()->playerInfo.maxExp =
			oldData->playerInfo.maxExp;
		//플레이어의 현재 체력
		newScene->GetData()->playerInfo.currentHp =
			oldData->playerInfo.currentHp;
		//플레이어의 최대 체력
		newScene->GetData()->playerInfo.maxHp =
			oldData->playerInfo.maxHp;
		//최대 마나
		newScene->GetData()->playerInfo.maxMana =
			oldData->playerInfo.maxMana;
		//현재 마나
		newScene->GetData()->playerInfo.currentMana =
			oldData->playerInfo.currentMana;
		//소지금
		newScene->GetData()->playerInfo.Gold =
			oldData->playerInfo.Gold;
		//킬 수
		newScene->GetData()->playerInfo.Kills =
			oldData->playerInfo.Kills;
		//플레이어의 공격력
		newScene->GetData()->playerInfo.playerAtk =
			oldData->playerInfo.playerAtk;
		//플레이어의 방어력
		newScene->GetData()->playerInfo.playerDef =
			oldData->playerInfo.playerDef;
		//플레이어 힘 (STR)
		newScene->GetData()->playerInfo.STR =
			oldData->playerInfo.STR;
		//플레이어 체력 (CON)
		newScene->GetData()->playerInfo.CON =
			oldData->playerInfo.CON;
		//플레이어 지능 (INT)
		newScene->GetData()->playerInfo.INT =
			oldData->playerInfo.INT;
		//플레이어 행운 (LCK)
		newScene->GetData()->playerInfo.LCK =
			oldData->playerInfo.LCK;
		//인벤토리 벡터
		newScene->GetData()->playerInfo._vInven =
			oldData->playerInfo._vInven;
		//벡터 이터레이터
		newScene->GetData()->playerInfo._viInven =
			oldData->playerInfo._viInven;
		//캐릭터의 현재 맵 넘버
		newScene->GetData()->playerInfo.characterLocation =
			oldData->playerInfo.characterLocation;
		
		//SAFE_DELETE(oldScene);

		//MapMaster* tempDownCast = static_cast<MapMaster*>(oldScene);
		//gameNode* tempUpCast = static_cast<gameNode*>(tempDownCast);

		//dynamic_cast<MapMaster*>(oldScene)->GetData();

		return S_OK;
	}



	return E_FAIL;
}
