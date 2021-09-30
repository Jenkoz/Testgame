#pragma once
#include "Sprites.h"
#include <fstream>



#define ID_TEXTURE_MAP_1 40
#define TILE_WIDTH 48
#define TILE_HEIGHT 48

class Map
{
private:
	CSprites* sprites = CSprites::GetInstance();
	static Map* __instance;
	int col;
	int row;
	int mapTiles[43][183];
public:

	Map();
	~Map();
	void LoadResourses(LPCWSTR mapFile, LPCWSTR mapDataFile);
	void Render();
	static Map* GetInstance();
};
