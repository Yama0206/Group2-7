#include"Player.h"

//初期化処理
void Player::Init()
{
	//座標
	PosX = 0;
	PosY = 0;

	//画像ハンドル
	ImageHandle = -1;
}

//読み込み処理
void Player::Load()
{
	ImageHandle = LoadGraph(PLAYER_PATH);
}

//通常処理
void Player::Step()
{
	//移動処理
	Move();
}

//描画処理
void Player::Draw()
{
	//デバッグ用
	DrawFormatString(32, 32, GetColor(255, 0, 0), "%d, %d", PosX, PosY);
}

//終了処理
void Player::Fin()
{
	
}

//プレイヤーの移動処理
void Player::Move()
{
	//上方向
	if(IsKeyKeep(KEY_INPUT_W))
	{
		PosY++;
	}
	//下方向
	if (IsKeyKeep(KEY_INPUT_S))
	{
		PosY--;
	}
	//右方向
	if (IsKeyKeep(KEY_INPUT_D))
	{
		PosX++;
	}
	//左方向
	if (IsKeyKeep(KEY_INPUT_A))
	{
		PosX--;
	}
}
