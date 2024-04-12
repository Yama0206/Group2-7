#pragma once
#include "../../Player/Player.h"
#include "../../Player/Bullet/Bullet.h"
#include "../../Enemy/Enemy.h"

const float SHOT_INTERVAL = 5.0f;			//�e�̔��ˊ��o


//�v���C�V�[���N���X
class Play
{
private:
	Player player;
	Bullet bullet[256];
	Enemy enemy;

	float PlayerFramCnt;

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

	//���ƂŎg������
	/*void ShotInterval();*/
};
