#include"Player.h"

//����������
void Player::Init()
{
	//���W
	PosX = 0;
	PosY = 0;

	//�摜�n���h��
	ImageHandle = -1;
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
	DrawFormatString(32, 32, GetColor(255, 0, 0), "%d, %d", PosX, PosY);
}

//�I������
void Player::Fin()
{
	
}

//�v���C���[�̈ړ�����
void Player::Move()
{
	//�����
	if(IsKeyKeep(KEY_INPUT_W))
	{
		PosY++;
	}
	//������
	if (IsKeyKeep(KEY_INPUT_S))
	{
		PosY--;
	}
	//�E����
	if (IsKeyKeep(KEY_INPUT_D))
	{
		PosX++;
	}
	//������
	if (IsKeyKeep(KEY_INPUT_A))
	{
		PosX--;
	}
}
