#include "Enemy.h"

void Enemy::Init()
{

	for (int i = 0; i < ENEMY_MAX_NUM; i++)
	{
		//�����t���O
		EnemyIsActive[i] = true;

		//�ړ���
		EnemyMoveNumX[i] = 0;
		EnemyMoveNumY[i] = 0;

		IsAllive[i] = true;
	}

	PosChangeCnt[1] = 0;

	//���W�����ʒu
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

	
}

void Enemy::Load()
{
	for (int i = 0; i < ENEMY_MAX_NUM; i++)
	{
		//�G�摜�̓ǂݍ���
		EnemyImageHandle[i] = LoadGraph(ENEMY_PATH);
	}
}

void Enemy::Step()
{
	//�z��0�Ԗڂ̓G�̍s��
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
	
	//�z��P�Ԗڂ̓G�̍s��
	PosChangeCnt[1]++;
	if (PosChangeCnt[1] == 80)
	{
		EnemyPosX[1] = GetRand(640 - 16);
		EnemyPosY[1] = GetRand(480 - 16);

		PosChangeCnt[1] = 0;
	}
	////////////

	//�z��2�Ԗڂ̓G�̍s��
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

	//�z��3�Ԗڂ̓G�̍s��
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

	//�z��4�Ԗڂ̓G
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

		/*if (!IsAllive[i])
		{
			respawnCnt++;
			if (respawnCnt >= 100)
			{
				IsAllive[i] = true;
				respawnCnt = 0;
			}
			int respawnCnt;
		}*/
	}
}
