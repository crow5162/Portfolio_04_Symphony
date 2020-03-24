#pragma once
#include "gameNode.h"
#include "CharacterAttack.h"
#include "MonsterManager.h"

#define MOVESPEED  5.5f		//알카드 속도
#define GRAVITY    0.4f		//알카드 중력  ( Gravity True )
#define GRAVITY2   2.5f		//알카드 중력2 ( Pixel Collision)
#define JUMPPOWER  41.5f	//알카드 점프파웡

class MonsterManager;
class CharacterAttack;

//이동방향 enum
enum AlucardDirection
{
	DirectionLeft,
	DirectionRight
};

struct BOOLSET
{
	bool aniCheck;       //플레이어 애니메이션 체크.	
	bool moveCheck;      //이동시작 모션과 이동중 모션 체크
	bool gravityCheck;   //중력 유/무 체크
	bool jumpCheck;		 //점프 상태 체크
	bool scaffold;		 //발판 체크
	bool getDamage;		 //데미지 입었을때 체크.
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
	float gravity;		//중력1
	float valGravity;	//중력2
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

//잔상효과용 구조체 
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

	//발판 검사용 카운트.
	int _scaffoldCount;

	//캐릭터 잔상효과용 CurrentFrameX, Y, FrameCounter
	int _currentX, _currentY;

	AfterImage _afterimg[6];

public:
	Alucard();
	~Alucard();

	virtual HRESULT init();
	virtual void update();
	virtual void release();
	virtual void render();

	//키입력
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
	//알카드의 잔상효과 처리
	void AlucardAfterImage();
	//알카드의 잔상효과 처리용 FrameImage 재생
	void AlucardFrameCounter();
	//알카드 마법 사용시 공격 렉트
	void AlucardMagicUse();
	//알카드 수치관련 연산
	void AlucardData();

	//Character State
	void Idle();		//대기 자세
	void StartMove();	//이동시작 자세
	void Moving();		//이동
	void Jump();		//점프모션
	void DoubleJump();	//이단 점프 모션
	void BackDash();	//백대쉬
	void Attack();		//공격
	void AttackAir();	//공중 공격
	void Falling();		//낙하
	void Ducking();		//숙이기, 숙인상태 방향 전환.
	void DuckingDirection();
	void DuckingAttack();
	void Hit();			//몬스터의 공격에 피격.
	void Skill();		//알카드의 커맨드 스킬 발동.

	//몬스터 매니저 링크
	void SetLink_MonsterManager(MonsterManager* manager) { _monster = manager; }
	//Map에서 알카드의 좌표 수정 X, Y
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

	//캐릭터 어택 벡터 Get
	CharacterAttack* GetCAttack() { return _attack; }	
};

