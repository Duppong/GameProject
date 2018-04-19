#pragma once
#include "game.h"
#include "Scroll.h"

class GameObject
{
public:
	//file path, spawn points x ,y
	GameObject(const char* , const int x, int y, Scroll* tempScroll);
	~GameObject();

	void Update();
	void HandleEvent(SDL_Event& e);
	void Render();
	

private:
	int xpos;
	int ypos;

	//int velX;
	int velY;

	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;
};

