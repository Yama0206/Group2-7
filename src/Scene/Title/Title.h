#pragma once

const char TITLE_BGM[] = { "data/Sound/HipHop_01.mp3" };

class Title
{

protected :

	int TitleHndl;
	int Title_Bgm;

public:

	void DebugTitle(); //�^�C�g���f�o�b�O

	void InitTitle();  //�^�C�g������������

	void StepTitle();  //�^�C�g���ʏ폈��

	void FinTitle();   //�^�C�g���㏈��

	void DrawTitle();  //�`�揈��
};
