#pragma once
#include "Monster.h"

#define MEDUSAHEADSPEED 3.0f
#define MEDUSAWIDTH		45
#define MEDUSAHEIGHT	45

class Monster_Medusa_Head : public Monster
{
private:
	int _count;

	int _moveFrameX, _moveFrameY;
	int _frameCount;

	//�޵λ��� ����(���,�Ķ�) ������ ����.
	int _medusaKind;
	//�޵λ��� �̵����� ����
	bool _direction;

public:
	Monster_Medusa_Head();
	~Monster_Medusa_Head();

	virtual HRESULT init(float x, float y, bool gravityActive, int montertype, int kind, bool direction);
	virtual void update();
	virtual void release();
	virtual void render();

	void MedusaBehavior();

	void MedusaState();
	void LeftMoveFrame();
	void RightMoveFrame();
};

