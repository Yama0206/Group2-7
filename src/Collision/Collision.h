#pragma once
#include "DxLib.h"


//IsHitRect�̃v���g�^�C�v�錾
bool IsHitRect(int Ax, int Ay, int Aw, int Ah, int Bx, int By, int Bw, int Bh);

//IsHitRect�̃v���g�^�C�v�錾
bool IsHitRect(float Ax, float Ay, float Aw, float Ah, float Bx, float By, float Bw, float Bh);

//IsHitCircle�̃v���g�^�C�v�錾
bool IsHitCircle(int CircleAx, int CircleAy, int CircleAr, int CircleBx, int CircleBy, int CircleBr);

// �{�b�N�X���m�̓����蔻��
bool IsHit3DRect(VECTOR pos1, VECTOR size1, VECTOR pos2,  VECTOR size2);

// �����m�̓����蔻��
bool IsHitSphere(VECTOR pos1, float r1, VECTOR pos2, float r2);

bool IsHitSphere2(VECTOR pos1, float r1, VECTOR pos2, float r2);