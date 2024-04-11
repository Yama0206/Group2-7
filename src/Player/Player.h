#pragma once
#include "Dxlib.h"
#include "../Scene/Scene.h"
#include "../Input/Input.h"

const char PLAYER_PATH[] = { "" };

//プレイヤークラス
class Player
{
private:
	float PosX, PosY;			//座標
	float Speed;				//速さ
	int ImageHandle;			//画像ハンドル

public:
	//初期化
	void Init();

	//初期値設定
	void InitValue();

	//読み込み
	void Load();

	//通常処理
	void Step();

	//描画処理
	void Draw();

	//終了処理
	void Fin();

	//プレイヤーの移動
	void Move();

	//プレイヤーの座標取得
	void GetPlayerPos(float* PosX, float* PosY);

	//プレイヤーが球を打ったかどうか
	bool IsShot();
};