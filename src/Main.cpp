//ウィンドウを表示するプログラム（ひな形）

#include "DxLib.h"	//DXライブラリのインクルード
#include "Scene/Scene.h"
#include "Scene/Play/Play.h"
#include "Player/Player.h"
#include "Fps/Fps.h"

// define
#define	SCREEN_SIZE_X	640	// X方向の画面サイズを指定
#define	SCREEN_SIZE_Y	480	// Y方向の画面サイズを指定

// Win32アプリケーションは WinMain関数 から始まる
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//ウィンドウの状態を設定する
	ChangeWindowMode(true);

	//DXライブラリの初期化
	if (DxLib_Init() == -1) {
		return -1;
	}

	// 画面サイズを変更
	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 32);

	//描画するスクリーンを設定する
	SetDrawScreen(DX_SCREEN_BACK);
	
	//-----------------------------------------
	//一番最初に１回だけやる処理をここに書く
	
	//Input関数の初期化
	InitInput();
	
	//シーンクラス宣言
	SCENE_ID g_CurrentSceneID = SCENE_ID_INIT_TITLE;
	
	//クラス宣言
	Play play;			//プレイシーン

	//-----------------------------------------

	//ゲームメインループ
	while (ProcessMessage() != -1)
	{
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)
		{
			//エスケープキーが押されたら終了
			break;
		}

		//画面に表示されたものを初期化
		ClearDrawScreen();

		//-----------------------------------------
		//ここからゲームの本体を書くことになる
		//-----------------------------------------
		switch (g_CurrentSceneID)
		{
		case SCENE_ID_INIT_TITLE:

			g_CurrentSceneID = SCENE_ID_INIT_PLAY;
			break;
		case SCENE_ID_LOOP_TITLE:

			break;
		case SCENE_ID_FIN_TITLE:

			break;
		case SCENE_ID_INIT_PLAY:
			
			play.Init();		//初期化処理
			play.Load();		//読み込み処理

			g_CurrentSceneID = SCENE_ID_LOOP_PLAY;
			break;
		case SCENE_ID_LOOP_PLAY:

			play.Step();		//通常処理
			play.Draw();		//描画処理

			break;
		case SCENE_ID_FIN_PLAY:

			break;
		case SCENE_ID_INIT_RESULT:

			break;
		case SCENE_ID_LOOP_RESULT:

			break;
		case SCENE_ID_FIN_RESULT:

			break;
		}

		// FPS初期化処理
		void InitFPS();

		//FPS計算
		void CalcFPS();

		//FPS表示（デバッグ用）
		void DrawFPS();

		//現在の時間を設定
		void SetNowTimeFps();

		// 前回の実行から実行可能フレームかチェック
		bool IsExecuteFPS();

		// FPSの通常処理
		void StepFPS();

		//フレーレートの制御
		void FpsControll_Initialize();

		//FPS制御
		bool FpsControll_Update();
		//-----------------------------------------
		//ループの終わりに
		//フリップ関数
		ScreenFlip();

	}

	//-----------------------------------------
	//最後に１回だけやる処理をここに書く
	

	//-----------------------------------------
	//DXライブラリの後処理
	DxLib_End();

	return 0;
}

