#pragma once
#include "DxLib.h"

const char BULLET_PATH[] = { "" };

class Bullet
{
private:
	float PosX, PosY;		//座標
	int ImageHandle;		//画像ハンドル

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

	void Move(float posX, float posY);

};
