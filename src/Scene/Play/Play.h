#pragma once
#include "../../Player/Player.h"

//�v���C�V�[���N���X
class Play
{
private:
	Player player;

public:
	//������
	void Init();
	
	//�ǂݍ���
	void Load();

	//�ʏ폈��
	void Step();

	//�`�揈��
	void Draw();

	//�I������
	void Fin();
};
