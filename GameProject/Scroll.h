#pragma once
#include "game.h"
class Scroll
{
public:
	//file path, spawn points x ,y
	Scroll(const char*, int x, int y);
	~Scroll();

	void Update();
	void HandleEvent(SDL_Event& e);
	void Render();
	int base();

private:
	int xpos;
	int ypos;

	int velX;
	int velY;

	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;
	SDL_Rect srcSqu, destsqu;
};
