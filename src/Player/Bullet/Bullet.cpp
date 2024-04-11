#include "Bullet.h"

//������
void Bullet::Init()
{
	//���W
	PosX = 0.0f;		//X���W
	PosY = 0.0f;		//Y���W

	//�摜�n���h��
	ImageHandle = -1;

	//�t���O
	IsUse = false;		//�e���g���Ă��邩�ǂ���
}

//�����l�ݒ�
void Bullet::DefaultValue()
{
	//���W
	PosX = 0.0f;		//X���W
	PosY = 0.0f;		//Y���W
}

//�ǂݍ���
void Bullet::Load()
{
	
	ImageHandle = LoadGraph(BULLET_PATH);
}

//�ʏ폈��
void Bullet::Step()
{

}

//�`�揈��
void Bullet::Draw()
{

}

//�I������
void Bullet::Fin()
{

}

//�e�̈ړ��֐�
void Bullet::Move(float posX, float posY)
{
	//�}�E�X�̍��W���擾
	GetMousePoint(&MousePosX, &MousePosY);


}

void Bullet::SetIsUse(bool flag)
{
	IsUse = flag;
}
