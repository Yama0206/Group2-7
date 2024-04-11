#pragma once
#include "DxLib.h"

const char BULLET_PATH[] = { "" };			//�e�摜�p�X
const int BULLET_MAX_NUM = 256;				//�e�̍ő吔

class Bullet
{
private:
	float PosX, PosY;		//���W
	int ImageHandle;		//�摜�n���h��
	bool IsUse;				//�e���g���Ă��邩�ǂ���

	//�}�E�X�֘A(������)
	int MousePosX, MousePosY;	//�}�E�X�̍��W

public:
	//������
	void Init();

	//�����l�ݒ�
	void DefaultValue();

	//�ǂݍ���
	void Load();

	//�ʏ폈��
	void Step();

	//�`��
	void Draw();

	//�I��
	void Fin();

	//�e�̈ړ��֐�
	void Move(float posX, float posY);

	//�e�̎g�p�t���O�̐ݒ�
	void SetIsUse(bool flag);
};
