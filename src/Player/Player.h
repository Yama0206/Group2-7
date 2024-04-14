#pragma once
#include "Dxlib.h"
#include "../Scene/Scene.h"
#include "../Input/Input.h"

const char PLAYER_PATH[] = { "data/Player/PlayerImage.png" };

//�v���C���[�N���X
class Player
{
private:
	float PosX, PosY;			//���W
	float Speed;				//����
	int ImageHandle;			//�摜�n���h��

	bool IsAllive;				//�����Ă��邩�ǂ���
public:
	//������
	void Init();

	//�����l�ݒ�
	void InitValue();

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

	//�v���C���[�̍��W�擾
	float GetPosX() { return PosX; }		//X���W
	float GetPosY() { return PosY; }		//Y���W

	//�v���C���[�̍��W�擾
	void FramCnt(float* framcnt);

	//�v���C���[������ł������ǂ���
	bool IsShot();
};