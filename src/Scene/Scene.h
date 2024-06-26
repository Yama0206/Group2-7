#pragma once
#include "../Scene/Scene.h"

// define
#define	SCREEN_SIZE_X	800	// X方向の画面サイズを指定
#define	SCREEN_SIZE_Y	600	// Y方向の画面サイズを指定

enum SCENE_ID
{
	//タイトル関連
	SCENE_ID_INIT_TITLE = 100,
	SCENE_ID_LOOP_TITLE,
	SCENE_ID_FIN_TITLE,

	//プレイ関連
	SCENE_ID_INIT_PLAY = 200,
	SCENE_ID_LOOP_PLAY,
	SCENE_ID_FIN_PLAY,

	//ゲームクリア関連
	SCENE_ID_INIT_CLEAR = 300,
	SCENE_ID_LOOP_CLEAR,
	SCENE_ID_FIN_CLEAR,

	//ゲームオーバー関連
	SCENE_ID_INIT_GAMEOVER = 400,
	SCENE_ID_LOOP_GAMEOVER,
	SCENE_ID_FIN_GAMEOVER,

};

extern SCENE_ID g_CurrentSceneID;

