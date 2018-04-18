#include "Map.h"
#include "TextureManager.h"
#include <iostream>
#include "constants.h"
#include <fstream>

using namespace std;


Tile::Tile(int x, int y, int tileType)
{
	//get offsets
	tBox.x = x;
	tBox.y = y;

	//set collision box
	tBox.w = tileWidth;
	tBox.h = tileHeight;

	//get tile type
	tType = tileType;
}
int Tile ::getType()
{
	return tType;
}
SDL_Rect Tile::getBox()
{
	return tBox;
}

bool setTiles(Tile* tiles[])
{
	//succes check
	bool tilesLoaded = true;

	//tile offests
	int x = 0;
	int y = 0;

	//open map
	std::ifstream map("assets/game.map");

	if (map.end)
	{
		printf("unable to load map file!/n");
		tilesLoaded = false;
	}
	else
	{
		//intialize tiles
		for( int i = 0; i < 192; i++)
		{
			int tileType = -1;

			map >> tileType;

			if (map.fail())
			{
				printf("error loading map: unexpected end of file!\n");
				tilesLoaded = false;
				break;
			}

			if ((tileType >= 0) && (tileType < 192))
			{
				tiles[i] = new Tile(x, y, tileType);
			}
			else
			{
				//stop loading
				printf("error loading map: invalid file type at %d!\n", i);
				break;
			}
			//move to next tile spot
			x += tileWidth;

			if (x >= levelWidth)
			{
				//move back
				x = 0;

				//move to next row
				y += tileHeight;
			}
		}
	}
	map.close();
	return tilesLoaded;
}

int testMap[20][25] = {
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0 },
};

Map::Map()
{
	platform = TextureManager::LoadTexture("assets/platform.png");

	LoadMap(testMap);

	src.x = src.y = 0;
	src.w = dest.w = 32;
	src.h = dest.h = 32;
	dest.x = dest.y = 0;
}

void Map::LoadMap(int arr[20][25])
{
	for (int row = 0; row < 20; row++)
	{
		for (int column = 0; column < 25; column++)
		{
			map[row][column] = arr[row][column];
		}
	}
}

void Map::DrawMap()
{
	int type = 0;
	
	for (int row = 0; row < 20; row++)
	{
		for (int column = 0; column < 25; column++)
		{
			type = map[row][column];

			dest.x = column * 32;
			dest.y = row * 32;

			switch (type)
			{

			case 1: 
				TextureManager::Draw(platform, src, dest);
				break;
			default:
				break;
			}
		}
	}
}

