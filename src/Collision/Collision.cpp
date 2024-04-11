#include "Collision.h"
#include "DxLib.h"

//IsHitRectの定義
// 関数の定義
bool IsHitRect(int Ax, int Ay, int Aw, int Ah, int Bx, int By, int Bw, int Bh) {
	if (Bx < Ax + Aw &&
		Bx + Bw > Ax &&
		By + Bh > Ay &&
		By < Ay + Ah)
	{
		// 当たっているときの処理
		return true;
	}
	return false;
}

//IsHitCircleの定義
bool IsHitCircle(int CircleAx, int CircleAy, int CircleAr, int CircleBx, int CircleBy, int CircleBr) {
	if ((CircleAr + CircleBr) * (CircleAr + CircleBr) >
		(CircleAx - CircleBx) * (CircleAx - CircleBx) + (CircleAy - CircleBy) * (CircleAy - CircleBy))
	{
		// 当たっているときの処理
		return true;
	}
	return false;
}

// ボックス同士の当たり判定
bool IsHit3DRect(VECTOR pos1, VECTOR size1, VECTOR pos2, VECTOR size2)
{
	// 半分のサイズを計算する
	VECTOR halfSize1 = { size1.x * 0.5f, size1.y * 0.5f, size1.z * 0.5f };
	VECTOR halfSize2 = { size2.x * 0.5f, size2.y * 0.5f, size2.z * 0.5f };
	// 実際の当たり判定
	if (pos1.x - halfSize1.x < pos2.x + halfSize2.x
		&& pos1.x + halfSize1.x > pos2.x - halfSize2.x
		&& pos1.y - halfSize1.y < pos2.y + halfSize2.y
		&& pos1.y + halfSize1.y > pos2.y - halfSize2.y
		&& pos1.z - halfSize1.z < pos2.z + halfSize2.z
		&& pos1.z + halfSize1.z > pos2.z - halfSize2.z)
	{
		return true;
	}
	return false;
}

// 球同士の当たり判定
bool IsHitSphere(VECTOR pos1, float r1, VECTOR pos2, float r2)
{
	// 2点間を引き算する
	VECTOR dist = VSub(pos1, pos2);
	// 2点間の距離の2乗を計算する
	float length = (dist.x * dist.x) + (dist.y * dist.y)
		+ (dist.z * dist.z);
	// 二つの球の半径を足して2乗する
	float radius = (r1 + r2) * (r1 + r2);

	// 最終的な当たり判定
	if (length < radius) return true;
	else return false;
}

bool IsHitSphere2(VECTOR pos1, float r1, VECTOR pos2, float r2)
{
	pos1.x = pos1.x - pos2.x;
	pos1.y = pos1.y - pos2.y;
	pos1.z = pos1.z - pos2.z;

	pos1.x = pos1.x * pos1.x;
	pos1.y = pos1.y * pos1.y;
	pos1.z = pos1.z * pos1.z;

	float length = pos1.x + pos1.y + pos1.z;

	float radius = (r1 + r2) * (r1 + r2);

	if (length < radius)
	{
		return true;
	}
	else
	{
		return false;
	}
}