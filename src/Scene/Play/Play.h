#pragma once
#include "../../Player/Player.h"
#include "../../Player/Bullet/Bullet.h"
#include "../../Enemy/Enemy.h"
#include "../../Collision/Collision.h"

const float SHOT_INTERVAL = 5.0f;			//弾の発射感覚


//プレイシーンクラス
class Play
{
private:
	Player player;
	Bullet bullet[256];
	Enemy enemy;

	float PlayerFramCnt;
	
	float Startp;
	
	//マウス関連(試しに)
	int MousePosX, MousePosY;	//マウスの座標

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

	//発射処理
	void BulletShot();

	//敵と弾の当たり判定
	void EnemyToBulletCollision();

	//敵とプレイヤーの当たり判定
	void EnemyToPlayer();

	//無敵フラグ解除処理
	void PlayerIsInv();
};
