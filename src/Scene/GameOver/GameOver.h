#pragma once

const char GAMEOVER_BGM[] = { "data/Sound/zannense.mp3" };

class GameOver
{

protected:

	int GameOverHndl;

	int GameOverBgm;

public:

	void DebugGameOver(); //タイトルデバッグ

	void InitGameOver();  //タイトル初期化処理

	void StepGameOver();  //タイトル通常処理

	void FinGameOver();   //タイトル後処理

	void DrawGameOver();  //描画処理
};
