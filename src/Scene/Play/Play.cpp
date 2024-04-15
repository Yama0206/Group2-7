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

    //背景読み込み
	PlayImageHandle = LoadGraph("data/PlayImage/BackGround.png");

	PlayFinFreamCnt = 0;

	Bullet_SE = -1;
	Bgm = -1;

	//制限時間
	PlayFinCnt = 30;
	PlayFinFreamCntNum = 0;
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

	//発射音の読み込み
	Bullet_SE = LoadSoundMem(SHOT_SE);
	Bgm = LoadSoundMem(BGM);

	PlaySoundMem(Bgm, DX_PLAYTYPE_LOOP);

}

//通常処理
void Play::Step()
{
	PlayFinFreamCnt++;

	//プレイヤー関連
	player.Step();

	//発射処理
	BulletShot();

	//当たり判定
	EnemyToBulletCollision();

	//敵とプレイヤーの当たり判定
	EnemyToPlayer();
	
	//無敵処理
	PlayerIsInv();

	//敵のリスポーン処理
	RespawnEnemy();

	//敵関連
	enemy.Step();

	//制限時間をカウント
	PlayFinFreamCntNum++;
	if (PlayFinFreamCntNum >=60)
	{
		PlayFinCnt -= 1;
		PlayFinFreamCntNum = 0;
	}
}

//描画処理
void Play::Draw()
{
	//背景描画
	DrawRotaGraph(320, 240, 1.0f, 0.0f, PlayImageHandle, true);

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

	//制限時間描画
	DrawFormatString(0, 0, GetColor(255, 0, 0), "残り時間:%d", PlayFinCnt);
}

//終了処理
void Play::Fin()
{

}


//発射処理
void Play::BulletShot()
{
	//弾の数分for分を回す
	for (int bulletIndex = 0; bulletIndex < BULLET_MAX_NUM; bulletIndex++)
	{

		//プレイヤーが弾を発射したかどうか
		if (player.IsShot())
		{
			//クリックしたら無敵を解除
			player.SetIsStartInv(false);

			if (!bullet[bulletIndex].GetIsUse()) {
				//マウスの座標を取得
				GetMousePoint(&MousePosX, &MousePosY);

				PlaySoundMem(Bullet_SE, DX_PLAYTYPE_BACK);

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
			if (enemy.GetIsAllive(enemyIndex)) {
				//当たった時
				if (IsHitRect(bullet[bulletIndex].GetPosX(), bullet[bulletIndex].GetPosY(), BULLET_SIZE, BULLET_SIZE,
					enemy.EnemyPosX[enemyIndex], enemy.EnemyPosY[enemyIndex], ENEMY_SIZE, ENEMY_SIZE))
				{
					enemy.IsAllive[enemyIndex] = false;
				}
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
		if (enemy.GetIsAllive(enemyIndex)) {
			if (!player.GetIsInv() && !player.GetIsStartInv()) {
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

						Fin();
					}
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

void Play::RespawnEnemy()
{
	for (int i = 0; i < ENEMY_MAX_NUM; i++)
	{
		if (enemy.GetIsAllive(i) == false)
		{
			//リスポーンカウントを加算
			enemy.AddRespawnCnt();

			//カウントが240になったらリスポーン
			if (enemy.GetRespawnCnt() == 120)
			{
				enemy.SetIsAllive(true, i);

				enemy.SetRespawnCnt(0);
			}
		}
	}
}