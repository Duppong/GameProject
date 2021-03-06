#pragma once
#include "game.h"

class GameObject
{
public:
	//file path, spawn points x ,y
	GameObject(const char* textureSheet, int x, int y);
	~GameObject();

	void Update(SDL_Rect& Box);
	void HandleEvent(SDL_Event& e);
	void Render();
	int getX();
	int getY();

private:
	int xpos;
	int ypos;

	int velX;
	int velY;
  
	SDL_Rect collisonBox;
	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;
};

