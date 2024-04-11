#include "Bullet.h"

void Bullet::Init()
{
	PosX = 0.0f;
	PosY = 0.0f;

	ImageHandle = -1;

}

void Bullet::DefaultValue()
{
	PosX = 0.0f;
	PosY = 0.0f;
}

void Bullet::Load()
{
	ImageHandle = LoadGraph(BULLET_PATH);
}

void Bullet::Step()
{

}

void Bullet::Draw()
{

}

void Bullet::Fin()
{

}

void Bullet::Move(float posX, float posY)
{
	//マウスの座標を取得
	GetMousePoint(&MousePosX, &MousePosY);
}