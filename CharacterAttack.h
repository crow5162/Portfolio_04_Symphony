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

	//��ī���� �� ���� (�ѷ��� X, �ѷ��� Y, �˰��� Ÿ�� (0, 1), ���� (0 ������, 1����))
	void SwordAttack(float x, float y);
	//��ī���� �����̾� ���� (���� x, y, Ÿ�� x, y, ���ǵ� ��)
	void HellFire(float x, float y, float angle, float speed);
	//���������� ������.
	void CharacterMagicMove();

	//�ð��� ������ ���� ���ݷ�Ʈ ����.
	void EraseAttack();
	//ȭ���� ����� ���� ����
	void EraseAttack2();
	//Attavk Vector Delete (InterscetRect)
	void AttackDelete(int arrNum);

	vector<AlucardAttack>		    getAttackVector()     { return _vAttack; }
	vector<AlucardAttack>::iterator getAttackVectorIter() { return _viAttack; }
};

