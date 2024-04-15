#pragma once
#include "../../Player/Player.h"
#include "../../Player/Bullet/Bullet.h"
#include "../../Enemy/Enemy.h"
#include "../../Collision/Collision.h"

const float SHOT_INTERVAL = 5.0f;			//�e�̔��ˊ��o
const char SHOT_SE[] = { "data/Sound/ShotSE1.wav" };
const char BGM[] = { "data/Sound/maou_bgm_cyber44.mp3" };

//�v���C�V�[���N���X
class Play
{
private:
	Player player;
	Bullet bullet[256];
	Enemy enemy;

	//�v���C���[�t���[���J�E���g
	float PlayerFramCnt;
	
	//�}�E�X�֘A(������)
	int MousePosX, MousePosY;	//�}�E�X�̍��W

	//�v���C�V�[���̔w�i�摜
	int PlayImageHandle;

	//�������ԃJ�E���g
	int PlayFinFreamCnt;
	int PlayFinFreamCntNum;
	int PlayFinCnt;

	//�T�E���h
	int Bullet_SE;
	int Bgm;

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

	//�G�̍ďo������
	void RespawnEnemy();
};
