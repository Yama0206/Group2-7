#pragma once

class Clear
{

protected:

	int ClearHndl;

public:

	void DebugClear(); //タイトルデバッグ

	void InitClear();  //タイトル初期化処理

	void StepClear();  //タイトル通常処理

	void FinClear();   //タイトル後処理

	void DrawClear();  //描画処理
};
