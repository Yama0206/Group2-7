#pragma once
#include "../../Player/Player.h"
#include "../../Player/Bullet/Bullet.h"

//�v���C�V�[���N���X
class Play
{
private:
	Player player;
	Bullet bullet[256];

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
