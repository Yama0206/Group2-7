#include "DxLib.h"
#include "Input.h"

#define KEY_BUF_LEN	(256)

//現在のフレームのキー情報
char currentKeyBuf[KEY_BUF_LEN] = { 0 };

//前フレームのキー情報
char preKeyBuf[KEY_BUF_LEN] = { 0 };

//入力制御初期化
void InitInput()
{
	for (int index = 0; index < KEY_BUF_LEN; index++)
	{
		currentKeyBuf[index] = '\0';
		preKeyBuf[index] = '\0';
	}
}

//入力制御のステップ
//ほかのステップより早く呼ぶ
void StepInput()
{
	//前のフレームのキー情報変数に記録しておく
	for (int index = 0; index < KEY_BUF_LEN; index++)
	{
		preKeyBuf[index] = currentKeyBuf[index];
	}

	//現在のキー情報を取得
	GetHitKeyStateAll(currentKeyBuf);
}

bool IsKeyPush(int key_code)
{
	//前振れで押されてない　かつ　現フレで押されている
	if (preKeyBuf[key_code] == 0 && currentKeyBuf[key_code] == 1)
		return true;

	//押されてないのでfalse
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
	//現フレで押されている（前振れの状態は関係なし）
	if (currentKeyBuf[key_code] == 1)
	{
		return true;
	}

	return false;
}
