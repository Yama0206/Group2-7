#pragma once
#include "DxLib.h"
#include "math.h"

const char BULLET_PATH[] = { "data/Player/BulletImage.png" };			//弾画像パス
const int BULLET_MAX_NUM = 256;				//弾の最大数
const float BULLET_SIZE = 16.0f;					//弾の大きさ(縦横同じ)

//スピードの値
const int SPEED_NUM = 30;

class Bullet
{
private:
	float PosX, PosY;		//座標
	int ImageHandle;		//画像ハンドル
	bool IsUse;				//弾を使っているかどうか

	//マウスの座標保存用変数
	VECTOR MousePos = { 0.0f, 0.0f, 0.0f };

public:
	//初期化
	void Init();

	//初期値設定
	void DefaultValue();

	//読み込み
	void Load();

	//通常処理
	void Step();

	//描画
	void Draw();

	//終了
	void Fin();

	//弾の移動関数
	void Move(float x, float y);

	//弾の座標を設定
	void  SetPos(float x, float y);

	//弾の座標の取得
	float GetPosX() { return PosX; }
	float GetPosY() { return PosY; }

	//弾の使用フラグの設定
	void SetIsUse(bool flag);

	//弾を使っているかどうかフラグを取得
	bool GetIsUse() { return IsUse; }

	void SetMousePos(float posX, float posY);
};

//extern Bullet PosX;