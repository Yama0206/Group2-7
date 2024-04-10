#include "Play.h"

//初期化処理
void Play::Init()
{
	//プレイヤー関連
	player.Init();			
	player.InitValue();
}

//読み込み処理
void Play::Load()
{
	//プレイヤー関連
	player.Load();			
}

//通常処理
void Play::Step()
{
	//プレイヤー関連
	player.Step();
}

//描画処理
void Play::Draw()
{
	//プレイヤー関連
	player.Draw();			
}

//終了処理
void Play::Fin()
{

}