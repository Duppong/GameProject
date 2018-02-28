#pragma once
#include "game.h"

class GameObject
{
public:
	//file path, spawn points x ,y
	GameObject(const char* textureSheet, int x, int y);
	~GameObject();

	void Update();
	void setCamera(SDL_Rect& camera);
	void HandleEvent(SDL_Event& e);
	void Render();

private:
	int xpos;
	int ypos;

	int velX;
	int velY;

	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;
};

