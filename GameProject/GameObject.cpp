#include "GameObject.h"
#include "TextureManager.h"
#include <Windows.h>
#include "constants.h"


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
	int velocty = 2;
	int jumppoint = 0;// jumping variables
	const int base = 576;

	if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
	{
		switch (e.key.keysym.sym)
		{
		/*case SDLK_UP: velY -= velocty;
			break;
		case SDLK_DOWN: velY += velocty;
			break;*/
		case SDLK_LEFT: velX -= velocty;
			break;
		case SDLK_RIGHT: velX += velocty;
			break;
		case SDLK_SPACE:
		{
			if (ypos = base)
				velY = -3;
			else velY = 3;
			break;
		}
		}
	}
	else if (e.type == SDL_KEYUP && e.key.repeat == 0)
	{
		switch (e.key.keysym.sym)
		{
		/*case SDLK_UP: velY += velocty;
			break;*/
		/*case SDLK_DOWN: velY -= velocty;
			break;*/
		case SDLK_LEFT: velX += velocty;
			break;
		case SDLK_RIGHT: velX -= velocty;
			break;
		case SDLK_SPACE: velY = 3;
		}
	}
}

void GameObject::Update(SDL_Rect& Box)
{
	xpos += velX;

	if (xpos < 0 || (xpos + 64 > screenWidth) )
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

int GameObject::getX()
{
	return xpos;
}

int GameObject::getY()
{
	return ypos;
}

bool checkCollision(SDL_Rect& a, SDL_Rect& b)
{
	//check sides of rect
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;
	return false;
}


void GameObject::Render()
{
	SDL_RenderCopy(game::renderer, objTexture, &srcRect, &destRect);


	Sleep(2);
	if (ypos < 576 - 300)
		velY = 2;
}

GameObject::~GameObject()
{
}