#include "fallingObject.h"
#include "TextureManager.h"
#include <Windows.h>
#include "constants.h"
#include "fallingObject.h"


fallingObject::fallingObject(const char* textureSheet, int x, int y)
{
	objTexture = TextureManager::LoadTexture(textureSheet);

	xpos = x;
	ypos = y;
	velX = 0;
	velY = 0;

}


void fallingObject::HandleEvent(SDL_Event & e)
{
	int velocty = 2;
	const int base = 550;

	if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
	{
		switch (e.key.keysym.sym)
		{
			/*case SDLK_UP:;
			break;
			case SDLK_DOWN:;
			break;*/
		case SDLK_LEFT:;
			break;
		case SDLK_RIGHT:;
			break;
		case SDLK_SPACE:
		{
			break;
		}
		}
	}
	else if (e.type == SDL_KEYUP && e.key.repeat == 0)
	{
		switch (e.key.keysym.sym)
		{
			/*case SDLK_UP:;
			break;*/
			/*case SDLK_DOWN:;
			break;*/
		case SDLK_LEFT:;
			break;
		case SDLK_RIGHT:;
			break;
		case SDLK_SPACE:;
		}
	}
}

void fallingObject::Update()
{
	xpos += velX;

	if (xpos < 0 || (xpos + 64 > screenWidth))
	{
		xpos -= velX;
	}

	ypos += velY;

	if (ypos < 0 || (ypos + 64 > screenHeight))
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
int fallingObject::getXBox()
{
	return xpos;
}

int fallingObject::getYBox()
{
	return ypos;
}

void fallingObject::Render()
{
	
	SDL_RenderCopy(game::renderer, objTexture, &srcRect, &destRect);


	Sleep(2);
	if (ypos < 576 - 300)
		velY = 1;
}

fallingObject::~fallingObject()
{
	SDL_DestroyTexture(objTexture);
}