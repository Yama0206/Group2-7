#pragma once
#include "Dxlib.h"
#include "../Scene/Scene.h"
#include "../Input/Input.h"

const char PLAYER_PATH[] = { "data/Player/PlayerImage.png" };
const float PLAYER_SIZE = 32.0f;

//プレイヤークラス
class Player
{
private:
	float PosX, PosY;			//座標
	float Speed;				//速さ
	int ImageHandle;			//画像ハンドル
	int HP;						//体力

	bool IsInv;					//無敵フラグ
	bool IsStartInv;			//スタートしてからの無敵フラグ
	bool IsAllive;				//生きているかどうか
	bool IsDraw;
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
	float GetPosX() { return PosX; }		//X座標
	float GetPosY() { return PosY; }		//Y座標

	//生きているかどうかの設定
	void SetIsAllive(bool Isflag) { IsAllive = Isflag; }
	//生きているかどうかの取得
	bool GetIsAllive() { return IsAllive; }

	//描画するかどうか
	void SetIsDraw(bool Isflag) { IsDraw = Isflag; }
	//描画するかどうかの取得
	bool GetIsDraw() { return IsDraw; }

	//無敵フラグのセット
	void SetIsInv(bool IsFlag) { IsInv = IsFlag; }
	//無敵フラグを取得
	bool GetIsInv() { return IsInv; }

	//無敵フラグのセット
	void SetIsStartInv(bool IsFlag) { IsStartInv = IsFlag; }
	//無敵フラグを取得
	bool GetIsStartInv() { return IsStartInv; }

	//HPの値の変更
	void SetHP(int hp) { HP += hp; }
	
	//HP取得
	int GetHP() { return HP; }

	//プレイヤーの座標取得
	void FramCnt(float* framcnt);

	//プレイヤーが球を打ったかどうか
	bool IsShot();
};
