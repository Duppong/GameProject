#include "GameObject.h"
#include "TextureManager.h"
#include "Scroll.h"
#include <Windows.h>
int jumpbase;
 int base;
Scroll* checkBase;

GameObject::GameObject(const char* textureSheet, int x, int y, Scroll* tempScroll)
{
	objTexture = TextureManager::LoadTexture(textureSheet);

	xpos = x;
	ypos = y;
	//velX = 0;
	velY = 0;
	checkBase = tempScroll;
	
	
}

void GameObject::HandleEvent(SDL_Event & e)
{
	base = checkBase->base();
	
	
	if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
	{
		switch (e.key.keysym.sym)
		{
		
		case SDLK_SPACE: 
		{
			if (velY == -2)
				velY = -2;
			else if (ypos == base)
			{
				velY = 2;
				jumpbase = base;
			}
			
			break;
		}
		}
	}
	else if (e.type == SDL_KEYUP && e.key.repeat == 0)
	{
		
		switch (e.key.keysym.sym)
		{
		
		case SDLK_SPACE: 
		{
			velY = -2;
			if (velY == -2 && (ypos == base))
			{
				velY = 0;
			}
		}

		}
	}
	
}

void GameObject::Update()
{
	
	base = checkBase->base();
	if (velY == -2 && (ypos == base))
		{
			velY = 0;
		}
	if (velY == 0 && ypos < base)
		velY = -2;
	if (ypos < jumpbase - 240)
		velY = -2;
	if (ypos > 0 )
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
