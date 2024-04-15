#include "DxLib.h"
#include "GameOver.h"
#include "../Scene.h"

void GameOver::DebugGameOver()
{
	DrawFormatString(0, 50, GetColor(255, 255, 255), "ゲームオーバーです");
}

void GameOver::InitGameOver()
{

	GameOverHndl = LoadGraph("data/gameoverImage/gameoverimage.png");
	GameOverBgm = LoadSoundMem(GAMEOVER_BGM);
	
	//ゲームオーバーシーンのBGM
	PlaySoundMem(GameOverBgm, DX_PLAYTYPE_BACK);


	g_CurrentSceneID = SCENE_ID_LOOP_GAMEOVER;
}

void GameOver::StepGameOver()
{

	if (CheckHitKey(KEY_INPUT_SPACE))
	{
		g_CurrentSceneID = SCENE_ID_FIN_GAMEOVER;
	}
}

void GameOver::FinGameOver()
{
	g_CurrentSceneID = SCENE_ID_INIT_TITLE;

	DeleteSoundMem(GameOverBgm);
	DeleteGraph(GameOverHndl);
}

void GameOver::DrawGameOver()
{
	DrawGraph(0, 0, GameOverHndl, true);
}
