#include "DxLib.h"
#include "Title.h"
#include "../Scene.h"
#include "../../Input/Input.h"

void Title::DebugTitle()
{
	DrawFormatString(0, 50, GetColor(255,255,255), "スペースキーを押してください");
}

void Title::InitTitle()
{
	TitleHndl = LoadGraph("data/TitleImage/Title_Image.png");

	Title_Bgm = LoadSoundMem(TITLE_BGM);

	PlaySoundMem(Title_Bgm, DX_PLAYTYPE_BACK);

	g_CurrentSceneID = SCENE_ID_LOOP_TITLE;
}

void Title::StepTitle()
{
	if (IsKeyPush(KEY_INPUT_SPACE))
	{
		g_CurrentSceneID = SCENE_ID_FIN_TITLE;
	}
}

void Title::FinTitle()
{
	g_CurrentSceneID = SCENE_ID_INIT_PLAY;

	DeleteGraph(TitleHndl);
	DeleteSoundMem(Title_Bgm);
}

void Title::DrawTitle()
{
	DrawGraph(0, 0, TitleHndl, true);
}
