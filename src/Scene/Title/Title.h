#pragma once

class Title
{

protected :

	int TitleHndl;

public:

	void DebugTitle(); //タイトルデバッグ

	void InitTitle();  //タイトル初期化処理

	void StepTitle();  //タイトル通常処理

	void FinTitle();   //タイトル後処理

	void DrawTitle();  //描画処理
};
