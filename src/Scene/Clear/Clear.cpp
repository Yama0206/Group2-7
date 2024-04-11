#include "DxLib.h"
#include "Clear.h"
#include "../Scene.h"

void Clear::DebugClear()
{
	DrawFormatString(0, 50, GetColor(255, 255, 255), "スペースキーを押してください");
}

void Clear::InitClear()
{
	ClearHndl = LoadGraph("data/sensya.png");

	g_CurrentSceneID = SCENE_ID_LOOP_RESULT;
}

void Clear::StepClear()
{
	if (CheckHitKey(KEY_INPUT_SPACE))
	{
		g_CurrentSceneID = SCENE_ID_FIN_RESULT;
	}
}

void Clear::FinClear()
{
	g_CurrentSceneID = SCENE_ID_INIT_RESULT;

	DeleteGraph(ClearHndl);
}

void Clear::DrawClear()
{
	DrawGraph(0, 0, ClearHndl, true);
}
