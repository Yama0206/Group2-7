#include "Play.h"

//初期化処理
void Play::Init()
{
	//プレイヤー関連
	player.Init();			
	player.InitValue();

	PlayerFramCnt = 0.0f;

}

//読み込み処理
void Play::Load()
{
	//プレイヤー関連
	player.Load();			
}

//通常処理
void Play::Step()
{
	//プレイヤー関連
	player.Step();
	//プレイヤーのフレームをカウント
	player.FramCnt(&PlayerFramCnt);
}

//描画処理
void Play::Draw()
{
	//プレイヤー関連
	player.Draw();	

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