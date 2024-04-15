//#include "Map.h"
//#include "../Collision/Collision.h"
//#include "DxLib.h"
//#include <string.h>
//
//const int MAX_DATA_LEN = 256;
//
//Map::Map() :m_MapData{
//	{1,1,1,1,1,1,1,1,1,1},
//	{1,0,0,0,0,0,0,0,0,1},
//	{1,0,0,0,0,0,0,0,0,1},
//	{1,0,0,1,0,0,1,0,0,1},
//	{1,0,0,1,0,0,1,0,0,1},
//	{1,0,0,0,0,0,0,0,0,1},
//	{1,0,0,0,0,0,0,0,0,1},
//	{1,1,1,1,1,1,1,1,1,1} }
//{
//	imgHundle = -1;
//
//	m_x = 0;
//	m_y = 0;
//
//}
//
//Map::~Map() {}
//
//void Map::InitMap() {
//	// 画像の読み込み
//	imgHundle = LoadGraph("../mapchip_1.png");
//
//	m_x = 40;
//	m_y = 40;
//	m_x2 = 0;
//	m_y2 = 0;
//}
//
//void Map::DrawMap() {
//	DrawFormatString(0, 0, GetColor(255, 255, 255), "draw成功");
//
//	for (int y = 0; y < MAP_DATA_Y; y++)
//	{
//		for (int x = 0; x < MAP_DATA_X; x++)
//		{
//			// ブロックを描画
//
//			if (m_MapData[y][x] == 1) {
//				DrawGraph(x * MAP_SIZE, y * MAP_SIZE, imgHundle, true);
//			}
//		}
//	}
//}
//
//void Map::DebugMap()
//{
//	DrawBox(m_x, m_y, m_x + PLAYER_SIZE, m_y + PLAYER_SIZE, GetColor(255, 0, 0), true);
//
//	for (int y = 0; y < MAP_DATA_Y; y++)
//	{
//		for (int x = 0; x < MAP_DATA_X; x++)
//		{
//
//			if (m_MapData[y][x] == 0)
//			{
//				continue;
//			}
//
//			//キャラクターとマップの当たり判定
//			if (IsHitRect(m_x, m_y, PLAYER_SIZE, PLAYER_SIZE,
//				x * MAP_SIZE, y * MAP_SIZE,
//				MAP_SIZE, MAP_SIZE))
//			{
//				DrawFormatString(200, 100, GetColor(255, 255, 255), "hittttt");
//			}
//
//		}
//	}
//
//	if (CheckHitKey(KEY_INPUT_A)) //左移動
//	{
//		m_x--;
//	}
//
//	if (CheckHitKey(KEY_INPUT_D)) //右移動
//	{
//		m_x++;
//	}
//
//	if (CheckHitKey(KEY_INPUT_W)) //上移動
//	{
//		m_y--;
//	}
//
//	if (CheckHitKey(KEY_INPUT_S)) //下移動
//	{
//		m_y++;
//	}
//
//}
//
//void Map::MapCollision()
//{
//	for (int y = 0; y < MAP_DATA_Y; y++)
//	{
//		for (int x = 0; x < MAP_DATA_X; x++)
//		{
//
//			if (m_MapData[y][x] == 0)
//			{
//				continue;
//			}
//
//			//キャラクターとマップの当たり判定
//			if (IsHitRect(m_x, m_y, PLAYER_SIZE, PLAYER_SIZE,
//				x * MAP_SIZE, y * MAP_SIZE,
//				MAP_SIZE, MAP_SIZE))
//			{
//				DrawFormatString(200, 100, GetColor(255, 255, 255), "hittttt");
//
//				m_x = m_x2;
//				m_y = m_y2;
//			}
//
//		}
//	}
//
//	m_x2 = m_x;
//	m_y2 = m_y;
//
//}