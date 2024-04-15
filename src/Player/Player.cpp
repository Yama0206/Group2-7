#include"Player.h"

//����������
void Player::Init()
{
	//���W
	PosX = 0.0f;
	PosY = 0.0f;

	Speed = 0.0f;

	HP = 0;

	IsAllive = true;
	IsInv = false;
	IsStartInv = true;
	IsDraw = true;

	//�摜�n���h��
	ImageHandle = -1;
}

//�����l�ݒ�
void Player::InitValue()
{
	//���W�ݒ�
	PosX = 320.0f;
	PosY = 240.0f;

	HP = 3;

	//����
	Speed = 2.0f;
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
	if (IsAllive && IsDraw) {
		DrawRotaGraph(PosX, PosY, 1.0f, 0.0f, ImageHandle, true, false);
	}
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
		PosY -= Speed;
	}
	//������
	if (IsKeyKeep(KEY_INPUT_S))
	{
		PosY += Speed;
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


bool Player::IsShot()
{
	if (GetMouseInput() && MOUSE_INPUT_LEFT != 0)
	{
		return true;
	}

	return false;
}

//�v���C���[�̍��W
void Player::FramCnt(float* framcnt)
{
	*framcnt+=1;
}
