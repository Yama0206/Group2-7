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

	//���ˏ���
	BulletShot();

	//�����蔻��
	EnemyToBulletCollision();

	//�G�ƃv���C���[�̓����蔻��
	EnemyToPlayer();
	
	PlayerIsInv();

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
	
	DrawFormatString(32, 128, GetColor(255, 0, 0), "%d", player.GetHP());

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

				//�e�̔��ˈʒu���v���C���[�̍��W�ɐݒ�
				bullet[bulletIndex].SetPos(player.GetPosX(), player.GetPosY());
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

//�G�ƒe�̓����蔻��
void Play::EnemyToBulletCollision()
{
	//�G�̐���for������
	for (int enemyIndex = 0; enemyIndex < ENEMY_MAX_NUM; enemyIndex++) {
		//�e�̐�����for������
		for (int bulletIndex = 0; bulletIndex < BULLET_MAX_NUM; bulletIndex++) {
			//����������
			if (IsHitRect(bullet[bulletIndex].GetPosX(), bullet[bulletIndex].GetPosY(), BULLET_SIZE, BULLET_SIZE,
				enemy.EnemyPosX[enemyIndex], enemy.EnemyPosY[enemyIndex], ENEMY_SIZE, ENEMY_SIZE))
			{
				enemy.IsAllive[enemyIndex] = false;
			}
		}
	}
}

//�G�ƃv���C���[�̓����蔻��
void Play::EnemyToPlayer()
{
	//�G�̐���for������
	for (int enemyIndex = 0; enemyIndex < ENEMY_MAX_NUM; enemyIndex++)
	{
		if (!player.GetIsInv()) {
			//�G�ƃv���C���[������������
			if (IsHitRect(player.GetPosX(), player.GetPosY(), PLAYER_SIZE, PLAYER_SIZE,
				enemy.EnemyPosX[enemyIndex], enemy.EnemyPosY[enemyIndex], ENEMY_SIZE, ENEMY_SIZE))
			{
				player.SetIsInv(true);
				//�v���C���[��HP�����炷
				player.SetHP(-1);

				//HP���[���ɂȂ�����
				if (player.GetHP() == 0)
				{
					player.SetIsAllive(false);
				}
			}
		}
	}
}

void Play::PlayerIsInv()
{
	if (player.GetIsInv())
	{
		//�v���C���[�̃t���[�����J�E���g
		player.FramCnt(&PlayerFramCnt);

		if (PlayerFramCnt == 120)
		{
			player.SetIsInv(false);

			PlayerFramCnt = 0;
		}
	}
}