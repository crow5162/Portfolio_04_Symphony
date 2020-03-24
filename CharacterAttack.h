#pragma once
#include "gameNode.h"

enum CharacterAttackType
{
	NormalAttack,
	MagicAttack,
};

struct AlucardAttack
{
	RECT rc;
	float x, y;
	float targetX, targetY;
	float duration;
	float angle;
	float speed;
	image* img;

	int currentX;
	int currentY;
	int frameCount;
	int direction;
	animation* ani;
	CharacterAttackType type;
};

class CharacterAttack : public gameNode
{
private:
	vector<AlucardAttack>			_vAttack;
	vector<AlucardAttack>::iterator _viAttack;

public:
	CharacterAttack() {};
	~CharacterAttack() {};

	virtual HRESULT init();
	virtual void update();
	virtual void release();
	virtual void render();

	//알카드의 검 공격 (뿌려질 X, 뿌려질 Y, 검공격 타입 (0, 1), 방향 (0 오른쪽, 1왼쪽))
	void SwordAttack(float x, float y);
	//알카드의 헬파이어 공격 (시작 x, y, 타겟 x, y, 스피드 값)
	void HellFire(float x, float y, float angle, float speed);
	//마법공격의 움직임.
	void CharacterMagicMove();

	//시간이 지남에 따라 공격렉트 삭제.
	void EraseAttack();
	//화면을 벗어나면 공격 삭제
	void EraseAttack2();
	//Attavk Vector Delete (InterscetRect)
	void AttackDelete(int arrNum);

	vector<AlucardAttack>		    getAttackVector()     { return _vAttack; }
	vector<AlucardAttack>::iterator getAttackVectorIter() { return _viAttack; }
};

