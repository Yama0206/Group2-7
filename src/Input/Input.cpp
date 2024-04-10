#include "DxLib.h"
#include "Input.h"

#define KEY_BUF_LEN	(256)

//���݂̃t���[���̃L�[���
char currentKeyBuf[KEY_BUF_LEN] = { 0 };

//�O�t���[���̃L�[���
char preKeyBuf[KEY_BUF_LEN] = { 0 };

//���͐��䏉����
void InitInput()
{
	for (int index = 0; index < KEY_BUF_LEN; index++)
	{
		currentKeyBuf[index] = '\0';
		preKeyBuf[index] = '\0';
	}
}

//���͐���̃X�e�b�v
//�ق��̃X�e�b�v��葁���Ă�
void StepInput()
{
	//�O�̃t���[���̃L�[���ϐ��ɋL�^���Ă���
	for (int index = 0; index < KEY_BUF_LEN; index++)
	{
		preKeyBuf[index] = currentKeyBuf[index];
	}

	//���݂̃L�[�����擾
	GetHitKeyStateAll(currentKeyBuf);
}

bool IsKeyPush(int key_code)
{
	//�O�U��ŉ�����ĂȂ��@���@���t���ŉ�����Ă���
	if (preKeyBuf[key_code] == 0 && currentKeyBuf[key_code] == 1)
		return true;

	//������ĂȂ��̂�false
	return false;
}

bool IsKeyKeep(int key_code)
{
	if (preKeyBuf[key_code] == 1 && currentKeyBuf[key_code] == 1)
	{
		return true;
	}

	return false;
}

bool IsKeyRelease(int key_code)
{
	if (preKeyBuf[key_code] == 1 && currentKeyBuf[key_code] == 0)
	{
		return true;
	}
	return false;
}

bool IsKeyDown(int key_code)
{
	//���t���ŉ�����Ă���i�O�U��̏�Ԃ͊֌W�Ȃ��j
	if (currentKeyBuf[key_code] == 1)
	{
		return true;
	}

	return false;
}
