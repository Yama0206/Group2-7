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
	//プレイヤーのフレームをカウント
	player.FramCnt(&PlayerFramCnt);

	//発射処理
	BulletShot();

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