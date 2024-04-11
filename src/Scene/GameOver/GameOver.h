#pragma once

class GameOver
{

protected:

	int GameOverHndl;

public:

	void DebugGameOver(); //タイトルデバッグ

	void InitGameOver();  //タイトル初期化処理

	void StepGameOver();  //タイトル通常処理

	void FinGameOver();   //タイトル後処理

	void DrawGameOver();  //描画処理
};
