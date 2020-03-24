#pragma once
#include "gameNode.h"
#include "CharacterAttack.h"
#include "MonsterManager.h"

#define MOVESPEED  5.5f		//��ī�� �ӵ�
#define GRAVITY    0.4f		//��ī�� �߷�  ( Gravity True )
#define GRAVITY2   2.5f		//��ī�� �߷�2 ( Pixel Collision)
#define JUMPPOWER  41.5f	//��ī�� �����Ŀ�

class MonsterManager;
class CharacterAttack;

//�̵����� enum
enum AlucardDirection
{
	DirectionLeft,
	DirectionRight
};

struct BOOLSET
{
	bool aniCheck;       //�÷��̾� �ִϸ��̼� üũ.	
	bool moveCheck;      //�̵����� ��ǰ� �̵��� ��� üũ
	bool gravityCheck;   //�߷� ��/�� üũ
	bool jumpCheck;		 //���� ���� üũ
	bool scaffold;		 //���� üũ
	bool getDamage;		 //������ �Ծ����� üũ.
	bool levelUp;
};

enum AlucardState		 
{						 
	NONE,			 	 
	MOVE,
	BACK_DASH,
	ATTACK,
	AIRATTACK,
	FALLING,
	JUMP,
	DUCK,
	DUCKINGATTACK,
	HIT,
	HELLFIRE,
};

struct ALUCARD
{
	RECT rc;
	float x;
	float y;
	float gravity;		//�߷�1
	float valGravity;	//�߷�2
	float moveSpeed;
	float jumpPower;
	
	int width;
	int height;
	int jumpCount;
	int frameCount;

	BOOLSET boolset;
	AlucardState state;
	animation* ani;
	image* image;
	AlucardDirection direction;
};

//�ܻ�ȿ���� ����ü 
struct AfterImage
{
	image* img;
	image* testimg;
	animation* ani;

	int currentX, currentY;
	int currentX2, currentY2;
	float x, y;
	int alpha;
	int testPosX, testPosY;
};

class Alucard : public gameNode
{
private:

	int _firecount;

	ALUCARD _alucard;

	MonsterManager* _monster;
	CharacterAttack* _attack;

	int _probeX, _probeY;
	int _probeY2;

	//���� �˻�� ī��Ʈ.
	int _scaffoldCount;

	//ĳ���� �ܻ�ȿ���� CurrentFrameX, Y, FrameCounter
	int _currentX, _currentY;

	AfterImage _afterimg[6];

public:
	Alucard();
	~Alucard();

	virtual HRESULT init();
	virtual void update();
	virtual void release();
	virtual void render();

	//Ű�Է�
	void AlucardInputKey();
	//Gravity Bool Set
	void GravitySet();
	//Jump Bool Set
	void isJump();
	//Alucard State
	void State();
	//Pixel Collision
	void CharacterPixelGround();
	void CharacterPixelWall();
	void CharacterPixelTop();
	//��ī���� �ܻ�ȿ�� ó��
	void AlucardAfterImage();
	//��ī���� �ܻ�ȿ�� ó���� FrameImage ���
	void AlucardFrameCounter();
	//��ī�� ���� ���� ���� ��Ʈ
	void AlucardMagicUse();
	//��ī�� ��ġ���� ����
	void AlucardData();

	//Character State
	void Idle();		//��� �ڼ�
	void StartMove();	//�̵����� �ڼ�
	void Moving();		//�̵�
	void Jump();		//�������
	void DoubleJump();	//�̴� ���� ���
	void BackDash();	//��뽬
	void Attack();		//����
	void AttackAir();	//���� ����
	void Falling();		//����
	void Ducking();		//���̱�, ���λ��� ���� ��ȯ.
	void DuckingDirection();
	void DuckingAttack();
	void Hit();			//������ ���ݿ� �ǰ�.
	void Skill();		//��ī���� Ŀ�ǵ� ��ų �ߵ�.

	//���� �Ŵ��� ��ũ
	void SetLink_MonsterManager(MonsterManager* manager) { _monster = manager; }
	//Map���� ��ī���� ��ǥ ���� X, Y
	void SetAlucardX(float x) { _alucard.x = x; }
	void SetAlucardY(float y) { _alucard.y = y; }
	//Alucard Position Set
	void AlucardPositionSet(float* x, float* y);
	//Alucard Struct Get
	ALUCARD GetAlucard() { return _alucard; }
	bool GetAlucardJump() { return _alucard.boolset.jumpCheck; }
	bool GetAlucardHit() { return _alucard.boolset.getDamage; }
	void SetAlucardGravity(bool gravity) { _alucard.boolset.gravityCheck = gravity; }
	void SetAlucardJump(bool jumpcheck)  { _alucard.boolset.jumpCheck = jumpcheck; }
	void SetAlucardJumpCount(int count)  { _alucard.jumpCount = count; }
	void SetAlucardY2(float y) { _alucard.y += y; }
	RECT GetAlucardRect() { return _alucard.rc; }

	//ĳ���� ���� ���� Get
	CharacterAttack* GetCAttack() { return _attack; }	
};

