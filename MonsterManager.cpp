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
	//몬스터 제거
	for (_viMonster = _vMonster.begin(); _viMonster != _vMonster.end();)
	{
		if (_vMonster.size() == 0) return;

		//몬스터의 체력이 0 이 되면 삭제됩니다.
		if ((*_viMonster)->getMonsterInfo().hp <= 0)
		{
			DATA->playerInfo.Kills += 1;

			//몬스터의 타입에 따라 이펙트
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

		//화면밖을 나가는 몬스터를 삭제
		else if ((*_viMonster)->getMonsterInfo().x < 0 || (*_viMonster)->getMonsterInfo().x > CAMERAMANAGER->getWorldCameraSize())
		{
			//화면밖을 나가는 몬스터는 메두사의 머리뿐입니다.
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

		//■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
		if (_vMonster[i]->getMonsterInfo().monsterType == MONSTER_KNIGHT)
			//갑옷 기사의 행동패턴.
		{
			if (getDistance(_vMonster[i]->getMonsterInfo().x, _vMonster[i]->getMonsterInfo().y,
				_alucard->GetAlucard().x, _alucard->GetAlucard().y) < 500.f)
				//갑옷기사와 일정거리만큼 가까워 지면 인식.(인식범위 설정)
			{
				if (_vMonster[i]->getCoolDown() == false)
				{
					if (getDistance(_vMonster[i]->getMonsterInfo().rc.left, _vMonster[i]->getMonsterInfo().y,
						_alucard->GetAlucard().x, _alucard->GetAlucard().y) <
						getDistance(_vMonster[i]->getMonsterInfo().rc.right, _vMonster[i]->getMonsterInfo().y,
							_alucard->GetAlucard().x, _alucard->GetAlucard().y) && _vMonster[i]->getMonsterInfo().behavior != KNIGHT_RIGHT_STAB)
						//몬스터의 rc Left와 rc Right 를 비교해서 공격 방향을 결정합니다.
						//중간에 방향을 바꾸는 일이 없도록 "반대방향의 동작이 실행되지 않고있을때만 실행" 조건을 주었습니다
						//왼쪽 방향 조건.
					{
						_vMonster[i]->setMonsterHavior(KNIGHT_LEFT_STAB);
					}

					else if (getDistance(_vMonster[i]->getMonsterInfo().rc.left, _vMonster[i]->getMonsterInfo().y,
						_alucard->GetAlucard().x, _alucard->GetAlucard().y) >
						getDistance(_vMonster[i]->getMonsterInfo().rc.right, _vMonster[i]->getMonsterInfo().y,
							_alucard->GetAlucard().x, _alucard->GetAlucard().y) && _vMonster[i]->getMonsterInfo().behavior != KNIGHT_LEFT_STAB)
						//오른쪽 방향 조건.
					{
						_vMonster[i]->setMonsterHavior(KNIGHT_RIGHT_STAB);
					}
				}
				//■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
				//찌르기 모션이 실행되고 CoolDown 이 켜져있을땐 베기 공격이 실행 된다.
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
						//거리가 멀어지면 무조건 MOVING 으로 전환합니다.
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

		//■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
	}
}

void MonsterManager::SkeletonKnightBehavior()
{
	for (int i = 0; i < _vMonster.size(); i++)
	{
		if (_vMonster.size() == 0) return;

		//■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
		if (_vMonster[i]->getMonsterInfo().monsterType == MONSTER_SKELETONKNIGHT)
			//스켈레톤 기사의 행동 패턴.
		{
			if (getDistance(_vMonster[i]->getMonsterInfo().x, _vMonster[i]->getMonsterInfo().y,
				_alucard->GetAlucard().x, _alucard->GetAlucard().y) < 100.f)
				//일정 범위안에 (100.0f) 들어왔을때
			{
				if (getDistance(_vMonster[i]->getMonsterRect().left, _vMonster[i]->getMonsterInfo().y,
					_alucard->GetAlucard().x, _alucard->GetAlucard().y) <
					getDistance(_vMonster[i]->getMonsterRect().right, _vMonster[i]->getMonsterInfo().y,
						_alucard->GetAlucard().x, _alucard->GetAlucard().y))
					//몬스터의 렉트 Left와 더 가깝다면, Alucard와의 거리가.
				{
					_vMonster[i]->setMonsterHavior(ATTACKING_LEFT);
					//Left Attack 시전.
				}
				else if (getDistance(_vMonster[i]->getMonsterRect().left, _vMonster[i]->getMonsterInfo().y,
					_alucard->GetAlucard().x, _alucard->GetAlucard().y) >
					getDistance(_vMonster[i]->getMonsterRect().right, _vMonster[i]->getMonsterInfo().y,
						_alucard->GetAlucard().x, _alucard->GetAlucard().y))
					//몬스터의 렉트 Right와 더 가깝다면, Alucard와의 거리가.
				{
					_vMonster[i]->setMonsterHavior(ATTACKING_RIGHT);
					//Right Attack 시전.
				}
			}
			//거리가 멀어지면 순찰을 진행합니다.
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

		//■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■ 가고일의 패턴.
		if (_vMonster[i]->getMonsterInfo().monsterType == BOSS_GARGOYLE)
		{
			if (getDistance(_vMonster[i]->getMonsterInfo().x, _vMonster[i]->getMonsterInfo().y,
				_alucard->GetAlucard().x, _alucard->GetAlucard().y) < 500.f)
				//알카드와의 거리
			{
				if (_vMonster[i]->getMonsterInfo().state == MOVE_LEFT ||
					_vMonster[i]->getMonsterInfo().state == MOVE_RIGHT)
					//■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
					//1. 땅에 착지한 상태 일때.
				{
					_pattern.random = RND->getInt(2);
					_pattern.timer++;

					if (_pattern.random == 0 && _pattern.timer > 150)
						//땅에서 불꽃발사 (일정시간)
					{
						_pattern.timer = 0;

						//캐릭터와 거리를 계산해서 Left 또는 Right방향을 결정합니다.
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
						//공중으로 상승
					{
						_pattern.timer = 0;
						_vMonster[i]->setMonsterState(IDLE_LEFT);
					}

				}
				else if (_vMonster[i]->getMonsterInfo().state == IDLE_LEFT ||
					_vMonster[i]->getMonsterInfo().state == IDLE_RIGHT)
					//■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
					//2. 공중에 뜬 상태일때.
				{
					//랜덤값에따라 공중에서 실행할 행동을 결정.
					_pattern.timer++;
					_pattern.random = RND->getInt(2);
					_vMonster[i]->setMonsterGravity(false);
					//공중에 뜬 상태일때는 알카드를 추적한다.
					_vMonster[i]->GotoAngleSpeed(_alucard->GetAlucard().x + 130, _alucard->GetAlucard().y - 150, 7.f);
					
					if (_pattern.random == 0 && _pattern.timer > 150)
						//랜덤값 0 이고 일정시간이 지나면 ATTACK 상태로 간다.
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
						//땅으로 착지.
					{
						_vMonster[i]->setMonsterState(MOVE_LEFT);
						_vMonster[i]->setMonsterGravity(true);
						_pattern.timer = 0;
					}

				}
				else if (_vMonster[i]->getMonsterInfo().state == ATTACK_LEFT ||
					_vMonster[i]->getMonsterInfo().state == ATTACK_RIGHT)
					//■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
					//2. 공중에 떠서 브레스를 발사하고있는 상태.
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
					//■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
					//2. 지상에서 브레스를 발사하고있는 상태.
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
		//■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■ 슬로그라의 패턴.
		if (_vMonster[i]->getMonsterInfo().monsterType == BOSS_SLOGRA)
		{
			if (getDistance(_vMonster[i]->getMonsterInfo().x, _vMonster[i]->getMonsterInfo().y,
				_alucard->GetAlucard().x, _alucard->GetAlucard().y) < 500.f &&
				getDistance(_vMonster[i]->getMonsterInfo().x, _vMonster[i]->getMonsterInfo().y,
				_alucard->GetAlucard().x, _alucard->GetAlucard().y) > 150.f)
		//캐릭터와 일정구간 떨어져있다면 캐릭터 앞까지 이동.
		//이동 방향 결정.
			{
			if (getDistance(_vMonster[i]->getMonsterInfo().rc.left, _vMonster[i]->getMonsterInfo().y,
				_alucard->GetAlucard().x, _alucard->GetAlucard().y) >
				getDistance(_vMonster[i]->getMonsterInfo().rc.right, _vMonster[i]->getMonsterInfo().y,
					_alucard->GetAlucard().x, _alucard->GetAlucard().y))
			{
				//플레이어가 위에있을때의 예외처리. 플레이어가 몬스터보다 위에 있을때 방향을 못잡아서 좌, 우 엄청나게 
				//왔다갔다 합니다.
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
			//캐릭터와 근접했다면 ATTACK State로 돌린다.
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
				//■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■ Phase 1
				if (_vMonster[i]->getMonsterInfo().hp > 250)
				{
					if (_vMonster[i]->getMonsterInfo().state == IDLE_LEFT ||
						_vMonster[i]->getMonsterInfo().state == IDLE_RIGHT)
					{
						_pattern.timer++;
						_pattern.random = RND->getInt(4);
						//SpeedMove의 isStop이 false로 되돌려지지않는 문제가 있어서 Idle 상태일떄
						//강제로 false로 돌림.
						_vMonster[i]->SetisStop(false);
						//Idle 상태일때 카운트 올라가고 랜덤한 값을 도출하여 다음 할 행동을 결정합니다.
						//상태 결정 
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
					//도출된 상태에 따라 일정시간동안 공격을 실행하고 시간이 다되면 다시 Idle 상태로 돌아옵니다.
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
				//■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■ Phase 2
				else if (_vMonster[i]->getMonsterInfo().hp < 250)
				{
					//1페이즈의 공격 도중에 맞아버리면 처음 시작 상태가 Idle상태가 아니니깐 패턴이 멈춰버린다.
					//처음에만  패턴체크 켜주고 Idle 상태로 돌린다.
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
						//Idle 상태일때 카운트 올라가고 랜덤한 값을 도출하여 다음 할 행동을 결정합니다.
						//상태 결정 
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
					//도출된 상태에 따라 일정시간동안 공격을 실행하고 시간이 다되면 다시 Idle 상태로 돌아옵니다.
					else if (_vMonster[i]->getMonsterInfo().state == ATTACK2_LEFT)
					{
						_vMonster[i]->GotoAngleSpeed(2700, 300, 2.5f);
						_pattern.timer++;

						if (_pattern.timer == 3)
						{
							//리퍼의 위에서 생성되는 네개의 마법진.
							for (int j = 0; j < 4; j++)
							{
								_vMonster[i]->GetMAttack()->MagicFireAngleDuration(2300 + j * 250, 75, getAngle(2300, 60, 
									_alucard->GetAlucard().x, _alucard->GetAlucard().y),
									_pattern.speed, 5, 600);
							}
						}

						if (_pattern.timer % 10 == 0)
						{
							//빠른 속도로 내려오는 전기 구체
							for (int j = 0; j < 4; j++)
							{
								_vMonster[i]->GetMAttack()->MagicFireAngle(2330 + j * 250, 85, getAngle(2330 + j * 250, 85,
									2330 + j * 250, 750), 5.0f, 3);
							}
						}
						
						if (_pattern.timer % 100 == 0)
						{
							//좌측에서 우측으로 오는 해골
							int headRandSet = RND->getFromIntTo(190, 550);

							_vMonster[i]->GetMAttack()->MagicFire(2100, headRandSet, 6.5f, 1, 4);
						}

						if (_pattern.timer % 100 == 0)
						{
							//우측에서 좌측으로 오는 해골
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
							//리퍼의 위에서 생성되는 네개의 마법진.
							for (int j = 0; j < 4; j++)
							{
								_vMonster[i]->GetMAttack()->MagicFireAngleDuration(2300 + j * 250, 75, getAngle(2300, 60,
									_alucard->GetAlucard().x, _alucard->GetAlucard().y),
									_pattern.speed, 5, 600);
							}
						}

						if (_pattern.timer % 10 == 0)
						{	
							//빠른 속도로 내려오는 전기 구체
							for (int j = 0; j < 4; j++)
							{
								_vMonster[i]->GetMAttack()->MagicFireAngle(2330 + j * 250, 85, getAngle(2330 + j * 250, 85,
									2330 + j * 250, 750), 5.0f, 3);
							}
						}

						if (_pattern.timer % 100 == 0)
						{
							//좌측에서 우측으로 오는 해골
							int headRandSet = RND->getFromIntTo(190, 550);

							_vMonster[i]->GetMAttack()->MagicFire(2100, headRandSet, 6.5f, 1, 4);
						}

						if (_pattern.timer % 100 == 0)
						{
							//좌측에서 우측으로 오는 해골
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

