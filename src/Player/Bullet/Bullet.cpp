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

}

//終了処理
void Bullet::Fin()
{

}

//弾の移動関数
void Bullet::Move(float posX, float posY)
{
	//マウスの座標を取得
	GetMousePoint(&MousePosX, &MousePosY);


}

void Bullet::SetIsUse(bool flag)
{
	IsUse = flag;
}
