#pragma once
#include "DxLib.h"

#define ENEMY_PATH "Data/Enemy/Waruo.png"
#define ENEMY_MAX_NUM (5)
#define ENEMY_RADIUS (16)
const float ENEMY_SIZE = 32.0f;

class Enemy
{
private:


	//�摜�n���h��
	int EnemyImageHandle[ENEMY_MAX_NUM];
	//�����t���O
	bool EnemyIsActive[ENEMY_MAX_NUM];

	int EnemyMoveNumX[ENEMY_MAX_NUM],EnemyMoveNumY[ENEMY_MAX_NUM];

	//���W���ύX�����܂ł̃J�E���g
	int PosChangeCnt[ENEMY_MAX_NUM];

public:
	//���W
	float EnemyPosX[ENEMY_MAX_NUM], EnemyPosY[ENEMY_MAX_NUM];

	bool IsAllive[ENEMY_MAX_NUM];
	
	void Init();
	void Load();
	void Step();
	void Draw();
};

