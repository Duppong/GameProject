#pragma once
#include "game.h"
class Map
{
public:
	Map();
	~Map();

	void LoadMap(int arr[20][25]);
	void DrawMap();

private:
	SDL_Rect src, dest;
	SDL_Texture* platform;

	int map[20][25];
};


class Tile
{
public:
	//tile info
	Tile(int x, int y, int tileType);
	//get tile type
	int getType();
	//get collision box
	SDL_Rect getBox();
private:
	//attributes of Tile
	SDL_Rect tBox;
	//tile type
	int tType;
};