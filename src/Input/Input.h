#pragma once

//入力制御初期化
void InitInput();

//入力制御ステップ
//ほかのStepより早く呼ぶ
void StepInput();

//今押された
bool IsKeyPush(int key_code);

//押し続ける
bool IsKeyKeep(int key_code);

//離したとき
bool IsKeyRelease(int key_code);

bool IsKeyDown(int key_code);