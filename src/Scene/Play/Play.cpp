#include "Play.h"

//����������
void Play::Init()
{
	//�v���C���[�֘A
	player.Init();			
	player.InitValue();

	PlayerFramCnt = 0.0f;

}

//�ǂݍ��ݏ���
void Play::Load()
{
	//�v���C���[�֘A
	player.Load();			
}

//�ʏ폈��
void Play::Step()
{
	//�v���C���[�֘A
	player.Step();
	//�v���C���[�̃t���[�����J�E���g
	player.FramCnt(&PlayerFramCnt);
}

//�`�揈��
void Play::Draw()
{
	//�v���C���[�֘A
	player.Draw();	

	//�f�o�b�O
	DrawFormatString(32, 100, GetColor(255, 0, 0), "%f", PlayerFramCnt);
}

//�I������
void Play::Fin()
{

}

//���ˊԊu
//void Play::ShotInterval()
//{
//	//���˂���܂ł̎���
//	if (PlayerFramCnt > SHOT_INTERVAL)
//	{
//		PlayerFramCnt = SHOT_INTERVAL;
//	}
//	//���ˊԊu�Ɣ��˃t���O���I���ɂȂ����甭��
//	if (player.IsShot() && PlayerFramCnt == SHOT_INTERVAL)
//	{
//		//�e�̏�񏈗�
//		for (int BulletIndex = 0; BulletIndex < BULLET_MAX_NUM; BulletIndex++)
//		{
//
//		}
//	}
//}