#pragma once
#include "DxLib.h"

const char BULLET_PATH[] = { "" };			//弾画像パス
const int BULLET_MAX_NUM = 256;				//弾の最大数

class Bullet
{
private:
	float PosX, PosY;		//座標
	int ImageHandle;		//画像ハンドル
	bool IsUse;				//弾を使っているかどうか

	//マウス関連(試しに)
	int MousePosX, MousePosY;	//マウスの座標

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
	void Move(float posX, float posY);

	//弾の使用フラグの設定
	void SetIsUse(bool flag);
};
