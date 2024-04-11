//�E�B���h�E��\������v���O�����i�ЂȌ`�j

#include "DxLib.h"	//DX���C�u�����̃C���N���[�h
#include "Scene/Scene.h"
#include "Scene/Play/Play.h"
#include "Player/Player.h"
#include "Fps/Fps.h"

// define
#define	SCREEN_SIZE_X	640	// X�����̉�ʃT�C�Y���w��
#define	SCREEN_SIZE_Y	480	// Y�����̉�ʃT�C�Y���w��

//�V�[���N���X�錾
SCENE_ID g_CurrentSceneID = SCENE_ID_INIT_TITLE;

// Win32�A�v���P�[�V������ WinMain�֐� ����n�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//�E�B���h�E�̏�Ԃ�ݒ肷��
	ChangeWindowMode(true);

	//DX���C�u�����̏�����
	if (DxLib_Init() == -1) {
		return -1;
	}

	// ��ʃT�C�Y��ύX
	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 32);

	//�`�悷��X�N���[����ݒ肷��
	SetDrawScreen(DX_SCREEN_BACK);
	
	//-----------------------------------------
	//��ԍŏ��ɂP�񂾂���鏈���������ɏ���
	
	//Input�֐��̏�����
	InitInput();
	
	
	
	//�N���X�錾
	Play play;			//�v���C�V�[��

	//-----------------------------------------

	//�Q�[�����C�����[�v
	while (ProcessMessage() != -1)
	{
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)
		{
			//�G�X�P�[�v�L�[�������ꂽ��I��
			break;
		}

		//��ʂɕ\�����ꂽ���̂�������
		ClearDrawScreen();

		//�t���[�����[�g����
		FpsControll_Update();

		//���͐���X�e�b�v
		StepInput();

		//�}�E�X�J�[�\���̕\��
		SetMouseDispFlag(true);


		//�Q�[���̃V�[���ړ�
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
			
			play.Init();		//����������
			play.Load();		//�ǂݍ��ݏ���

			g_CurrentSceneID = SCENE_ID_LOOP_PLAY;
			break;
		case SCENE_ID_LOOP_PLAY:

			play.Step();		//�ʏ폈��
			play.Draw();		//�`�揈��

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

		// FPS����������
		InitFPS();

		//FPS�v�Z
		CalcFPS();

		// FPS�̒ʏ폈��
		StepFPS();

		//FPS�̕\��
		DrawFPS();

		//���݂̎��Ԃ�ݒ�
		SetNowTimeFps();

		// �O��̎��s������s�\�t���[�����`�F�b�N
		IsExecuteFPS();

		//�ҋ@
		FpsControll_Wait();		
	
		//���[�v�̏I����
		//�t���b�v�֐�
		ScreenFlip();

	}

	//-----------------------------------------
	//�Ō�ɂP�񂾂���鏈���������ɏ���
	

	//-----------------------------------------
	//DX���C�u�����̌㏈��
	DxLib_End();

	return 0;
}

