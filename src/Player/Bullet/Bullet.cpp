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
	for (int i = 0; i < BULLET_MAX_NUM; i++)
	{
		if (IsUse) {
			DrawRotaGraph(PosX, PosY, 1.0f, 0.0f, ImageHandle, false, true);
		}
	}
		
	if (PosX > 640+32 || PosX < 0-32 || PosY>480+32 || PosY < 0-32)
	{
		IsUse = false;

		//��ʊO�ɏo����e�̔��ˈʒu�ɖ߂�
		PosX = 0.0f;
		PosY = 0.0f;
	}
}

//�I������
void Bullet::Fin()
{

}

//�e�̈ړ��֐�
void Bullet::Move(float x, float y)
{
	//X,Y�x�N�g��
	VECTOR vBulletPos = { 0.0f, 0.0f, 0.0f };

	//��_�Ԃ̋���
	float TwoPoint = 0.0f;

	

	//X,Y�x�N�g�����v�Z
	vBulletPos.x = MousePos.x - x;
	vBulletPos.y = MousePos.y - y;

	//��_�Ԃ̋������擾
	TwoPoint = (vBulletPos.x * vBulletPos.x) + (vBulletPos.y * vBulletPos.y);

	//�����������߂�
	TwoPoint = sqrtf(TwoPoint);

	//������for�����g���ƂȂ����f�������オ��
	for (int i = 0; i < SPEED_NUM; i++)
	{
		//���K�������l�𑫂�
		PosX += vBulletPos.x / TwoPoint;
		PosY += vBulletPos.y / TwoPoint;
	}
}

void Bullet::SetIsUse(bool flag)
{
	
		IsUse = flag;
	
}

void Bullet::SetMousePos(float posX, float posY)
{
	MousePos.x = posX;
	MousePos.y = posY;
}