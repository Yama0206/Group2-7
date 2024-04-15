#include "Play.h"

//初期化処理
void Play::Init()
{
	//プレイヤー関連
	player.Init();
	player.InitValue();

	PlayerFramCnt = 0.0f;

	MousePosX = 0.0f;		//マウスのX座標
	MousePosY = 0.0f;		//マウスのY座標

	//弾の初期化
	for (int i = 0; i < BULLET_MAX_NUM; i++)
	{
		bullet[i].Init();
	}

	//敵関連
	enemy.Init();
}

//読み込み処理
void Play::Load()
{
	player.Load();				//プレイヤー関連
	enemy.Load();				//敵関連
	//弾の数文for文を回す
	for (int i = 0; i < BULLET_MAX_NUM; i++)
	{
		bullet[i].Load();		//弾関連
	}
}

//通常処理
void Play::Step()
{
	//プレイヤー関連
	player.Step();

	//発射処理
	BulletShot();

	//当たり判定
	EnemyToBulletCollision();

	//敵とプレイヤーの当たり判定
	EnemyToPlayer();
	
	PlayerIsInv();

	//敵関連
	enemy.Step();
}

//描画処理
void Play::Draw()
{
	//プレイヤー関連
	player.Draw();	
	for (int i = 0; i < BULLET_MAX_NUM; i++) {			//弾の数文for文を回す
		if (bullet[i].GetIsUse()) {
			//弾関連
			bullet[i].Draw();
		}
	}
	
	DrawFormatString(32, 128, GetColor(255, 0, 0), "%d", player.GetHP());

	//敵関連
	enemy.Draw();
	//デバッグ
	DrawFormatString(32, 100, GetColor(255, 0, 0), "%f", PlayerFramCnt);
}

//終了処理
void Play::Fin()
{

}

//発射間隔
//void Play::ShotInterval()
//{
//	//発射するまでの時間
//	if (PlayerFramCnt > SHOT_INTERVAL)
//	{
//		PlayerFramCnt = SHOT_INTERVAL;
//	}
//	//発射間隔と発射フラグがオンになったら発射
//	if (player.IsShot() && PlayerFramCnt == SHOT_INTERVAL)
//	{
//		//弾の情報処理
//		for (int BulletIndex = 0; BulletIndex < BULLET_MAX_NUM; BulletIndex++)
//		{
//
//		}
//	}
//}

//発射処理
void Play::BulletShot()
{
	//弾の数分for分を回す
	for (int bulletIndex = 0; bulletIndex < BULLET_MAX_NUM; bulletIndex++)
	{

		//プレイヤーが弾を発射したかどうか
		if (player.IsShot())
		{
			if (!bullet[bulletIndex].GetIsUse()) {
				//マウスの座標を取得
				GetMousePoint(&MousePosX, &MousePosY);

				//発射したら弾の使用フラグをオンにする
				bullet[bulletIndex].SetIsUse(true);

				//弾の発射位置をプレイヤーの座標に設定
				bullet[bulletIndex].SetPos(player.GetPosX(), player.GetPosY());
			}
		}
		
		//弾が使われているかどうか
		if (bullet[bulletIndex].GetIsUse())
		{

			//マウスの座標を保存
			bullet[bulletIndex].SetMousePos((float)MousePosX, (float)MousePosY);

			//使われていたら弾を移動させる
			bullet[bulletIndex].Move(player.GetPosX(), player.GetPosY());
		}

		
	}
}

//敵と弾の当たり判定
void Play::EnemyToBulletCollision()
{
	//敵の数分for文を回す
	for (int enemyIndex = 0; enemyIndex < ENEMY_MAX_NUM; enemyIndex++) {
		//弾の数分をfor文を回す
		for (int bulletIndex = 0; bulletIndex < BULLET_MAX_NUM; bulletIndex++) {
			//当たった時
			if (IsHitRect(bullet[bulletIndex].GetPosX(), bullet[bulletIndex].GetPosY(), BULLET_SIZE, BULLET_SIZE,
				enemy.EnemyPosX[enemyIndex], enemy.EnemyPosY[enemyIndex], ENEMY_SIZE, ENEMY_SIZE))
			{
				enemy.IsAllive[enemyIndex] = false;
			}
		}
	}
}

//敵とプレイヤーの当たり判定
void Play::EnemyToPlayer()
{
	//敵の数分for文を回す
	for (int enemyIndex = 0; enemyIndex < ENEMY_MAX_NUM; enemyIndex++)
	{
		if (!player.GetIsInv()) {
			//敵とプレイヤーが当たった時
			if (IsHitRect(player.GetPosX(), player.GetPosY(), PLAYER_SIZE, PLAYER_SIZE,
				enemy.EnemyPosX[enemyIndex], enemy.EnemyPosY[enemyIndex], ENEMY_SIZE, ENEMY_SIZE))
			{
				player.SetIsInv(true);
				//プレイヤーのHPを減らす
				player.SetHP(-1);

				//HPがゼロになった時
				if (player.GetHP() == 0)
				{
					player.SetIsAllive(false);
				}
			}
		}
	}
}

void Play::PlayerIsInv()
{
	if (player.GetIsInv())
	{
		//プレイヤーのフレームをカウント
		player.FramCnt(&PlayerFramCnt);

		if (PlayerFramCnt == 120)
		{
			player.SetIsInv(false);

			PlayerFramCnt = 0;
		}
	}
}