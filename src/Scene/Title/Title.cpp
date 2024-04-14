#include "DxLib.h"
#include "Title.h"
#include "../Scene.h"

void Title::DebugTitle()
{
	DrawFormatString(0, 50, GetColor(255,255,255), "スペースキーを押してください");
}

void Title::InitTitle()
{
	TitleHndl = LoadGraph("data/TitleImage/Title_Image.png");

	g_CurrentSceneID = SCENE_ID_LOOP_TITLE;
}

void Title::StepTitle()
{
	if (CheckHitKey(KEY_INPUT_SPACE))
	{
		g_CurrentSceneID = SCENE_ID_FIN_TITLE;
	}
}

void Title::FinTitle()
{
	g_CurrentSceneID = SCENE_ID_INIT_PLAY;

	DeleteGraph(TitleHndl);
}

void Title::DrawTitle()
{
	DrawGraph(0, 0, TitleHndl, true);
}
