#pragma once

const char CLEAR_BGM[] = { "data/Sound/GameClearBGM1.m4a" };

class Clear
{

protected:

	int ClearHndl;
	int Clear_Bgm;

public:

	void DebugClear(); //タイトルデバッグ

	void InitClear();  //タイトル初期化処理

	void StepClear();  //タイトル通常処理

	void FinClear();   //タイトル後処理

	void DrawClear();  //描画処理
};
