#pragma once
#include "Dxlib.h"
#include "../Scene/Scene.h"
#include "../Input/Input.h"

const char PLAYER_PATH[] = { "data/Player/PlayerImage.png" };
const float PLAYER_SIZE = 32.0f;

//�v���C���[�N���X
class Player
{
private:
	float PosX, PosY;			//���W
	float Speed;				//����
	int ImageHandle;			//�摜�n���h��
	int HP;						//�̗�

	bool IsInv;					//���G�t���O
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

	//�����Ă��邩�ǂ����̐ݒ�
	void SetIsAllive(bool Isflag) { IsAllive = Isflag; }
	//�����Ă��邩�ǂ����̎擾
	bool GetIsAllive() { return IsAllive; }

	//���G�t���O�̃Z�b�g
	void SetIsInv(bool IsFlag) { IsInv = IsFlag; }
	//���G�t���O���擾
	bool GetIsInv() { return IsInv; }

	//HP�̒l�̕ύX
	void SetHP(int hp) { HP += hp; }
	//HP�擾
	int GetHP() { return HP; }

	//�v���C���[�̍��W�擾
	void FramCnt(float* framcnt);

	//�v���C���[������ł������ǂ���
	bool IsShot();
};
