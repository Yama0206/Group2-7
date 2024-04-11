#pragma once
#include "DxLib.h"

const char BULLET_PATH[] = { "" };

class Bullet
{
private:
	float PosX, PosY;		//���W
	int ImageHandle;		//�摜�n���h��

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

	void Move(float posX, float posY);

};
