#pragma once

const char TITLE_BGM[] = { "data/Sound/HipHop_01.mp3" };

class Title
{

protected :

	int TitleHndl;
	int Title_Bgm;

public:

	void DebugTitle(); //タイトルデバッグ

	void InitTitle();  //タイトル初期化処理

	void StepTitle();  //タイトル通常処理

	void FinTitle();   //タイトル後処理

	void DrawTitle();  //描画処理
};
