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

    //�w�i�ǂݍ���
	PlayImageHandle = LoadGraph("data/PlayImage/BackGround.png");

	PlayFinFreamCnt = 0;

	Bullet_SE = -1;
	Bgm = -1;

	//��������
	PlayFinCnt = 30;
	PlayFinFreamCntNum = 0;
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

	//���ˉ��̓ǂݍ���
	Bullet_SE = LoadSoundMem(SHOT_SE);
	Bgm = LoadSoundMem(BGM);

	PlaySoundMem(Bgm, DX_PLAYTYPE_LOOP);

}

//�ʏ폈��
void Play::Step()
{
	PlayFinFreamCnt++;

	//�v���C���[�֘A
	player.Step();

	//���ˏ���
	BulletShot();

	//�����蔻��
	EnemyToBulletCollision();

	//�G�ƃv���C���[�̓����蔻��
	EnemyToPlayer();
	
	//���G����
	PlayerIsInv();

	//�G�̃��X�|�[������
	RespawnEnemy();

	//�G�֘A
	enemy.Step();

	//�������Ԃ��J�E���g
	PlayFinFreamCntNum++;
	if (PlayFinFreamCntNum >=60)
	{
		PlayFinCnt -= 1;
		PlayFinFreamCntNum = 0;
	}
}

//�`�揈��
void Play::Draw()
{
	//�w�i�`��
	DrawRotaGraph(320, 240, 1.0f, 0.0f, PlayImageHandle, true);

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

	//�������ԕ`��
	DrawFormatString(0, 0, GetColor(255, 0, 0), "�c�莞��:%d", PlayFinCnt);
}

//�I������
void Play::Fin()
{

}


//���ˏ���
void Play::BulletShot()
{
	//�e�̐���for������
	for (int bulletIndex = 0; bulletIndex < BULLET_MAX_NUM; bulletIndex++)
	{

		//�v���C���[���e�𔭎˂������ǂ���
		if (player.IsShot())
		{
			//�N���b�N�����疳�G������
			player.SetIsStartInv(false);

			if (!bullet[bulletIndex].GetIsUse()) {
				//�}�E�X�̍��W���擾
				GetMousePoint(&MousePosX, &MousePosY);

				PlaySoundMem(Bullet_SE, DX_PLAYTYPE_BACK);

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
			if (enemy.GetIsAllive(enemyIndex)) {
				//����������
				if (IsHitRect(bullet[bulletIndex].GetPosX(), bullet[bulletIndex].GetPosY(), BULLET_SIZE, BULLET_SIZE,
					enemy.EnemyPosX[enemyIndex], enemy.EnemyPosY[enemyIndex], ENEMY_SIZE, ENEMY_SIZE))
				{
					enemy.IsAllive[enemyIndex] = false;
				}
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
		if (enemy.GetIsAllive(enemyIndex)) {
			if (!player.GetIsInv() && !player.GetIsStartInv()) {
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

						Fin();
					}
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

void Play::RespawnEnemy()
{
	for (int i = 0; i < ENEMY_MAX_NUM; i++)
	{
		if (enemy.GetIsAllive(i) == false)
		{
			//���X�|�[���J�E���g�����Z
			enemy.AddRespawnCnt();

			//�J�E���g��240�ɂȂ����烊�X�|�[��
			if (enemy.GetRespawnCnt() == 120)
			{
				enemy.SetIsAllive(true, i);

				enemy.SetRespawnCnt(0);
			}
		}
	}
}