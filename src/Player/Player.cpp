#include"Player.h"

//����������
void Player::Init()
{
	//���W
	PosX = 0.0f;
	PosY = 0.0f;

	Speed = 0.0f;

	//�摜�n���h��
	ImageHandle = -1;
}

//�����l�ݒ�
void Player::InitValue()
{
	//���W�ݒ�
	PosX = 0.0f;
	PosY = 0.0f;

	//����
	Speed = 1.0f;
}

//�ǂݍ��ݏ���
void Player::Load()
{
	ImageHandle = LoadGraph(PLAYER_PATH);
}

//�ʏ폈��
void Player::Step()
{
	//�ړ�����
	Move();
}

//�`�揈��
void Player::Draw()
{
	//�f�o�b�O�p
	DrawFormatString(32, 32, GetColor(255, 0, 0), "%f %f", PosX, PosY);
}

//�I������
void Player::Fin()
{
	
}

//�v���C���[�̑���֘A
//�v���C���[�̈ړ�����
void Player::Move()
{
	//�����
	if(IsKeyKeep(KEY_INPUT_W))
	{
		PosY += Speed;
	}
	//������
	if (IsKeyKeep(KEY_INPUT_S))
	{
		PosY -= Speed;
	}
	//�E����
	if (IsKeyKeep(KEY_INPUT_D))
	{
		PosX += Speed;
	}
	//������
	if (IsKeyKeep(KEY_INPUT_A))
	{
		PosX -= Speed;
	}


}

//�v���C���[������ł��̕���
void Player::ShotDir()
{
	//�}�E�X�̍��W���擾
	GetMousePoint(&MousePosX, &MousePosY);


}

//�v���C���[�̍��W
void Player::GetPlayerPos(float* posX, float* posY)
{
	posX = &PosX;
	posY = &PosY;
}
