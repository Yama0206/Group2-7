#pragma once

const char CLEAR_BGM[] = { "data/Sound/GameClearBGM1.m4a" };

class Clear
{

protected:

	int ClearHndl;
	int Clear_Bgm;

public:

	void DebugClear(); //�^�C�g���f�o�b�O

	void InitClear();  //�^�C�g������������

	void StepClear();  //�^�C�g���ʏ폈��

	void FinClear();   //�^�C�g���㏈��

	void DrawClear();  //�`�揈��
};
