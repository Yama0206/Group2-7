#pragma once
#include "../../Player/Player.h"
#include "../../Player/Bullet/Bullet.h"
#include "../../Enemy/Enemy.h"
#include "../../Collision/Collision.h"

const float SHOT_INTERVAL = 5.0f;			//�e�̔��ˊ��o


//�v���C�V�[���N���X
class Play
{
private:
	Player player;
	Bullet bullet[256];
	Enemy enemy;

	float PlayerFramCnt;
	
	float Startp;
	
	//�}�E�X�֘A(������)
	int MousePosX, MousePosY;	//�}�E�X�̍��W

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

	//���ˏ���
	void BulletShot();

	//�G�ƒe�̓����蔻��
	void EnemyToBulletCollision();

	//�G�ƃv���C���[�̓����蔻��
	void EnemyToPlayer();

	//���G�t���O��������
	void PlayerIsInv();
};
