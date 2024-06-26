#pragma once
#include "DxLib.h"

#define ENEMY_PATH "Data/Enemy/Waruo.png"
#define ENEMY_MAX_NUM (5)
#define ENEMY_RADIUS (16)
const float ENEMY_SIZE = 32.0f;

class Enemy
{
private:
	//画像ハンドル
	int EnemyImageHandle[ENEMY_MAX_NUM];
	//生存フラグ
	bool EnemyIsActive[ENEMY_MAX_NUM];

	int EnemyMoveNumX[ENEMY_MAX_NUM],EnemyMoveNumY[ENEMY_MAX_NUM];

	//座標が変更されるまでのカウント
	int PosChangeCnt[ENEMY_MAX_NUM];

	int respawnCnt;
public:
	//座標
	float EnemyPosX[ENEMY_MAX_NUM], EnemyPosY[ENEMY_MAX_NUM];

	bool IsAllive[ENEMY_MAX_NUM];
	
	void Init();
	void Load();
	void Step();
	void Draw();

	//生きているかどうかのフラグ設定
	void SetIsAllive(bool Isflag, int num);
	//生きているかどうかのフラグを取得
	bool GetIsAllive(int num) { return IsAllive[num]; }

	//リスポーンカウント
	void AddRespawnCnt() { respawnCnt++; }
	//リスポーンカウントの設定
	void SetRespawnCnt(int num) { respawnCnt = num; }
	//リスポーンカウント取得
	int  GetRespawnCnt() { return respawnCnt; }
};

