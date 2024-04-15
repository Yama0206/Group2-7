#pragma once
#include "DxLib.h"
#include "math.h"

const char BULLET_PATH[] = { "data/Player/BulletImage.png" };			//�e�摜�p�X
const int BULLET_MAX_NUM = 256;				//�e�̍ő吔
const float BULLET_SIZE = 16.0f;					//�e�̑傫��(�c������)

//�X�s�[�h�̒l
const int SPEED_NUM = 30;

class Bullet
{
private:
	float PosX, PosY;		//���W
	int ImageHandle;		//�摜�n���h��
	bool IsUse;				//�e���g���Ă��邩�ǂ���

	//�}�E�X�̍��W�ۑ��p�ϐ�
	VECTOR MousePos = { 0.0f, 0.0f, 0.0f };

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
	void Move(float x, float y);

	//�e�̍��W��ݒ�
	void  SetPos(float x, float y);

	//�e�̍��W�̎擾
	float GetPosX() { return PosX; }
	float GetPosY() { return PosY; }

	//�e�̎g�p�t���O�̐ݒ�
	void SetIsUse(bool flag);

	//�e���g���Ă��邩�ǂ����t���O���擾
	bool GetIsUse() { return IsUse; }

	void SetMousePos(float posX, float posY);
};

//extern Bullet PosX;