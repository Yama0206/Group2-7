#include "Enemy.h"

void Enemy::Init()
{
	
	for (int i = 0; i < ENEMY_MAX_NUM; i++)
	{
		//座標
		EnemyPosX[i] = GetRand(640);
		EnemyPosY[i] = GetRand(480);
		//生存フラグ
		EnemyIsActive[i] = true;
	}


}

void Enemy::Load()
{
	for (int i = 0; i < ENEMY_MAX_NUM; i++)
	{
		//敵画像の読み込み
		EnemyImageHandle[i] = LoadGraph(ENEMY_PATH);
	}
}

void Enemy::Step()
{




}

void Enemy::Draw()
{
	for (int i = 0; i < ENEMY_MAX_NUM; i++)
	{
		DrawRotaGraph(EnemyPosX[i], EnemyPosY[i], 1.0f, 0.0f, EnemyImageHandle[i], true);
	}
}
