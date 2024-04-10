#include "Play.h"

//初期化処理
void Play::Init()
{
	player.Init();			//プレイヤー関連			
}

//読み込み処理
void Play::Load()
{
	player.Load();			//プレイヤー関連
}

//通常処理
void Play::Step()
{
	player.Step();			//プレイヤー関連
}

//描画処理
void Play::Draw()
{
	player.Draw();			//プレイヤー関連
}

//終了処理
void Play::Fin()
{

}