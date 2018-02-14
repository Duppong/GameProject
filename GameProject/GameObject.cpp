#include "GameObject.h"
#include "TextureManager.h"



GameObject::GameObject(const char* textureSheet, int x, int y)
{
	objTexture = TextureManager::LoadTexture(textureSheet);

	xpos = x;
	ypos = y;
	velX = 0;
	velY = 0;

}

void GameObject::HandleEvent(SDL_Event & e)
{
	int velocty = 1;
	

	if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
	{
		switch (e.key.keysym.sym)
		{
		case SDLK_UP: velY -= velocty;
			break;
		case SDLK_DOWN: velY += velocty;
			break;
		case SDLK_LEFT: velX -= velocty;
			break;
		case SDLK_RIGHT: velX += velocty;
			break;
		}
	}
	else if (e.type == SDL_KEYUP && e.key.repeat == 0)
	{
		switch (e.key.keysym.sym)
		{
		case SDLK_UP: velY += velocty;
			break;
		case SDLK_DOWN: velY -= velocty;
			break;
		case SDLK_LEFT: velX += velocty;
			break;
		case SDLK_RIGHT: velX -= velocty;
			break;
		}
	}
}

void GameObject::Update()
{
	int gravity = 1;
	
	xpos += velX;
	if (xpos < 0 || (xpos + 64 > 800))
	{
		xpos -= velX;
	}

	ypos += velY;
	if (ypos < 0 || (ypos + 64 > 640))
	{
		ypos -= velY;
	}


	srcRect.h = 32;
	srcRect.w = 32;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = srcRect.w * 2;
	destRect.h = srcRect.h * 2;

}



void GameObject::Render()
{
	SDL_RenderCopy(game::renderer, objTexture, &srcRect, &destRect);
}

GameObject::~GameObject()
{
}
