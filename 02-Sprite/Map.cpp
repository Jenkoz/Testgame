#include "Map.h"
#include "Textures.h"
#include "Mario.h"
Map* Map::__instance = NULL;
Map::Map() {}

#define MAP_TILE_ID 100000
#define ID_TEX_TILE 1000
#define DATA_MAP1_MAX_COL 29
#define DATA_MAP1_MAX_ROW 30


void Map::LoadResourses(LPCWSTR mapFile, LPCWSTR mapDataFile) {
	ifstream File;
	File.open(mapDataFile);
	File >> col >> row;
	//mapTiles = new int*[row];
	for (int r = 0; r < row; ++r) {
		//mapTiles[r] = new int [col];
		for (int c = 0; c < col; ++c) {
			File >> mapTiles[r][c];
		}
	}
	File.close();

	 
	CTextures* tex = CTextures::GetInstance();
	tex->Add(ID_TEX_TILE, mapFile);
	LPTEXTURE texMap = tex->Get(ID_TEX_TILE);

	int idTile = 1;
	for (int r = 0; r < DATA_MAP1_MAX_ROW; r++)
	{
		for (int c = 0; c < DATA_MAP1_MAX_COL; c++)
		{
			sprites->Add(idTile + MAP_TILE_ID, TILE_WIDTH * c, TILE_HEIGHT * r, TILE_WIDTH * (c + 1), TILE_HEIGHT * (r + 1), texMap);
			idTile++;
		}
	}
}
void Map::Render() {
	for (int r = 0; r < 600/TILE_WIDTH +1; r++) 
	{
		for (int c = 0; c < 800/TILE_HEIGHT +1; c++)
		{
			float x = c * TILE_WIDTH;
			if (x != 0)
				x -= 0.5;
			float y = r * TILE_HEIGHT;
			if (y != 0)
				y -= 0.5;
			sprites->Get(mapTiles[r+20][c] + MAP_TILE_ID + 1)->Draw(x , y);
		}
	}
}

Map* Map::GetInstance()
{
	if (__instance == NULL)
		__instance = new Map();
	return __instance;
}

Map::~Map() {
}