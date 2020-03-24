#include "stdafx.h"
#include "MonsterManager.h"
#include "Monster.h"

HRESULT MonsterManager::init()
{
	_pattern.timer = 0;
	_pattern.random = 0;
	_pattern.check = false;

	return S_OK;
}

void MonsterManager::update()
{
	for (int i = 0; i < _vMonster.size(); i++)
	{
		if (_vMonster.size() == 0) return;

		_vMonster[i]->update();

	}


	EraseMonster();

	ArmoredKnightBehavior();
	SkeletonKnightBehavior();
	GargoyleAndSlogra();
	DeathBehavior();
}

void MonsterManager::release()
{

}

void MonsterManager::render()
{
	for (int i = 0; i < _vMonster.size(); i++)
	{
		if (_vMonster.size() == 0) return;

		_vMonster[i]->render();
	}
}

void MonsterManager::EraseMonster()
{
	//���� ����
	for (_viMonster = _vMonster.begin(); _viMonster != _vMonster.end();)
	{
		if (_vMonster.size() == 0) return;

		//������ ü���� 0 �� �Ǹ� �����˴ϴ�.
		if ((*_viMonster)->getMonsterInfo().hp <= 0)
		{
			DATA->playerInfo.Kills += 1;

			//������ Ÿ�Կ� ���� ����Ʈ
			if ((*_viMonster)->getMonsterInfo().monsterType == MONSTER_SKELETON)
			{
				EFFECTMANAGER->play("Dead_01", (*_viMonster)->getMonsterInfo().x, (*_viMonster)->getMonsterInfo().y);
			}

			else if ((*_viMonster)->getMonsterInfo().monsterType == MONSTER_KNIGHT || 
				(*_viMonster)->getMonsterInfo().monsterType == BOSS_GARGOYLE || 
				(*_viMonster)->getMonsterInfo().monsterType == BOSS_SLOGRA ||
				(*_viMonster)->getMonsterInfo().monsterType == BOSS_REAPER)
			{
				EFFECTMANAGER->play("Dead_04", (*_viMonster)->getMonsterInfo().x, (*_viMonster)->getMonsterInfo().y);
			}

			_viMonster = _vMonster.erase(_viMonster);
		}

		//ȭ����� ������ ���͸� ����
		else if ((*_viMonster)->getMonsterInfo().x < 0 || (*_viMonster)->getMonsterInfo().x > CAMERAMANAGER->getWorldCameraSize())
		{
			//ȭ����� ������ ���ʹ� �޵λ��� �Ӹ����Դϴ�.
			if ((*_viMonster)->getMonsterInfo().monsterType != MONSTER_MEDUSAHEAD) return;
		
				_viMonster = _vMonster.erase(_viMonster);
		}

		else
		{
			_viMonster++;
		}
		
	}
}

void MonsterManager::DeleteMonster(int arrNum)
{
	_vMonster.erase(_vMonster.begin() + arrNum);
}

void MonsterManager::ArmoredKnightBehavior()
{
	for (int i = 0; i < _vMonster.size(); i++)
	{
		if (_vMonster.size() == 0) return;

		//�������������������������������������������������������
		if (_vMonster[i]->getMonsterInfo().monsterType == MONSTER_KNIGHT)
			//���� ����� �ൿ����.
		{
			if (getDistance(_vMonster[i]->getMonsterInfo().x, _vMonster[i]->getMonsterInfo().y,
				_alucard->GetAlucard().x, _alucard->GetAlucard().y) < 500.f)
				//���ʱ��� �����Ÿ���ŭ ����� ���� �ν�.(�νĹ��� ����)
			{
				if (_vMonster[i]->getCoolDown() == false)
				{
					if (getDistance(_vMonster[i]->getMonsterInfo().rc.left, _vMonster[i]->getMonsterInfo().y,
						_alucard->GetAlucard().x, _alucard->GetAlucard().y) <
						getDistance(_vMonster[i]->getMonsterInfo().rc.right, _vMonster[i]->getMonsterInfo().y,
							_alucard->GetAlucard().x, _alucard->GetAlucard().y) && _vMonster[i]->getMonsterInfo().behavior != KNIGHT_RIGHT_STAB)
						//������ rc Left�� rc Right �� ���ؼ� ���� ������ �����մϴ�.
						//�߰��� ������ �ٲٴ� ���� ������ "�ݴ������ ������ ������� �ʰ��������� ����" ������ �־����ϴ�
						//���� ���� ����.
					{
						_vMonster[i]->setMonsterHavior(KNIGHT_LEFT_STAB);
					}

					else if (getDistance(_vMonster[i]->getMonsterInfo().rc.left, _vMonster[i]->getMonsterInfo().y,
						_alucard->GetAlucard().x, _alucard->GetAlucard().y) >
						getDistance(_vMonster[i]->getMonsterInfo().rc.right, _vMonster[i]->getMonsterInfo().y,
							_alucard->GetAlucard().x, _alucard->GetAlucard().y) && _vMonster[i]->getMonsterInfo().behavior != KNIGHT_LEFT_STAB)
						//������ ���� ����.
					{
						_vMonster[i]->setMonsterHavior(KNIGHT_RIGHT_STAB);
					}
				}
				//�������������������������������������������������������
				//��� ����� ����ǰ� CoolDown �� ���������� ���� ������ ���� �ȴ�.
				if (_vMonster[i]->getCoolDown())
				{
					if (getDistance(_vMonster[i]->getMonsterInfo().x, _vMonster[i]->getMonsterInfo().y,
						_alucard->GetAlucard().x, _alucard->GetAlucard().y) < 400.f)
					{
						if (getDistance(_vMonster[i]->getMonsterInfo().rc.left, _vMonster[i]->getMonsterInfo().y,
							_alucard->GetAlucard().x, _alucard->GetAlucard().y) <
							getDistance(_vMonster[i]->getMonsterInfo().rc.right, _vMonster[i]->getMonsterInfo().y,
								_alucard->GetAlucard().x, _alucard->GetAlucard().y))
						{
							_vMonster[i]->setMonsterState(MOVE_LEFT);

						}
						else if (getDistance(_vMonster[i]->getMonsterInfo().rc.left, _vMonster[i]->getMonsterInfo().y,
							_alucard->GetAlucard().x, _alucard->GetAlucard().y) >
							getDistance(_vMonster[i]->getMonsterInfo().rc.right, _vMonster[i]->getMonsterInfo().y,
								_alucard->GetAlucard().x, _alucard->GetAlucard().y))
						{
							_vMonster[i]->setMonsterState(MOVE_RIGHT);
						}
					}

					if (getDistance(_vMonster[i]->getMonsterInfo().x, _vMonster[i]->getMonsterInfo().y,
						_alucard->GetAlucard().x, _alucard->GetAlucard().y) < 200.f)
					{
						if (getDistance(_vMonster[i]->getMonsterInfo().rc.left, _vMonster[i]->getMonsterInfo().y,
							_alucard->GetAlucard().x, _alucard->GetAlucard().y) <
							getDistance(_vMonster[i]->getMonsterInfo().rc.right, _vMonster[i]->getMonsterInfo().y,
								_alucard->GetAlucard().x, _alucard->GetAlucard().y))
						{
							_vMonster[i]->setMonsterState(ATTACK2_LEFT);
						}
						else if (getDistance(_vMonster[i]->getMonsterInfo().rc.left, _vMonster[i]->getMonsterInfo().y,
							_alucard->GetAlucard().x, _alucard->GetAlucard().y) >
							getDistance(_vMonster[i]->getMonsterInfo().rc.right, _vMonster[i]->getMonsterInfo().y,
								_alucard->GetAlucard().x, _alucard->GetAlucard().y))
						{
							_vMonster[i]->setMonsterState(ATTACK2_RIGHT);
						}
					}
					else
						//�Ÿ��� �־����� ������ MOVING ���� ��ȯ�մϴ�.
					{
						_vMonster[i]->setMonsterHavior(MOVING);
					}
				}
			}
			else if (getDistance(_vMonster[i]->getMonsterInfo().x, _vMonster[i]->getMonsterInfo().y,
				_alucard->GetAlucard().x, _alucard->GetAlucard().y) > 400.f)
			{
				_vMonster[i]->setCoolDown(false);
			}
		}

		//�������������������������������������������������������
	}
}

void MonsterManager::SkeletonKnightBehavior()
{
	for (int i = 0; i < _vMonster.size(); i++)
	{
		if (_vMonster.size() == 0) return;

		//�������������������������������������������������������
		if (_vMonster[i]->getMonsterInfo().monsterType == MONSTER_SKELETONKNIGHT)
			//���̷��� ����� �ൿ ����.
		{
			if (getDistance(_vMonster[i]->getMonsterInfo().x, _vMonster[i]->getMonsterInfo().y,
				_alucard->GetAlucard().x, _alucard->GetAlucard().y) < 100.f)
				//���� �����ȿ� (100.0f) ��������
			{
				if (getDistance(_vMonster[i]->getMonsterRect().left, _vMonster[i]->getMonsterInfo().y,
					_alucard->GetAlucard().x, _alucard->GetAlucard().y) <
					getDistance(_vMonster[i]->getMonsterRect().right, _vMonster[i]->getMonsterInfo().y,
						_alucard->GetAlucard().x, _alucard->GetAlucard().y))
					//������ ��Ʈ Left�� �� �����ٸ�, Alucard���� �Ÿ���.
				{
					_vMonster[i]->setMonsterHavior(ATTACKING_LEFT);
					//Left Attack ����.
				}
				else if (getDistance(_vMonster[i]->getMonsterRect().left, _vMonster[i]->getMonsterInfo().y,
					_alucard->GetAlucard().x, _alucard->GetAlucard().y) >
					getDistance(_vMonster[i]->getMonsterRect().right, _vMonster[i]->getMonsterInfo().y,
						_alucard->GetAlucard().x, _alucard->GetAlucard().y))
					//������ ��Ʈ Right�� �� �����ٸ�, Alucard���� �Ÿ���.
				{
					_vMonster[i]->setMonsterHavior(ATTACKING_RIGHT);
					//Right Attack ����.
				}
			}
			//�Ÿ��� �־����� ������ �����մϴ�.
			else
			{
				_vMonster[i]->setMonsterHavior(MOVING);
			}
		}
	}
}

void MonsterManager::GargoyleAndSlogra()
{
	for (int i = 0; i < _vMonster.size(); i++)
	{
		if (_vMonster.size() == 0) return;

		//������������������������������������������������������� �������� ����.
		if (_vMonster[i]->getMonsterInfo().monsterType == BOSS_GARGOYLE)
		{
			if (getDistance(_vMonster[i]->getMonsterInfo().x, _vMonster[i]->getMonsterInfo().y,
				_alucard->GetAlucard().x, _alucard->GetAlucard().y) < 500.f)
				//��ī����� �Ÿ�
			{
				if (_vMonster[i]->getMonsterInfo().state == MOVE_LEFT ||
					_vMonster[i]->getMonsterInfo().state == MOVE_RIGHT)
					//�������������������������������������������������������
					//1. ���� ������ ���� �϶�.
				{
					_pattern.random = RND->getInt(2);
					_pattern.timer++;

					if (_pattern.random == 0 && _pattern.timer > 150)
						//������ �Ҳɹ߻� (�����ð�)
					{
						_pattern.timer = 0;

						//ĳ���Ϳ� �Ÿ��� ����ؼ� Left �Ǵ� Right������ �����մϴ�.
						if (getDistance(_vMonster[i]->getMonsterInfo().rc.right, _vMonster[i]->getMonsterInfo().y,
							_alucard->GetAlucard().x, _alucard->GetAlucard().y) >
							getDistance(_vMonster[i]->getMonsterInfo().rc.left, _vMonster[i]->getMonsterInfo().y,
								_alucard->GetAlucard().x, _alucard->GetAlucard().y))
						{
							_vMonster[i]->setMonsterState(ATTACK2_LEFT);
						}
						else if (getDistance(_vMonster[i]->getMonsterInfo().rc.right, _vMonster[i]->getMonsterInfo().y,
							_alucard->GetAlucard().x, _alucard->GetAlucard().y) <
							getDistance(_vMonster[i]->getMonsterInfo().rc.left, _vMonster[i]->getMonsterInfo().y,
								_alucard->GetAlucard().x, _alucard->GetAlucard().y))
						{
							_vMonster[i]->setMonsterState(ATTACK2_RIGHT);
						}

					}
					else if (_pattern.random == 1 && _pattern.timer > 150)
						//�������� ���
					{
						_pattern.timer = 0;
						_vMonster[i]->setMonsterState(IDLE_LEFT);
					}

				}
				else if (_vMonster[i]->getMonsterInfo().state == IDLE_LEFT ||
					_vMonster[i]->getMonsterInfo().state == IDLE_RIGHT)
					//�������������������������������������������������������
					//2. ���߿� �� �����϶�.
				{
					//������������ ���߿��� ������ �ൿ�� ����.
					_pattern.timer++;
					_pattern.random = RND->getInt(2);
					_vMonster[i]->setMonsterGravity(false);
					//���߿� �� �����϶��� ��ī�带 �����Ѵ�.
					_vMonster[i]->GotoAngleSpeed(_alucard->GetAlucard().x + 130, _alucard->GetAlucard().y - 150, 7.f);
					
					if (_pattern.random == 0 && _pattern.timer > 150)
						//������ 0 �̰� �����ð��� ������ ATTACK ���·� ����.
					{
						_pattern.timer = 0;

						if (getDistance(_vMonster[i]->getMonsterInfo().rc.right, _vMonster[i]->getMonsterInfo().y,
							_alucard->GetAlucard().x, _alucard->GetAlucard().y) >
							getDistance(_vMonster[i]->getMonsterInfo().rc.left, _vMonster[i]->getMonsterInfo().y,
								_alucard->GetAlucard().x, _alucard->GetAlucard().y))
						{
							_vMonster[i]->setMonsterState(ATTACK_LEFT);
						}
						else if (getDistance(_vMonster[i]->getMonsterInfo().rc.right, _vMonster[i]->getMonsterInfo().y,
							_alucard->GetAlucard().x, _alucard->GetAlucard().y) < 
							getDistance(_vMonster[i]->getMonsterInfo().rc.left, _vMonster[i]->getMonsterInfo().y,
								_alucard->GetAlucard().x, _alucard->GetAlucard().y))
						{
							_vMonster[i]->setMonsterState(ATTACK_RIGHT);
						}
	
					}
					else if (_pattern.random == 1 && _pattern.timer > 150)
						//������ ����.
					{
						_vMonster[i]->setMonsterState(MOVE_LEFT);
						_vMonster[i]->setMonsterGravity(true);
						_pattern.timer = 0;
					}

				}
				else if (_vMonster[i]->getMonsterInfo().state == ATTACK_LEFT ||
					_vMonster[i]->getMonsterInfo().state == ATTACK_RIGHT)
					//�������������������������������������������������������
					//2. ���߿� ���� �극���� �߻��ϰ��ִ� ����.
				{
					_pattern.timer++;

					if (_pattern.timer % 30 == 0)
					{
						_vMonster[i]->GetMAttack()->MagicFireAngle(_vMonster[i]->getMonsterInfo().x, _vMonster[i]->getMonsterInfo().y - 35,
							getAngle(_vMonster[i]->getMonsterInfo().x, _vMonster[i]->getMonsterInfo().y,
								_alucard->GetAlucard().x, _alucard->GetAlucard().y), 7.0f, 1);
					}

					if (_pattern.timer > 300)
					{
						_pattern.timer = 0;
						_vMonster[i]->setMonsterState(IDLE_LEFT);
					}
				}
				else if (_vMonster[i]->getMonsterInfo().state == ATTACK2_LEFT ||
					_vMonster[i]->getMonsterInfo().state == ATTACK2_RIGHT)
					//�������������������������������������������������������
					//2. ���󿡼� �극���� �߻��ϰ��ִ� ����.
				{
					_pattern.timer++;

					if (_pattern.timer % 30 == 0)
					{
						if (_vMonster[i]->getMonsterInfo().state == ATTACK2_LEFT)
						{
							_vMonster[i]->GetMAttack()->MagicFire(_vMonster[i]->getMonsterInfo().x, _vMonster[i]->getMonsterInfo().y - 35,
								7.0f, 0, 2);
						}
						else if (_vMonster[i]->getMonsterInfo().state == ATTACK2_RIGHT)
						{
							_vMonster[i]->GetMAttack()->MagicFire(_vMonster[i]->getMonsterInfo().x, _vMonster[i]->getMonsterInfo().y - 35,
								7.0f, 1, 2);
						}
					}

					if (_pattern.timer > 300)
					{
						_pattern.timer = 0;
						_vMonster[i]->setMonsterState(MOVE_LEFT);
					}
				}
			}
		}
		//������������������������������������������������������� ���α׶��� ����.
		if (_vMonster[i]->getMonsterInfo().monsterType == BOSS_SLOGRA)
		{
			if (getDistance(_vMonster[i]->getMonsterInfo().x, _vMonster[i]->getMonsterInfo().y,
				_alucard->GetAlucard().x, _alucard->GetAlucard().y) < 500.f &&
				getDistance(_vMonster[i]->getMonsterInfo().x, _vMonster[i]->getMonsterInfo().y,
				_alucard->GetAlucard().x, _alucard->GetAlucard().y) > 150.f)
		//ĳ���Ϳ� �������� �������ִٸ� ĳ���� �ձ��� �̵�.
		//�̵� ���� ����.
			{
			if (getDistance(_vMonster[i]->getMonsterInfo().rc.left, _vMonster[i]->getMonsterInfo().y,
				_alucard->GetAlucard().x, _alucard->GetAlucard().y) >
				getDistance(_vMonster[i]->getMonsterInfo().rc.right, _vMonster[i]->getMonsterInfo().y,
					_alucard->GetAlucard().x, _alucard->GetAlucard().y))
			{
				//�÷��̾ ������������ ����ó��. �÷��̾ ���ͺ��� ���� ������ ������ ����Ƽ� ��, �� ��û���� 
				//�Դٰ��� �մϴ�.
				if (_vMonster[i]->getMonsterInfo().rc.left < _alucard->GetAlucard().rc.right &&
					_vMonster[i]->getMonsterInfo().rc.right > _alucard->GetAlucard().rc.left &&
					_vMonster[i]->getMonsterInfo().y > _alucard->GetAlucard().y)
				{
					_vMonster[i]->setMonsterState(IDLE_RIGHT);
				}
				else
				{
					_vMonster[i]->setMonsterState(MOVE_RIGHT);
				}

			}
			else if (getDistance(_vMonster[i]->getMonsterInfo().rc.left, _vMonster[i]->getMonsterInfo().y,
				_alucard->GetAlucard().x, _alucard->GetAlucard().y) <
				getDistance(_vMonster[i]->getMonsterInfo().rc.right, _vMonster[i]->getMonsterInfo().y,
					_alucard->GetAlucard().x, _alucard->GetAlucard().y))
			{
				if (_vMonster[i]->getMonsterInfo().rc.left < _alucard->GetAlucard().rc.right &&
					_vMonster[i]->getMonsterInfo().rc.right > _alucard->GetAlucard().rc.left &&
					_vMonster[i]->getMonsterInfo().y > _alucard->GetAlucard().y)
				{
					_vMonster[i]->setMonsterState(IDLE_LEFT);
				}
				else
				{
					_vMonster[i]->setMonsterState(MOVE_LEFT);
				}

			}

			}

			else if (getDistance(_vMonster[i]->getMonsterInfo().x, _vMonster[i]->getMonsterInfo().y,
			_alucard->GetAlucard().x, _alucard->GetAlucard().y) < 150.f)
			//ĳ���Ϳ� �����ߴٸ� ATTACK State�� ������.
			{
			if (getDistance(_vMonster[i]->getMonsterInfo().rc.left, _vMonster[i]->getMonsterInfo().y,
				_alucard->GetAlucard().x, _alucard->GetAlucard().y) >
				getDistance(_vMonster[i]->getMonsterInfo().rc.right, _vMonster[i]->getMonsterInfo().y,
					_alucard->GetAlucard().x, _alucard->GetAlucard().y))
			{
				_vMonster[i]->setMonsterState(ATTACK_RIGHT);
			}

			else if (getDistance(_vMonster[i]->getMonsterInfo().rc.left, _vMonster[i]->getMonsterInfo().y,
				_alucard->GetAlucard().x, _alucard->GetAlucard().y) <
				getDistance(_vMonster[i]->getMonsterInfo().rc.right, _vMonster[i]->getMonsterInfo().y,
					_alucard->GetAlucard().x, _alucard->GetAlucard().y))
			{
				_vMonster[i]->setMonsterState(ATTACK_LEFT);
			}
			}
		}
	}
}

void MonsterManager::DeathBehavior()
{
	for (int i = 0; i < _vMonster.size(); i++)
	{
		if (_vMonster.size() == 0) return;

		if (_vMonster[i]->getMonsterInfo().monsterType == BOSS_REAPER)
		{
			if (getDistance(_vMonster[i]->getMonsterInfo().x, _vMonster[i]->getMonsterInfo().y,
				_alucard->GetAlucard().x, _alucard->GetAlucard().y) < 700.f)
			{
				//������������������������������������������������������� Phase 1
				if (_vMonster[i]->getMonsterInfo().hp > 250)
				{
					if (_vMonster[i]->getMonsterInfo().state == IDLE_LEFT ||
						_vMonster[i]->getMonsterInfo().state == IDLE_RIGHT)
					{
						_pattern.timer++;
						_pattern.random = RND->getInt(4);
						//SpeedMove�� isStop�� false�� �ǵ��������ʴ� ������ �־ Idle �����ϋ�
						//������ false�� ����.
						_vMonster[i]->SetisStop(false);
						//Idle �����϶� ī��Ʈ �ö󰡰� ������ ���� �����Ͽ� ���� �� �ൿ�� �����մϴ�.
						//���� ���� 
						if (_pattern.timer > 120 && _pattern.random == 0)
						{
							_pattern.timer = 0;
							_vMonster[i]->setMonsterState(ATTACK_LEFT);
						}
						else if (_pattern.timer > 120 && _pattern.random == 1)
						{
							_pattern.timer = 0;
							_vMonster[i]->setMonsterState(ATTACK_RIGHT);
						}
						else if (_pattern.timer > 120 && _pattern.random == 2)
						{
							_pattern.timer = 0;
							_vMonster[i]->setMonsterState(ATTACK3_LEFT);
						}
						else if (_pattern.timer > 120 && _pattern.random == 3)
						{
							_pattern.timer = 0;
							_vMonster[i]->setMonsterState(ATTACK3_RIGHT);
						}
					}
					//����� ���¿� ���� �����ð����� ������ �����ϰ� �ð��� �ٵǸ� �ٽ� Idle ���·� ���ƿɴϴ�.
					else if (_vMonster[i]->getMonsterInfo().state == ATTACK_LEFT)
					{
						_pattern.timer++;
						_vMonster[i]->GotoAngleSpeed(3050, 500, 7.0f);

						if (_pattern.timer % 25 == 0)
						{
							int randomX = RND->getFromIntTo(2302, 3140);
							int randomY = RND->getFromIntTo(50, 80);
							_vMonster[i]->GetMAttack()->MagicFireAngle(randomX, randomY, getAngle(randomX, randomY,
								_alucard->GetAlucard().x, _alucard->GetAlucard().y), 5.0f, 3);
						}

						if (_pattern.timer > 250)
						{
							_vMonster[i]->setMonsterState(IDLE_LEFT);
							_pattern.timer = 0;
						}
					}

					else if (_vMonster[i]->getMonsterInfo().state == ATTACK_RIGHT)
					{
						_pattern.timer++;
						_vMonster[i]->GotoAngleSpeed(2280, 500, 7.0f);

						if (_pattern.timer % 25 == 0)
						{
							int randomX = RND->getFromIntTo(2302, 3140);
							int randomY = RND->getFromIntTo(50, 80);
							_vMonster[i]->GetMAttack()->MagicFireAngle(randomX, randomY, getAngle(randomX, randomY,
								_alucard->GetAlucard().x, _alucard->GetAlucard().y), 5.0f, 3);
						}

						if (_pattern.timer > 250)
						{
							_vMonster[i]->setMonsterState(IDLE_LEFT);
							_pattern.timer = 0;
						}
					}

					else if (_vMonster[i]->getMonsterInfo().state == ATTACK3_LEFT)
					{
						_pattern.timer++;
						_vMonster[i]->GotoAngleSpeed(3050, 500, 7.0f);

						if (_pattern.timer == 80) _vMonster[i]->GetMAttack()->MagicFire(3080, 585, 4.0f, 0, 4);
						else if (_pattern.timer == 160) _vMonster[i]->GetMAttack()->MagicFire(3080, 500, 4.0f, 0, 4);
						else if (_pattern.timer == 240) _vMonster[i]->GetMAttack()->MagicFire(3080, 425, 4.0f, 0, 4);
							

						if (_pattern.timer > 250)
						{
							_vMonster[i]->setMonsterState(IDLE_LEFT);
							_pattern.timer = 0;
						}
					}

					else if (_vMonster[i]->getMonsterInfo().state == ATTACK3_RIGHT)
					{
						_pattern.timer++;
						_vMonster[i]->GotoAngleSpeed(2280, 500, 7.0f);

						if (_pattern.timer == 80) _vMonster[i]->GetMAttack()->MagicFire(2270, 585, 4.0f, 1, 4);
						else if (_pattern.timer == 160) _vMonster[i]->GetMAttack()->MagicFire(2270, 500, 4.0f, 1, 4);
						else if (_pattern.timer == 240) _vMonster[i]->GetMAttack()->MagicFire(2270, 425, 4.0f, 1, 4);

						if (_pattern.timer > 250)
						{
							_vMonster[i]->setMonsterState(IDLE_LEFT);
							_pattern.timer = 0;
						}
					}
				}
				//������������������������������������������������������� Phase 2
				else if (_vMonster[i]->getMonsterInfo().hp < 250)
				{
					//1�������� ���� ���߿� �¾ƹ����� ó�� ���� ���°� Idle���°� �ƴϴϱ� ������ ���������.
					//ó������  ����üũ ���ְ� Idle ���·� ������.
					if (!_pattern.check)
					{
						_pattern.check = true;
						_vMonster[i]->setMonsterState(IDLE_LEFT);
					}
					if (_vMonster[i]->getMonsterInfo().state == IDLE_LEFT ||
						_vMonster[i]->getMonsterInfo().state == IDLE_RIGHT)
					{
						_vMonster[i]->SetisStop(false);
						_pattern.timer++;
						_pattern.random = RND->getInt(4);
						//Idle �����϶� ī��Ʈ �ö󰡰� ������ ���� �����Ͽ� ���� �� �ൿ�� �����մϴ�.
						//���� ���� 
						if (_pattern.timer > 80 && _pattern.random == 0)
						{
							_pattern.timer = 0;
							_vMonster[i]->setMonsterState(ATTACK2_LEFT);
						}
						else if (_pattern.timer > 80 && _pattern.random == 1)
						{
							_pattern.timer = 0;
							_vMonster[i]->setMonsterState(ATTACK2_RIGHT);
						}
						else if (_pattern.timer > 80 && _pattern.random == 2)
						{
							_pattern.timer = 0;
							_vMonster[i]->setMonsterState(ATTACK3_LEFT);
						}
						else if (_pattern.timer > 80 && _pattern.random == 3)
						{
							_pattern.timer = 0;
							_vMonster[i]->setMonsterState(ATTACK3_LEFT);
						}
					}
					//����� ���¿� ���� �����ð����� ������ �����ϰ� �ð��� �ٵǸ� �ٽ� Idle ���·� ���ƿɴϴ�.
					else if (_vMonster[i]->getMonsterInfo().state == ATTACK2_LEFT)
					{
						_vMonster[i]->GotoAngleSpeed(2700, 300, 2.5f);
						_pattern.timer++;

						if (_pattern.timer == 3)
						{
							//������ ������ �����Ǵ� �װ��� ������.
							for (int j = 0; j < 4; j++)
							{
								_vMonster[i]->GetMAttack()->MagicFireAngleDuration(2300 + j * 250, 75, getAngle(2300, 60, 
									_alucard->GetAlucard().x, _alucard->GetAlucard().y),
									_pattern.speed, 5, 600);
							}
						}

						if (_pattern.timer % 10 == 0)
						{
							//���� �ӵ��� �������� ���� ��ü
							for (int j = 0; j < 4; j++)
							{
								_vMonster[i]->GetMAttack()->MagicFireAngle(2330 + j * 250, 85, getAngle(2330 + j * 250, 85,
									2330 + j * 250, 750), 5.0f, 3);
							}
						}
						
						if (_pattern.timer % 100 == 0)
						{
							//�������� �������� ���� �ذ�
							int headRandSet = RND->getFromIntTo(190, 550);

							_vMonster[i]->GetMAttack()->MagicFire(2100, headRandSet, 6.5f, 1, 4);
						}

						if (_pattern.timer % 100 == 0)
						{
							//�������� �������� ���� �ذ�
							int headRandSet2 = RND->getFromIntTo(190, 550);

							_vMonster[i]->GetMAttack()->MagicFire(3100, headRandSet2, 6.5f, 0, 4);
						}

						if (_pattern.timer > 600)
						{
							_vMonster[i]->setMonsterState(IDLE_LEFT);
							_pattern.timer = 0;
						}
					}

					else if (_vMonster[i]->getMonsterInfo().state == ATTACK2_RIGHT)
					{
						_vMonster[i]->GotoAngleSpeed(2700, 300, 2.5f);
						_pattern.timer++;

						if (_pattern.timer == 3)
						{	
							//������ ������ �����Ǵ� �װ��� ������.
							for (int j = 0; j < 4; j++)
							{
								_vMonster[i]->GetMAttack()->MagicFireAngleDuration(2300 + j * 250, 75, getAngle(2300, 60,
									_alucard->GetAlucard().x, _alucard->GetAlucard().y),
									_pattern.speed, 5, 600);
							}
						}

						if (_pattern.timer % 10 == 0)
						{	
							//���� �ӵ��� �������� ���� ��ü
							for (int j = 0; j < 4; j++)
							{
								_vMonster[i]->GetMAttack()->MagicFireAngle(2330 + j * 250, 85, getAngle(2330 + j * 250, 85,
									2330 + j * 250, 750), 5.0f, 3);
							}
						}

						if (_pattern.timer % 100 == 0)
						{
							//�������� �������� ���� �ذ�
							int headRandSet = RND->getFromIntTo(190, 550);

							_vMonster[i]->GetMAttack()->MagicFire(2100, headRandSet, 6.5f, 1, 4);
						}

						if (_pattern.timer % 100 == 0)
						{
							//�������� �������� ���� �ذ�
							int headRandSet = RND->getFromIntTo(190, 550);

							_vMonster[i]->GetMAttack()->MagicFire(3100, headRandSet, 6.5f, 0, 4);
						}

						if (_pattern.timer > 600)
						{
							_vMonster[i]->setMonsterState(IDLE_LEFT);
							_pattern.timer = 0;
						}
					}

					else if (_vMonster[i]->getMonsterInfo().state == ATTACK3_LEFT)
					{
						_vMonster[i]->GotoAngleSpeed(3050, 500, 7.0f);
						_pattern.timer++;

						if (_pattern.timer % 20 == 0)
						{
							int randX = RND->getFromIntTo(2250, 3160);
							int randY = RND->getFromIntTo(40, 670);

							_vMonster[i]->GetMAttack()->MagicFireAngleDuration(randX, randY, getAngle(randX, randY,
								_alucard->GetAlucard().x, _alucard->GetAlucard().y), 0.f, 3, 50);
						}

						if (_pattern.timer > 300)
						{
							_vMonster[i]->setMonsterState(IDLE_LEFT);
							_pattern.timer = 0;
						}
					}

					else if (_vMonster[i]->getMonsterInfo().state == ATTACK3_RIGHT)
					{
						_vMonster[i]->GotoAngleSpeed(2280, 500, 7.0f);
						_pattern.timer++;

						if (_pattern.timer % 20 == 0)
						{
							int randX = RND->getFromIntTo(2250, 3160);
							int randY = RND->getFromIntTo(40, 670);

							_vMonster[i]->GetMAttack()->MagicFireAngleDuration(randX, randY, getAngle(randX, randY,
								_alucard->GetAlucard().x, _alucard->GetAlucard().y), 0.f, 3, 50);
						}

						if (_pattern.timer > 300)
						{
							_vMonster[i]->setMonsterState(IDLE_LEFT);
							_pattern.timer = 0;
						}
					}
				}
			}
		}
	}
}

void MonsterManager::Merman_Set(float posx, float posy, bool activeGravity)
{
	Monster_Merman*  _merman;
	_merman = new Monster_Merman;
	_merman->init(posx, posy, 2, activeGravity);

	_vMonster.push_back(_merman);
}

void MonsterManager::Gergoyle_Set(float posx, float posy, bool activegravity)
{
	Boss_Gargoyle* _gargoyle;
	_gargoyle = new Boss_Gargoyle;
	_gargoyle->init(posx, posy,5 , activegravity);

	_vMonster.push_back(_gargoyle);
}

void MonsterManager::Slogra_Set(float posx, float posy, bool activegravity)
{
	Boss_Slogra* _slogra;
	_slogra = new Boss_Slogra;
	_slogra->init(posx, posy, 6, activegravity);

	_vMonster.push_back(_slogra);
}

void MonsterManager::DeathSet(float posx, float posy, bool activegravity)
{
	Boss_Death* _death;
	_death = new Boss_Death;
	_death->init(posx, posy, 7, false);

	_vMonster.push_back(_death);
}

void MonsterManager::Skeleton_Knight_Set(float posx ,float posy, bool activeGravity)
{
	Monster_Skeleton_Knight* _skeletonKnight;
	_skeletonKnight = new Monster_Skeleton_Knight;
	_skeletonKnight->init(posx, posy, 3, activeGravity);

	_vMonster.push_back(_skeletonKnight);
}

void MonsterManager::Skeleton_Set(float posx, float posy, bool activeGravity)
{
	Monster_Skeleton* _skeleton;
	_skeleton = new Monster_Skeleton;
	_skeleton->init(posx, posy, activeGravity, 0);

	_vMonster.push_back(_skeleton);
}

void MonsterManager::Medusa_Head_Set(float posx, float posy, bool activeGravity, int medusaKind, bool direction)
{
	Monster_Medusa_Head* _medusa;
	_medusa = new Monster_Medusa_Head;
	_medusa->init(posx, posy, activeGravity, 1, medusaKind, direction);

	_vMonster.push_back(_medusa);
}

void MonsterManager::Armored_Knight_Set(float posx, float posy, bool activeGravity)
{
	Monster_Armored_Knight* _armoredKight;
	_armoredKight = new Monster_Armored_Knight;
	_armoredKight->init(posx, posy, 4, activeGravity);

	_vMonster.push_back(_armoredKight);
}

