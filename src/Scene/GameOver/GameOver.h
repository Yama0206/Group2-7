#pragma once

const char GAMEOVER_BGM[] = { "data/Sound/zannense.mp3" };

class GameOver
{

protected:

	int GameOverHndl;

	int GameOverBgm;

public:

	void DebugGameOver(); //�^�C�g���f�o�b�O

	void InitGameOver();  //�^�C�g������������

	void StepGameOver();  //�^�C�g���ʏ폈��

	void FinGameOver();   //�^�C�g���㏈��

	void DrawGameOver();  //�`�揈��
};
