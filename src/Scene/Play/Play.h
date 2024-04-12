#pragma once
#include "../../Player/Player.h"
#include "../../Player/Bullet/Bullet.h"
#include "../../Enemy/Enemy.h"

const float SHOT_INTERVAL = 5.0f;			//弾の発射感覚


//プレイシーンクラス
class Play
{
private:
	Player player;
	Bullet bullet[256];
	Enemy enemy;

	float PlayerFramCnt;

public:
	//初期化
	void Init();
	
	//読み込み
	void Load();

	//通常処理
	void Step();

	//描画処理
	void Draw();

	//終了処理
	void Fin();

	//あとで使うかも
	/*void ShotInterval();*/
};
