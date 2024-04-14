#include "Bullet.h"

//初期化
void Bullet::Init()
{
	
	//座標
	PosX = 0.0f;		//X座標
	PosY = 0.0f;		//Y座標

	//画像ハンドル
	ImageHandle = -1;

	//フラグ
	IsUse = false;		//弾を使っているかどうか
	
}

//初期値設定
void Bullet::DefaultValue()
{
	
	//座標
	PosX = 0.0f;		//X座標
	PosY = 0.0f;		//Y座標
	
}

//読み込み
void Bullet::Load()
{
	
		ImageHandle = LoadGraph(BULLET_PATH);
	
}

//通常処理
void Bullet::Step()
{
	
}

//描画処理
void Bullet::Draw()
{
	for (int i = 0; i < BULLET_MAX_NUM; i++)
	{
		if (IsUse) {
			DrawRotaGraph(PosX, PosY, 1.0f, 0.0f, ImageHandle, false, true);
		}
	}
		
	if (PosX > 640+32 || PosX < 0-32 || PosY>480+32 || PosY < 0-32)
	{
		IsUse = false;

		//画面外に出たら弾の発射位置に戻す
		PosX = 0.0f;
		PosY = 0.0f;
	}
}

//終了処理
void Bullet::Fin()
{

}

//弾の移動関数
void Bullet::Move(float x, float y)
{
	//X,Yベクトル
	VECTOR vBulletPos = { 0.0f, 0.0f, 0.0f };

	//二点間の距離
	float TwoPoint = 0.0f;

	

	//X,Yベクトルを計算
	vBulletPos.x = MousePos.x - x;
	vBulletPos.y = MousePos.y - y;

	//二点間の距離を取得
	TwoPoint = (vBulletPos.x * vBulletPos.x) + (vBulletPos.y * vBulletPos.y);

	//平方根を求める
	TwoPoint = sqrtf(TwoPoint);

	//↓このfor文を使うとなぜか素早さが上がる
	for (int i = 0; i < SPEED_NUM; i++)
	{
		//正規化した値を足す
		PosX += vBulletPos.x / TwoPoint;
		PosY += vBulletPos.y / TwoPoint;
	}
}

void Bullet::SetIsUse(bool flag)
{
	
		IsUse = flag;
	
}

void Bullet::SetMousePos(float posX, float posY)
{
	MousePos.x = posX;
	MousePos.y = posY;
}