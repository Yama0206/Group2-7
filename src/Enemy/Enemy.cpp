#include "Enemy.h"

void Enemy::Init()
{

	for (int i = 0; i < ENEMY_MAX_NUM; i++)
	{
		//生存フラグ
		EnemyIsActive[i] = true;

		//移動量
		EnemyMoveNumX[i] = 0;
		EnemyMoveNumY[i] = 0;

		IsAllive[i] = true;
	}

	PosChangeCnt[1] = 0;

	//座標初期位置
	EnemyPosX[0] = 16;
	EnemyPosY[0] = 16;

	EnemyPosX[1] = GetRand(640 - 16);
	EnemyPosY[1] = GetRand(480 - 16);

	/*EnemyPosX[2] = 640 / 2;
	EnemyPosY[2] = 16;*/

	EnemyPosX[2] = GetRand(640 - 16);
	EnemyPosY[2] = 16;

	EnemyPosX[3] = GetRand(640 - 16);
	EnemyPosY[3] = 16;

	EnemyPosX[4] = 640 - 16;
	EnemyPosY[4] = 480 - 16;

	//リスポーンカウント
	respawnCnt = 0;
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
	//配列0番目の敵の行動
	if (EnemyPosY[0] <= 16)
	{
		EnemyMoveNumX[0] = 5;
		EnemyMoveNumY[0] = 0;
	}
	if (EnemyPosX[0] >= 640 - 16)
	{
		EnemyMoveNumX[0] = 0;
		EnemyMoveNumY[0] = 5;
	}
	if (EnemyPosY[0] >= 480 - 16)
	{
		EnemyMoveNumX[0] =- 5;
		EnemyMoveNumY[0] =0;
	}
	if (EnemyPosX[0] <= 16)
	{
		EnemyMoveNumX[0] =0 ;
		EnemyMoveNumY[0] =-5;

		if (EnemyPosY[0] <= 16)
		{
			EnemyMoveNumX[0] = 5;
			EnemyMoveNumY[0] = 0;
		}
	}
	////////////
	
	//配列１番目の敵の行動
	PosChangeCnt[1]++;
	if (PosChangeCnt[1] == 80)
	{
		EnemyPosX[1] = GetRand(640 - 16);
		EnemyPosY[1] = GetRand(480 - 16);

		PosChangeCnt[1] = 0;
	}
	////////////

	//配列2番目の敵の行動
	if (EnemyPosY[2] <= 16)
	{
		/*EnemyMoveNumX[2] = 6;
		EnemyMoveNumY[2] = 4;*/

		EnemyMoveNumX[2] = GetRand(10);
		EnemyMoveNumY[2] = GetRand(10);
	}
	if (EnemyPosX[2] >= 640 - 16)
	{
		/*EnemyMoveNumX[2] = -4;
		EnemyMoveNumY[2] = 6;*/

		EnemyMoveNumX[2] = GetRand(-10);
		EnemyMoveNumY[2] = GetRand(10);
	}
	if (EnemyPosY[2] >= 480 - 16)
	{
		/*EnemyMoveNumX[2] = -6;
		EnemyMoveNumY[2] = -4;*/

		EnemyMoveNumX[2] = GetRand(-10);
		EnemyMoveNumY[2] = GetRand(-10);
	}
	if (EnemyPosX[2] <= 16)
	{
		/*EnemyMoveNumX[2] = 6;
		EnemyMoveNumY[2] = -4;*/

		EnemyMoveNumX[2] = GetRand(10);
		EnemyMoveNumY[2] = GetRand(-10);
	}
	////////////

	//配列3番目の敵の行動
	if (EnemyPosY[3] <= 16)
	{
		/*EnemyMoveNumX[2] = 6;
		EnemyMoveNumY[2] = 4;*/

		EnemyMoveNumX[3] = GetRand(-10);
		EnemyMoveNumY[3] = GetRand(10);
	}
	if (EnemyPosX[3] <= 16)
	{
		/*EnemyMoveNumX[2] = 6;
		EnemyMoveNumY[2] = -4;*/

		EnemyMoveNumX[3] = GetRand(10);
		EnemyMoveNumY[3] = GetRand(10);
	}
	if (EnemyPosY[3] >= 480 - 16)
	{
		/*EnemyMoveNumX[2] = -6;
		EnemyMoveNumY[2] = -4;*/

		EnemyMoveNumX[3] = GetRand(10);
		EnemyMoveNumY[3] = GetRand(-10);
	}
	if (EnemyPosX[3] >= 640 - 16)
	{
		/*EnemyMoveNumX[2] = -4;
		EnemyMoveNumY[2] = 6;*/

		EnemyMoveNumX[3] = GetRand(-10);
		EnemyMoveNumY[3] = GetRand(-10);
	}
	////////////

	//配列4番目の敵
	if (EnemyPosY[4] <= 480-16)
	{
		EnemyMoveNumX[4] = -5;
		EnemyMoveNumY[4] = 0;
	}
	if (EnemyPosX[4] <= 16)
	{
		EnemyMoveNumX[4] = 0;
		EnemyMoveNumY[4] = -5;
	}
	if (EnemyPosY[4] <= 16)
	{
		EnemyMoveNumX[4] = 5;
		EnemyMoveNumY[4] = 0;
	}
	if (EnemyPosX[4] >= 640 - 16)
	{
		EnemyMoveNumX[4] = 0;
		EnemyMoveNumY[4] = 5;

		if (EnemyPosY[4] >= 480 - 16)
		{
			EnemyMoveNumX[4] = -5;
			EnemyMoveNumY[4] = 0;
		}
	}
	/////////////

}

void Enemy::Draw()
{
	for (int i = 0; i < ENEMY_MAX_NUM; i++)
	{
		if (IsAllive[i]) {
			DrawRotaGraph(EnemyPosX[i] += EnemyMoveNumX[i], EnemyPosY[i] += EnemyMoveNumY[i], 1.0f, 0.0f, EnemyImageHandle[i], true);
		}
	}
}

void Enemy::SetIsAllive(bool IsFlag, int num)
{
	IsAllive[num] = IsFlag;
}
