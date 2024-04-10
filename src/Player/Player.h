#pragma once
#include "Dxlib.h"
#include "../Scene/Scene.h"
#include "../Input/Input.h"

const char PLAYER_PATH[] = { "" };

//プレイヤークラス
class Player
{
private:
	float PosX, PosY;
	int ImageHandle;

public:
	//初期化
	void Init();

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
};