#include"Player.h"

//初期化処理
void Player::Init()
{
	//座標
	PosX = 0.0f;
	PosY = 0.0f;

	Speed = 0.0f;

	IsAllive = false;

	//画像ハンドル
	ImageHandle = -1;
}

//初期値設定
void Player::InitValue()
{
	//座標設定
	PosX = 0.0f;
	PosY = 0.0f;

	//速さ
	Speed = 1.0f;
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
	if (IsShot()) {
		//デバッグ用
		DrawFormatString(32, 32, GetColor(255, 0, 0), "押された");
	}

	DrawRotaGraph(PosX, PosY, 1.0f, 0.0f, ImageHandle, false, true);
}

//終了処理
void Player::Fin()
{
	
}

//プレイヤーの操作関連
//プレイヤーの移動処理
void Player::Move()
{
	//上方向
	if(IsKeyKeep(KEY_INPUT_W))
	{
		PosY -= Speed;
	}
	//下方向
	if (IsKeyKeep(KEY_INPUT_S))
	{
		PosY += Speed;
	}
	//右方向
	if (IsKeyKeep(KEY_INPUT_D))
	{
		PosX += Speed;
	}
	//左方向
	if (IsKeyKeep(KEY_INPUT_A))
	{
		PosX -= Speed;
	}


}


bool Player::IsShot()
{
	if (GetMouseInput() && MOUSE_INPUT_LEFT != 0)
	{
		return true;
	}

	return false;
}

//プレイヤーの座標
void Player::FramCnt(float* framcnt)
{
	*framcnt+=1;
}
