#include "DxLib.h"
#include "Clear.h"
#include "../Scene.h"
#include "../../Input/Input.h"

void Clear::DebugClear()
{
	DrawFormatString(0, 50, GetColor(255, 255, 255), "スペースキーを押してください");
}

void Clear::InitClear()
{
	ClearHndl = LoadGraph("data/clearImage/gameclearimage.png");
	Clear_Bgm = LoadSoundMem(CLEAR_BGM);

	PlaySoundMem(Clear_Bgm, DX_PLAYTYPE_LOOP);

	g_CurrentSceneID = SCENE_ID_LOOP_CLEAR;
}

void Clear::StepClear()
{
	if (IsKeyPush(KEY_INPUT_SPACE))
	{
		g_CurrentSceneID = SCENE_ID_FIN_CLEAR;
	}
}

void Clear::FinClear()
{
	g_CurrentSceneID = SCENE_ID_INIT_TITLE;

	DeleteSoundMem(Clear_Bgm);
	DeleteGraph(ClearHndl);
}

void Clear::DrawClear()
{
	DrawGraph(0, 0, ClearHndl, true);
}
