#include "game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Map.h"
#include "Scroll.h"

GameObject* player;
Map* map;
Scroll* background;

SDL_Renderer* game::renderer = nullptr;


game::game(const char* title, int width, int height, bool fullscreen)
{
	int flags = 0;

	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, flags);
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		}

		isRunning = true;
	}
	background = new Scroll("assets/Map.png", 0, 100);
	player = new GameObject("assets/Dude2.png",264 ,510, background);
	
	map = new Map();
}


void game::handleEvents()
{
	SDL_Event event;
	
	SDL_PollEvent(&event);

	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		background->HandleEvent(event);
		player->HandleEvent(event);
		break;
	}
}

void game::update()
{
	background->Update();
	player->Update();
	//map->LoadMap();
}

void game::render()
{
	SDL_RenderClear(renderer);
	map->DrawMap();
	background->Render();
	player->Render();
	SDL_RenderPresent(renderer);
}

void game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}