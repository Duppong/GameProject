#include "Scroll.h"
#include "TextureManager.h"
#include <Windows.h>


Scroll::Scroll(const char* textureSheet, int x, int y)
{
	objTexture = TextureManager::LoadTexture(textureSheet);

	xpos = x;
	ypos = y;
	velX = 0;
	velY = 0;

}

void Scroll::HandleEvent(SDL_Event & e)
{
	int velocty = 2;
	
	if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
	{
		switch (e.key.keysym.sym)
		{
		case SDLK_LEFT: velX += velocty;
			break;
		case SDLK_RIGHT: velX -= velocty;
			break;
		
		}
	}
	else if (e.type == SDL_KEYUP && e.key.repeat == 0)
	{
		switch (e.key.keysym.sym)
		{
		case SDLK_LEFT: velX -= velocty;
			break;
		case SDLK_RIGHT: velX += velocty;
			break;
			
		}
	}
}

void Scroll::Update()
{
	xpos += velX;

	srcRect.h = 270;
	srcRect.w = 1500;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = srcRect.w * 2;
	destRect.h = srcRect.h * 2;

}



void Scroll::Render()
{
	SDL_RenderCopy(game::renderer, objTexture, &srcRect, &destRect);
	Sleep(3);

	

}

int Scroll::base()
{
	
	int map[46] = { 0, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 0, 3, 3, 3, 3, 3, 1, 1, 1, 1, 1, 1, 1, 0, 3, 3, 3, 3, 3, 2, 2, 2, 2, 1, 1, 2, 3, 0, 0, 0, 3, 3, 3};
	int ybase;
	int i =1;
	if (xpos > 330)
		i = 0;
	else if (xpos <= 330 && xpos > 264)
		i = 1;
	else if (xpos <= 264 && xpos > 198)
		i = 2;
	else if (xpos <= 198 && xpos > 132)
		i = 3;
	else if (xpos <= 132 && xpos > 66)
		i = 4;
	else if (xpos <= 66 && xpos > 0)
		i = 5;
	else if (xpos <= 0 && xpos > -66)
		i = 6;
	else if (xpos <= -66 && xpos > -66 * 2)
		i = 7;
	else if (xpos <= -66 * 2 && xpos > -66 * 3)
		i = 8;
	else if (xpos <= -66 * 3 && xpos > -66 * 4)
		i = 9;
	else if (xpos <= -66 * 4 && xpos > -66 * 5)
		i = 10;
	else if (xpos <= -66 * 5 && xpos > -66 * 6)
		i = 11;
	else if (xpos <= -66 * 6 && xpos > -66 * 7)
		i = 12;
	else if (xpos <= -66 * 7 && xpos > -66 * 8)
		i = 13;
	else if (xpos <= -66 * 8 && xpos > -66 * 9)
		i = 14;
	else if (xpos <= -66 * 9 && xpos > -66 * 10)
		i = 15;
	else if (xpos <= -66 * 10 && xpos > -66 * 11)
		i = 16;
	else if (xpos <= -66 * 11 && xpos > -66 * 12)
		i = 17;
	else if (xpos <= -66 * 12 && xpos > -66 * 13)
		i = 18;
	else if (xpos <= -66 * 13 && xpos > -66 * 14)
		i = 19;
	else if (xpos <= -66 * 14 && xpos > -66 * 15)
		i = 20;
	else if (xpos <= -66 * 15 && xpos > -66 * 16)
		i = 21;
	else if (xpos <= -66 * 16 && xpos > -66 * 17)
		i = 22;
	else if (xpos <= -66 * 17 && xpos > -66 * 18)
		i = 23;
	else if (xpos <= -66 * 18 && xpos > -66 * 19)
		i = 24;
	else if (xpos <= -66 * 19 && xpos > -66 * 20)
		i = 25;
	else if (xpos <= -66 * 20 && xpos > -66 * 21)
		i = 26;
	else if (xpos <= -66 * 21 && xpos > -66 * 22)
		i = 27;
	else if (xpos <= -66 * 22 && xpos > -66 * 23)
		i = 28;
	else if (xpos <= -66 * 23 && xpos > -66 * 24)
		i = 29;
	else if (xpos <= -66 * 24 && xpos > -66 * 25)
		i = 30;
	else if (xpos <= -66 * 25 && xpos > -66 * 26)
		i = 31;
	else if (xpos <= -66 * 26 && xpos > -66 * 27)
		i = 32;
	else if (xpos <= -66 * 27 && xpos > -66 * 28)
		i = 33;
	else if (xpos <= -66 * 28 && xpos > -66 * 29)
		i = 34;
	else if (xpos <= -66 * 29 && xpos > -66 * 30)
		i = 35;
	else if (xpos <= -66 * 30 && xpos > -66 * 31)
		i = 36;
	else if (xpos <= -66 * 31 && xpos > -66 * 32)
		i = 37;
	else if (xpos <= -66 * 32 && xpos > -66 * 33)
		i = 38;
	else if (xpos <= -66 * 33 && xpos > -66 * 34)
		i = 39;
	else if (xpos <= -66 * 34 && xpos > -66 * 35)
		i = 40;
	else if (xpos <= -66 * 35 && xpos > -66 * 36)
		i = 41;
	else if (xpos <= -66 * 36 && xpos > -66 * 37)
		i = 42;
	else if (xpos <= -66 * 37 && xpos > -66 * 38)
		i = 43;
	else if (xpos <= -66 * 38 && xpos > -66 * 39)
		i = 44;
	else if (xpos <= -66 * 39 && xpos > -66 * 40)
		i = 45;
	ybase = 576 - map[i] * 66;
	return ybase;
}

Scroll::~Scroll()
{
}



