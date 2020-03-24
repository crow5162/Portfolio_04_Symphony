#include "stdafx.h"
#include "MapMaster.h"
#include "GameData.h"


GameData* MapMaster::gameData = nullptr;

GameData * MapMaster::GetData()
{
	return gameData;
}

MapMaster::MapMaster()
{
	gameData = new GameData;
}

MapMaster::~MapMaster()
{
}

HRESULT MapMaster::init()
{
	_alucard = new Alucard;
	_alucard->init();

	_monsterManager = new MonsterManager;
	_monsterManager->init();

	_alucard->SetLink_MonsterManager(_monsterManager);
	_monsterManager->SetLink_Alucard(_alucard);

	_item = new ItemManager;
	_item->init();

	_ui.alphaValue = 0;
	_ui.select = SelectEquip;
	_ui.equipInformation = Weapon;
	_ui._selectEquip = index;

	_ui.blackScreen = IMAGEMANAGER->findImage("UIStart");

	_hud.x = 15;
	_hud.y = 20;

	_hud.x2 = 342;
	_hud.y2 = 20;

	_hud.img = IMAGEMANAGER->findImage("Character_Hud");
	_hud.img2 = IMAGEMANAGER->findImage("Character_Hud_02");

	_hud.ani = new animation;
	_hud.ani->init(_hud.img2->getWidth(), _hud.img2->getHeight(), _hud.img2->getFrameWidth(), _hud.img2->getFrameHeight());
	_hud.ani->setPlayFrame(0, 6, false, true);
	_hud.ani->setFPS(6);
	_hud.ani->start();

	_testCount = 0;

	_miniPlayer = RectMakeCenter(100, 100, 10, 10);
	_openMiniMap = false;

	for (int i = 0; i < 10; i++)
	{
		string num = to_string(i);

		NumImg[i] = IMAGEMANAGER->findImage("Number_0" + num);
	}

	for (int i = 0; i < 10; i++)
	{
		string dNum = to_string(i);

		DamageNum[i] = IMAGEMANAGER->findImage("DamageNum_0" + dNum);
	}

	for (int i = 0; i < 10; i++)
	{
		string deNum = to_string(i);

		EDamageNum[i] = IMAGEMANAGER->findImage("EDamageNum_0" + deNum);
	}



	return S_OK;
}

void MapMaster::update()
{

	if(!_ui.uiStart)
	{
		_alucard->update();
		_monsterManager->update();

		_ui.alphaValue--;

		if (_ui.alphaValue <= 0) _ui.alphaValue = 0;
	}

	DATA->playerInfo.characterLocation = SCENEMANAGER->getSceneNumber();

	_item->update();

	UiInterface();

	MonsterHit();
	CharacterHit();
	CharacterHit2();
	ItemCollision();

	EFFECTMANAGER->update();

	_hud.ani->frameUpdate(TIMEMANAGER->getElapsedTime() * 1.5f);

	if (KEYMANAGER->isOnceKeyDown('M'))
	{
		_openMiniMap = _openMiniMap ? false : true;
	}
}

void MapMaster::release()
{

}

void MapMaster::render()
{
	//��ī��� ���� ����.
	_monsterManager->render();
	_item->render();
	_alucard->render();

	//����, �ǰݽ� ������ �̹��� ���� �κ� �Դϴ�.
	for (int i = 0; i < _vDamage.size(); i++)
	{
		if (_vDamage[i]->color == 0)
		{
			//�÷��̾ ���������� ��Ÿ���� ��� �۾�.
			DrawDamageNum(_vDamage[i]->damageCount, _vDamage[i]->x + 60, _vDamage[i]->y);
		}

		else if (_vDamage[i]->color == 1)
		{
			//������ �޾����� ��Ÿ���� ������ �۾�.
			DrawEDamageNum(_vDamage[i]->damageCount, _vDamage[i]->x + 60, _vDamage[i]->y);
		}

		_vDamage[i]->timeCount++;

		if (_vDamage[i]->timeCount < 30)
		{
			_vDamage[i]->y--;
		}

		if (_vDamage[i]->timeCount > 45)
		{
			_vDamage.erase(_vDamage.begin() + i);
		}
	}

	EFFECTMANAGER->render();

	CAMERAMANAGER->getWorldImage()->render(getMemDC(), 0, 0, CAMERAMANAGER->get_CameraX(), CAMERAMANAGER->get_CameraY(), WINSIZEX, WINSIZEY);

	//UI Render �� World ��ǥ �߶���� �� �Ʒ��� ���־�� ��µȴ�.
	_hud.img->render(getMemDC(), _hud.x, _hud.y);
	_hud.img2->aniRender(getMemDC(), _hud.x2, _hud.y2, _hud.ani);

	DrawNumber(DATA->playerInfo.currentHp, 128, 80);
	DrawNumber(DATA->playerInfo.currentMana, 310, 60);

	//����.
	_ui.blackScreen->alphaRender(getMemDC(), 0, 0, _ui.alphaValue);

	if (_openMiniMap)
	{
		IMAGEMANAGER->findImage("UIStart")->alphaRender(getMemDC(), 0, 0, 180);
		IMAGEMANAGER->findImage("MiniMap")->render(getMemDC(), 0, 0);
		HBRUSH brush = CreateSolidBrush(RGB(255, 0, 0));
		HBRUSH oldBrush = (HBRUSH)SelectObject(getMemDC(), brush);
		Rectangle(getMemDC(), _miniPlayer);
		SelectObject(getMemDC(), oldBrush);
		DeleteObject(brush);
	}

	//�������̽��� ���������� ���.
	if (_ui.interfaceStart)
	{
		_ui.StatusInfo->render(getMemDC(), 0, 0);

		//UIâ���� �÷��̾��� ���� ������ġ ǥ��.
		DrawNumber(DATA->playerInfo.currentHp, 520, 200);
		DrawNumber(DATA->playerInfo.maxHp, 650 , 200);

		DrawNumber(DATA->playerInfo.currentMana, 520, 230);
		DrawNumber(DATA->playerInfo.maxMana, 650, 230);

		DrawNumber(DATA->playerInfo.currentExp, 520, 270);
		DrawNumber(DATA->playerInfo.maxExp, 650, 270);
		
		DrawNumber(DATA->playerInfo.characterLevel, 920, 155);

		DrawNumber(DATA->playerInfo.STR, 230 ,380);
		DrawNumber(DATA->playerInfo.CON, 230, 415);
		DrawNumber(DATA->playerInfo.INT, 230, 450);
		DrawNumber(DATA->playerInfo.LCK, 230, 480);

		DrawNumber(DATA->playerInfo.playerAtk, 980, 285);
		DrawNumber(DATA->playerInfo.playerDef, 980, 365);

		DrawNumber(DATA->playerInfo.Kills, 930, 505);
		DrawNumber(DATA->playerInfo.Gold, 270, 630);

		if (_ui.informationStart)
		{
			_ui.Infoimg->render(getMemDC(), 0, 0);

			//�����â�϶�.
			if (_ui.info == EquipInfo)
			{
				//���� ��ġ�� ����ġ
				DrawNumber(DATA->playerInfo.playerAtk, 975, 125);
				DrawNumber(DATA->playerInfo.playerDef, 975, 200);

				//����� �������� �����ϴ� â.

				if (_ui.equipInformation == Weapon)
				{
					IMAGEMANAGER->render("Select_Bar_01", getMemDC(), 365, 140);

					for (int i = 0; i < DATA->playerInfo._vInven.size(); i++)
					{
						if (DATA->playerInfo._vInven.size() == 0) return;

						if (DATA->playerInfo._vInven[i]->getItemInfo().type == Weapon_01 || Weapon_02)
						{
							DATA->playerInfo._vInven[i]->getItemInfo().img->render(getMemDC(),
								65, 410 + i * 60);

							if (DATA->playerInfo._vInven[i]->getItemInfo().type == Weapon_01)
								IMAGEMANAGER->findImage("Item_Name_01")->render(getMemDC(), 285, 420);

							if (DATA->playerInfo._vInven[i]->getItemInfo().type == Weapon_02)
								IMAGEMANAGER->findImage("Item_Name_02")->render(getMemDC(), 270, 480);
						}
					}
				}
				else if (_ui.equipInformation == Armor)
				{
					IMAGEMANAGER->render("Select_Bar_01", getMemDC(), 365, 210);
				}
				else if (_ui.equipInformation == Armor2)
				{
					IMAGEMANAGER->render("Select_Bar_01", getMemDC(), 365, 280);
				}

				//����� ������ �����ϰ� ���������� �������� ������ â.
				if (_ui.selectEquip)
				{
					if (_ui._selectEquip == index)
					{
						IMAGEMANAGER->render("Select_Bar_02", getMemDC(), 120, 410);
					}
					else if (_ui._selectEquip == index2)
					{
						IMAGEMANAGER->render("Select_Bar_02", getMemDC(), 120, 470);
					}
					else if (_ui._selectEquip == index3)
					{
						IMAGEMANAGER->render("Select_Bar_02", getMemDC(), 120, 530);
					}
					else if (_ui._selectEquip == index4)
					{
						IMAGEMANAGER->render("Select_Bar_02", getMemDC(), 530, 410);
					}
					else if (_ui._selectEquip == index5)
					{
						IMAGEMANAGER->render("Select_Bar_02", getMemDC(), 530, 470);
					}
					else if (_ui._selectEquip == index6)
					{
						IMAGEMANAGER->render("Select_Bar_02", getMemDC(), 530, 530);
					}
				}
			}

		}
	}



}

void MapMaster::MonsterHit()
{
	//��ī���� �������� ���Ϳ��� ���ظ� �־�����
	for (int i = 0; i < _alucard->GetCAttack()->getAttackVector().size(); i++)
	{
		for (int j = 0; j < _monsterManager->getMonsterVector().size(); j++)
		{
			RECT temp;
			
			if (IntersectRect(&temp, &_alucard->GetCAttack()->getAttackVector()[i].rc,
				&_monsterManager->getMonsterVector()[j]->getMonsterRect()))
			{
				//������ ��¿� ���Ϳ� push back
				Damage *monsterHitDamage = new Damage;

				monsterHitDamage->damageCount = (DATA->playerInfo.playerAtk) - _monsterManager->getMonsterVector()[i]->
					getMonsterInfo().def;
				monsterHitDamage->timeCount = 0;
				monsterHitDamage->x = temp.left;
				monsterHitDamage->y = temp.top;
				monsterHitDamage->color = 0;

				_vDamage.push_back(monsterHitDamage);

				//���� ���Ϳ� HP���� �Լ� �ҷ��ͼ� ������ ������ �� ĳ������ ��������ŭ ���� �����ݴϴ�.
				_monsterManager->getMonsterVector()[j]->decreaseHP((DATA->playerInfo.playerAtk) - _monsterManager->getMonsterVector()[i]->
					getMonsterInfo().def);

				//������ ü���� ������
				if (_monsterManager->getMonsterVector()[i]->getMonsterInfo().hp <= 0)
				{
					//temp�� ��ġ�� ������ �������� ����߸��ϴ�.
					RandomSpawnItem(temp.left, temp.top);
					//���ӵ����Ϳ� �ִ� ĳ���� ����ġ�� �÷��ְ�
					DATA->playerInfo.currentExp += 35;
				}

				//����Ʈ ȿ�� ó�� (���⿡ ���� �޶���.)
				if (DATA->playerInfo.swordType == 0)
				{
					EFFECTMANAGER->play("Attack_Effect_01", temp.left, temp.top);
				}
				else if (DATA->playerInfo.swordType == 1)
				{
					EFFECTMANAGER->play("Attack_Effect_02", temp.left, temp.top);
				}
				
				if (_alucard->GetCAttack()->getAttackVector()[i].type == MagicAttack)
				{
					EFFECTMANAGER->play("Dead_03", temp.left, temp.top);
				}

				//�ǰݵǴ� ����� ������ �߰��������� ��� �ǰݽø��� ���� �������� �������ݴϴ�.
				if (_monsterManager->getMonsterVector()[i]->getMonsterInfo().monsterType == BOSS_GARGOYLE ||
					_monsterManager->getMonsterVector()[i]->getMonsterInfo().monsterType == BOSS_SLOGRA)
				{
					RandomSpawnItem(temp.left, temp.top);
				}

				//ĳ������ ���� Ŭ�������ִ� ���� ����� �Լ� �������־ i��° ���� ���� ���ݴϴ�.
				_alucard->GetCAttack()->AttackDelete(i);

				//break�� ���ǹ� Ż���մϴ�.
				break;
			}
		}
	}
}

void MapMaster::CharacterHit()
{
	//���ͺ��� i ��° ���� �ҷ�����.
	for (int i = 0; i < _monsterManager->getMonsterVector().size(); i++)
	{
		//���ͺ��� i��° ������ AttackVector�� j��° ���Ҹ� �ҷ��´�.
		for (int j = 0; j < _monsterManager->getMonsterVector()[i]->GetMAttack()->getMonsterAttackV().size(); j++)
		{
			RECT temp;

			if (IntersectRect(&temp, &_monsterManager->getMonsterVector()[i]->GetMAttack()->getMonsterAttackV()[j].rc,
				&_alucard->GetAlucardRect()))
			{
				//���ӵ����Ϳ� ����� �÷��̾� ü���� ���� ������ ������ ��ŭ ��´�.
				// i��° ������ j��° ���ú��Ϳ� ��� ���ݷ�Ʈ ����.
				//��ī�尡 �ǰ� ���°� �ƴҶ��� �ǰ� ������ ���� �մϴ�.
				if (!_alucard->GetAlucard().boolset.getDamage)
				{
					Damage *charHitDamage = new Damage;

					charHitDamage->damageCount = _monsterManager->getMonsterVector()[i]->getMonsterInfo().damage - 
						DATA->playerInfo.playerDef;

					charHitDamage->timeCount = 0;
					charHitDamage->x = temp.left;
					charHitDamage->y = temp.top;
					charHitDamage->color = 1;

					_vDamage.push_back(charHitDamage);

					_alucard->Hit();
					DATA->playerInfo.currentHp -= (_monsterManager->getMonsterVector()[i]->getMonsterInfo().damage -
						DATA->playerInfo.playerDef);
				}

				_monsterManager->getMonsterVector()[i]->GetMAttack()->AttackDelete(j);
				break;
			}
		}
	}
}

void MapMaster::CharacterHit2()
{
	//������ Body�� ĳ���Ͱ� �浹������ ĳ���� ü�°���.

	for (int i = 0; i < _monsterManager->getMonsterVector().size(); i++)
	{
		//�޵λ����� ���� ���̷��游 �ش��մϴ�.
		if (_monsterManager->getMonsterVector()[i]->getMonsterInfo().monsterType == MONSTER_MEDUSAHEAD ||
			_monsterManager->getMonsterVector()[i]->getMonsterInfo().monsterType == MONSTER_SKELETON)
		{
			RECT temp;

			if (IntersectRect(&temp, &_monsterManager->getMonsterVector()[i]->getMonsterRect(), &_alucard->GetAlucardRect()))
			{
				if (!_alucard->GetAlucard().boolset.getDamage)
				{
					Damage *charHitBodyDamage = new Damage;

					charHitBodyDamage->damageCount = _monsterManager->getMonsterVector()[i]->getMonsterInfo().damage -
						DATA->playerInfo.playerDef;

					charHitBodyDamage->timeCount = 0;
					charHitBodyDamage->x = temp.left;
					charHitBodyDamage->y = temp.top;
					charHitBodyDamage->color = 1;

					_vDamage.push_back(charHitBodyDamage);

					_alucard->Hit();
					DATA->playerInfo.currentHp -= (_monsterManager->getMonsterVector()[i]->getMonsterInfo().damage -
						DATA->playerInfo.playerDef);
				}
				
				//�浹�� ���ʹ� ������ϴ�.
				_monsterManager->DeleteMonster(i);

				break;
			}
		}
	}


}

void MapMaster::ItemCollision()
{
	for (int i = 0; i < _item->getvItem().size(); i++)
	{
		if (_item->getvItem().size() == 0) return;

		//��� ���������� �κ��丮 ���Ϳ����� �ҷ��ü��ֽ��ϴ�.
		if (_item->getvItem()[i]->getItemInfo().type == Weapon_01 ||
			_item->getvItem()[i]->getItemInfo().type == Weapon_02)
		{
			RECT temp;

			if (IntersectRect(&temp, &_alucard->GetAlucardRect(), &_item->getvItem()[i]->getItemRect()))
			{
				EFFECTMANAGER->play("getItem", temp.left , temp.top);
				DATA->playerInfo._vInven.push_back(_item->getvItem()[i]);
				_item->EraseItem(i);

				break;
			}
		}

		//�Ҹ� ���������� �κ��丮 ���Ϳ� push_back �����ʽ��ϴ�.
		else if (_item->getvItem()[i]->getItemInfo().type == Immediate_01)
		{
			RECT temp;

			if (IntersectRect(&temp, &_alucard->GetAlucardRect(), &_item->getvItem()[i]->getItemRect()))
			{
				EFFECTMANAGER->play("getItem", temp.left, temp.top);
				DATA->playerInfo.currentHp += _item->getvItem()[i]->getItemInfo().Heal;
				_item->EraseItem(i);

				break;
			}
		}

		else if (_item->getvItem()[i]->getItemInfo().type == Immediate_02)
		{
			RECT temp;

			if (IntersectRect(&temp, &_alucard->GetAlucardRect(), &_item->getvItem()[i]->getItemRect()))
			{
				EFFECTMANAGER->play("getItem", temp.left, temp.top);
				DATA->playerInfo.currentMana += _item->getvItem()[i]->getItemInfo().Mana;
				_item->EraseItem(i);

				break;
			}
		}

		else if (_item->getvItem()[i]->getItemInfo().type == Gold)
		{
			RECT temp;

			if (IntersectRect(&temp, &_alucard->GetAlucardRect(), &_item->getvItem()[i]->getItemRect()))
			{
				EFFECTMANAGER->play("getItem", temp.left, temp.top);
				DATA->playerInfo.Gold += _item->getvItem()[i]->getItemInfo().gold;
				_item->EraseItem(i);

				break;
			}
		}
	}
}

void MapMaster::UiInterface()
{
	if (KEYMANAGER->isOnceKeyDown('I'))
	{
		_ui.uiStart = _ui.uiStart ? false : true;
	}

	if (_ui.uiStart)
	{
		_ui.alphaValue += 2;

		if (_ui.alphaValue >= 255) _ui.alphaValue = 255;

		//ȭ���� ������ ������ ���¿��� �������ͽ� â�� ������.
		if (_ui.alphaValue > 253)
			_ui.interfaceStart = true;
	}
	//ui Startr�� false�� �Ǹ� Interface Start�� false �� �˴ϴ�.
	else if (!_ui.uiStart)
	{
		_ui.interfaceStart = false;
	}

	if (_ui.interfaceStart)
	{
		if (!_ui.informationStart)
		{
			//�������̽��� ���� ���¿����� �۵��մϴ�.
			if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
			{
				//�� UI�� �������� �۵����� �ʾƾ� �մϴ�.

				_ui.select = (Select)((int)_ui.select + 1);

				if (_ui.select >= 4)
				{
					_ui.select = SelectEquip;
				}
			}

			else if (KEYMANAGER->isOnceKeyDown(VK_UP))
			{
				_ui.select = (Select)((int)_ui.select - 1);

				if (_ui.select < 0)
				{
					_ui.select = SelectFamiliars;
				}
			}

			if (KEYMANAGER->isOnceKeyDown('A'))
			{
				if (_ui.select == SelectEquip)
				{
					_ui.info = EquipInfo;
					_ui.informationStart = true;
					_ui.Infoimg = IMAGEMANAGER->findImage("Equip_info");
				}
				else if (_ui.select == SelectSpells)
				{
					_ui.info = SpellsInfo;
					_ui.informationStart = true;
					_ui.Infoimg = IMAGEMANAGER->findImage("Spells_info");
				}
				else if (_ui.select == SelectRelics)
				{
					_ui.info = RelicsInfo;
					_ui.informationStart = true;
					_ui.Infoimg = IMAGEMANAGER->findImage("Relics_info");
				}
				else if (_ui.select == SelectFamiliars)
				{
					_ui.info = FamiliarsInfo;
					_ui.informationStart = true;
					_ui.Infoimg = IMAGEMANAGER->findImage("Familiars_info");
				}
			}

			if (_ui.select == SelectEquip)				 _ui.StatusInfo = IMAGEMANAGER->findImage("Interface_Equip");
			else if (_ui.select == SelectSpells)		 _ui.StatusInfo = IMAGEMANAGER->findImage("Interface_Spells");
			else if (_ui.select == SelectRelics)		 _ui.StatusInfo = IMAGEMANAGER->findImage("Interface_Relics");
			else if (_ui.select == SelectFamiliars)	     _ui.StatusInfo = IMAGEMANAGER->findImage("Interface_Familiars");

		}

		//AŰ�� ������ �� ����ȭ�� ���� ��������.
		if (_ui.informationStart)
		{
			//��� ����â���� ��������.
			if (_ui.info == EquipInfo)
			{
				if (!_ui.selectEquip)
				{
					//��, �Ʒ� ����Ű�� �Է��ؼ� ������ �����մϴ�.
					if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
					{
						_ui.equipInformation = (EquipInformation)((int)_ui.equipInformation + 1);

						if (_ui.equipInformation >= 3)
						{
							_ui.equipInformation = Weapon;
						}
					}

					else if (KEYMANAGER->isOnceKeyDown(VK_UP))
					{
						_ui.equipInformation = (EquipInformation)((int)_ui.equipInformation - 1);

						if (_ui.equipInformation < 0)
						{
							_ui.equipInformation = Armor2;
						}
					}

					//�� ��� ������ A�� �����ϸ� �κ��丮�ȿ� ��� ����� �������� �̹����� ��µǰ�,
					//������ ������ �� �ֽ��ϴ�.
					if (_ui.equipInformation == Weapon || _ui.equipInformation == Armor || _ui.equipInformation == Armor2)
					{
						if (KEYMANAGER->isOnceKeyDown('A'))
						{
							_ui.selectEquip = true;
						}
					}
				}

				//��� ������ �����ؼ�  ���������� �����Ҽ��ִ� â.
				if (_ui.selectEquip)
				{
					if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
					{
						_ui._selectEquip = (EquipSelect)((int)_ui._selectEquip + 1);

						if (_ui._selectEquip >= 6)
						{
							_ui._selectEquip = index;
						}
					}
					else if (KEYMANAGER->isOnceKeyDown(VK_UP))
					{
						_ui._selectEquip = (EquipSelect)((int)_ui._selectEquip - 1);

						if (_ui._selectEquip < 0)
						{
							_ui._selectEquip = index6;
						}
					}

					//���� ����ϰ� �ٽ� ������ �����ϴ� â���� ���ư�.
					else if (KEYMANAGER->isOnceKeyDown('S'))
					{
						_ui.selectEquip = false;
					}

					if (_ui.equipInformation == Weapon)
					{
						for (int i = 0; i < DATA->playerInfo._vInven.size(); i++)
						{
							if (DATA->playerInfo._vInven.size() == 0) return;

							if (_ui._selectEquip == index)
							{
								if (KEYMANAGER->isOnceKeyDown('A'))
								{
									if (DATA->playerInfo._vInven[0] == nullptr) return;

									DATA->playerInfo.playerAtk = DATA->playerInfo._vInven[0]->getItemInfo().atk;
									if (DATA->playerInfo._vInven[0]->getItemInfo().type == Weapon_02)
										DATA->playerInfo.swordType = 1;
									if (DATA->playerInfo._vInven[0]->getItemInfo().type == Weapon_01)
										DATA->playerInfo.swordType = 0;
								}
							}

							else if (_ui._selectEquip == index2)
							{
								if (KEYMANAGER->isOnceKeyDown('A'))
								{
									if (DATA->playerInfo._vInven[1] == nullptr) return;

									DATA->playerInfo.playerAtk = DATA->playerInfo._vInven[1]->getItemInfo().atk;

									if (DATA->playerInfo._vInven[1]->getItemInfo().type == Weapon_02)
										DATA->playerInfo.swordType = 1;
									if (DATA->playerInfo._vInven[1]->getItemInfo().type == Weapon_01)
										DATA->playerInfo.swordType = 0;
								}
							}
						}
					}
				}
			}

			else if (_ui.info == SpellsInfo)
			{

			}

			else if (_ui.info == RelicsInfo)
			{

			}

			else if (_ui.info == FamiliarsInfo)
			{

			}

			//S�� ������ �������� �������´�.
			if (KEYMANAGER->isOnceKeyDown('S'))
			{
				_ui.info = NoneInfo;
				_ui.informationStart = false;
			}
		}
	}
}

void MapMaster::DrawNumber(int Num, int destX, int destY)
{
	int heightrange = 30; //���������� ���α���;

	if (Num >= 1000)
	{
		int a;
		int b;
		int c;
		int d;
		a = Num / 1000;
		b = (Num % 1000) / 100;
		c = (Num % 1000) % 100 / 10;
		d = (Num % 1000) % 100 % 10;
		NumImg[a]->render(getMemDC(), destX - 120, destY);
		NumImg[b]->render(getMemDC(), destX - 100, destY);
		NumImg[c]->render(getMemDC(), destX - 80, destY);
		NumImg[d]->render(getMemDC(), destX - 60, destY);

	}
	else if (Num >= 100) {
		int a;
		int b;
		int c;
		a = Num / 100;
		b = (Num % 100) / 10;
		c = (Num % 100) % 10;
		NumImg[a]->render(getMemDC(), destX - 100, destY);
		NumImg[b]->render(getMemDC(), destX - 80, destY);
		NumImg[c]->render(getMemDC(), destX - 60, destY);
	}
	else if (Num >= 10) {
		int a;
		int b;
		a = Num / 10;
		b = Num % 10;
		NumImg[a]->render(getMemDC(), destX - 80, destY);
		NumImg[b]->render(getMemDC(), destX - 60, destY);
	}
	else if (Num < 10 && Num > 0) {

		NumImg[Num]->render(getMemDC(), destX - 60, destY);
	}
	else if (Num <= 0)
	{
		NumImg[0]->render(getMemDC(), destX - 60, destY);
	}
}

void MapMaster::DrawDamageNum(int Num, int destX, int destY)
{
	if (Num >= 1000)
	{
		int a;
		int b;
		int c;
		int d;
		a = Num / 1000;
		b = (Num % 1000) / 100;
		c = (Num % 1000) % 100 / 10;
		d = (Num % 1000) % 100 % 10;
		DamageNum[a]->render(CAMERAMANAGER->getWorldDC(), destX - 120, destY);
		DamageNum[b]->render(CAMERAMANAGER->getWorldDC(), destX - 100, destY);
		DamageNum[c]->render(CAMERAMANAGER->getWorldDC(), destX - 80, destY);
		DamageNum[d]->render(CAMERAMANAGER->getWorldDC(), destX - 60, destY);

	}
	else if (Num >= 100) {
		int a;
		int b;
		int c;
		a = Num / 100;
		b = (Num % 100) / 10;
		c = (Num % 100) % 10;
		DamageNum[a]->render(CAMERAMANAGER->getWorldDC(), destX - 100, destY);
		DamageNum[b]->render(CAMERAMANAGER->getWorldDC(), destX - 80, destY);
		DamageNum[c]->render(CAMERAMANAGER->getWorldDC(), destX - 60, destY);
	}
	else if (Num >= 10) {
		int a;
		int b;
		a = Num / 10;
		b = Num % 10;
		DamageNum[a]->render(CAMERAMANAGER->getWorldDC(), destX - 80, destY);
		DamageNum[b]->render(CAMERAMANAGER->getWorldDC(), destX - 60, destY);
	}
	else if (Num < 10) {

		DamageNum[Num]->render(CAMERAMANAGER->getWorldDC(), destX - 60, destY);
	}


}

void MapMaster::DrawEDamageNum(int Num, int destX, int destY)
{
	if (Num >= 1000)
	{
		int a;
		int b;
		int c;
		int d;
		a = Num / 1000;
		b = (Num % 1000) / 100;
		c = (Num % 1000) % 100 / 10;
		d = (Num % 1000) % 100 % 10;
		EDamageNum[a]->render(CAMERAMANAGER->getWorldDC(), destX - 120, destY);
		EDamageNum[b]->render(CAMERAMANAGER->getWorldDC(), destX - 100, destY);
		EDamageNum[c]->render(CAMERAMANAGER->getWorldDC(), destX - 80, destY);
		EDamageNum[d]->render(CAMERAMANAGER->getWorldDC(), destX - 60, destY);

	}
	else if (Num >= 100) {
		int a;
		int b;
		int c;
		a = Num / 100;
		b = (Num % 100) / 10;
		c = (Num % 100) % 10;
		EDamageNum[a]->render(CAMERAMANAGER->getWorldDC(), destX - 100, destY);
		EDamageNum[b]->render(CAMERAMANAGER->getWorldDC(), destX - 80, destY);
		EDamageNum[c]->render(CAMERAMANAGER->getWorldDC(), destX - 60, destY);
	}
	else if (Num >= 10) {
		int a;
		int b;
		a = Num / 10;
		b = Num % 10;
		EDamageNum[a]->render(CAMERAMANAGER->getWorldDC(), destX - 80, destY);
		EDamageNum[b]->render(CAMERAMANAGER->getWorldDC(), destX - 60, destY);
	}
	else if (Num < 10) {

		EDamageNum[Num]->render(CAMERAMANAGER->getWorldDC(), destX - 60, destY);
	}
}

void MapMaster::RandomSpawnItem(int x, int y)
{
	int itemRandom = RND->getFromIntTo(0, 100);

	if (itemRandom <= 50) return;

	if (itemRandom > 50 && itemRandom <= 70)
	{
		_item->HealItemSet(x, y);
	}
	else if (itemRandom > 70 && itemRandom <= 90)
	{
		_item->ManaItemSet(x, y);
	}
	else if (itemRandom > 90 && itemRandom <= 100)
	{
		_item->MoneyItemSet(x, y);
	}

}


