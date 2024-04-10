#pragma once
#include "Dxlib.h"
#include "../Scene/Scene.h"
#include "../Input/Input.h"

const char PLAYER_PATH[] = { "" };

//�v���C���[�N���X
class Player
{
private:
	float PosX, PosY;
	int ImageHandle;

public:
	//������
	void Init();

	//�ǂݍ���
	void Load();

	//�ʏ폈��
	void Step();

	//�`�揈��
	void Draw();

	//�I������
	void Fin();

	//�v���C���[�̈ړ�
	void Move();
};