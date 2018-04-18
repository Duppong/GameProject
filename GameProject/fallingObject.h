#pragma once
#include "game.h"

class fallingObject
{
public:
	//file path, spawn points x ,y
	fallingObject(const char* textureSheet, int x, int y);
	void setCamera(SDL_Rect& Camera);
	~fallingObject();

	int getXBox();
	int	getYBox();
	void Update();
	void HandleEvent(SDL_Event& e);
	void Render();

private:
	int xpos;
	int ypos;

	int velX;
	int velY;

	SDL_Rect collisonBox;
	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;
};

