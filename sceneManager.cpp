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
		//� ���� ������ ó���� ����ֱ� ������ ������ �������
		if (_currentScene) _currentScene->release();

		//���� ���� �ٲٷ��� ���� ��´�
		gameNode* oldScene = _currentScene;
		_currentScene = find->second;
		
		GameData* oldData = static_cast<MapMaster*>(oldScene)->GetData();
		
		MapMaster* newScene = static_cast<MapMaster*>(_currentScene);

		//Init���� �ʾƾ��� ������ �õ������ �����͸� �Űܿͼ� �������ش�.
		//���� ������ ����ġ
		newScene->GetData()->playerInfo.characterLevel =
			oldData->playerInfo.characterLevel;
		newScene->GetData()->playerInfo.currentExp =
			oldData->playerInfo.currentExp;
		newScene->GetData()->playerInfo.maxExp =
			oldData->playerInfo.maxExp;
		//�÷��̾��� ���� ü��
		newScene->GetData()->playerInfo.currentHp =
			oldData->playerInfo.currentHp;
		//�÷��̾��� �ִ� ü��
		newScene->GetData()->playerInfo.maxHp =
			oldData->playerInfo.maxHp;
		//�ִ� ����
		newScene->GetData()->playerInfo.maxMana =
			oldData->playerInfo.maxMana;
		//���� ����
		newScene->GetData()->playerInfo.currentMana =
			oldData->playerInfo.currentMana;
		//������
		newScene->GetData()->playerInfo.Gold =
			oldData->playerInfo.Gold;
		//ų ��
		newScene->GetData()->playerInfo.Kills =
			oldData->playerInfo.Kills;
		//�÷��̾��� ���ݷ�
		newScene->GetData()->playerInfo.playerAtk =
			oldData->playerInfo.playerAtk;
		//�÷��̾��� ����
		newScene->GetData()->playerInfo.playerDef =
			oldData->playerInfo.playerDef;
		//�÷��̾� �� (STR)
		newScene->GetData()->playerInfo.STR =
			oldData->playerInfo.STR;
		//�÷��̾� ü�� (CON)
		newScene->GetData()->playerInfo.CON =
			oldData->playerInfo.CON;
		//�÷��̾� ���� (INT)
		newScene->GetData()->playerInfo.INT =
			oldData->playerInfo.INT;
		//�÷��̾� ��� (LCK)
		newScene->GetData()->playerInfo.LCK =
			oldData->playerInfo.LCK;
		//�κ��丮 ����
		newScene->GetData()->playerInfo._vInven =
			oldData->playerInfo._vInven;
		//���� ���ͷ�����
		newScene->GetData()->playerInfo._viInven =
			oldData->playerInfo._viInven;
		//ĳ������ ���� �� �ѹ�
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
