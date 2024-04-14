#include "Play.h"

//����������
void Play::Init()
{
	//�v���C���[�֘A
	player.Init();
	player.InitValue();

	PlayerFramCnt = 0.0f;

	MousePosX = 0.0f;		//�}�E�X��X���W
	MousePosY = 0.0f;		//�}�E�X��Y���W

	//�e�̏�����
	for (int i = 0; i < BULLET_MAX_NUM; i++)
	{
		bullet[i].Init();
	}

	//�G�֘A
	enemy.Init();
}

//�ǂݍ��ݏ���
void Play::Load()
{
	player.Load();				//�v���C���[�֘A
	enemy.Load();				//�G�֘A
	//�e�̐���for������
	for (int i = 0; i < BULLET_MAX_NUM; i++)
	{
		bullet[i].Load();		//�e�֘A
	}
}

//�ʏ폈��
void Play::Step()
{
	//�v���C���[�֘A
	player.Step();
	//�v���C���[�̃t���[�����J�E���g
	player.FramCnt(&PlayerFramCnt);

	//���ˏ���
	BulletShot();

	//�G�֘A
	enemy.Step();
}

//�`�揈��
void Play::Draw()
{
	//�v���C���[�֘A
	player.Draw();	
	for (int i = 0; i < BULLET_MAX_NUM; i++) {			//�e�̐���for������
		if (bullet[i].GetIsUse()) {
			//�e�֘A
			bullet[i].Draw();
		}
	}
	

	//�G�֘A
	enemy.Draw();
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

//���ˏ���
void Play::BulletShot()
{
	//�e�̐���for������
	for (int bulletIndex = 0; bulletIndex < BULLET_MAX_NUM; bulletIndex++)
	{

		//�v���C���[���e�𔭎˂������ǂ���
		if (player.IsShot())
		{
			if (!bullet[bulletIndex].GetIsUse()) {
				//�}�E�X�̍��W���擾
				GetMousePoint(&MousePosX, &MousePosY);

				//���˂�����e�̎g�p�t���O���I���ɂ���
				bullet[bulletIndex].SetIsUse(true);
			}
		}
		
		//�e���g���Ă��邩�ǂ���
		if (bullet[bulletIndex].GetIsUse())
		{
			//�}�E�X�̍��W��ۑ�
			bullet[bulletIndex].SetMousePos((float)MousePosX, (float)MousePosY);

			//�g���Ă�����e���ړ�������
			bullet[bulletIndex].Move(player.GetPosX(), player.GetPosY());
		}
	}
}