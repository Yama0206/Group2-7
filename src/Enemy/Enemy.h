#pragma once
#include "DxLib.h"

#define ENEMY_PATH "Data/Enemy/Waruo.png"
#define ENEMY_MAX_NUM (5)

class Enemy
{
private:
	//座標
	float EnemyPosX[ENEMY_MAX_NUM], EnemyPosY[ENEMY_MAX_NUM];
	//画像ハンドル
	int EnemyImageHandle[ENEMY_MAX_NUM];
	//生存フラグ
	bool EnemyIsActive[ENEMY_MAX_NUM];

public:
	
	void Init();
	void Load();
	void Step();
	void Draw();

};

