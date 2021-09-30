#pragma once
#include "Sprites.h"
#include <fstream>



#define ID_TEXTURE_MAP_1 40
#define TILE_WIDTH 16
#define TILE_HEIGHT 16
#define DATA_MAP1_MAX_COL 73
#define DATA_MAP1_MAX_ROW 21

class Map
{
private:
	CSprites* sprites = CSprites::GetInstance();
	static Map* __instance;
	int col;
	int row;
	int** mapTiles;
public:

	Map();
	~Map();
	void LoadResourses(LPCWSTR mapFile, LPCWSTR mapDataFile);
	void Render();
	static Map* GetInstance();
};
