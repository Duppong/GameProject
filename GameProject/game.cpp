#include "game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Map.h"
#include "fallingObject.h"
#include <random>
#include "constants.h"
#include <iostream>
using namespace std;

GameObject* player;
fallingObject* block;
fallingObject* blockArray [maxBlocks];
Map* map;

SDL_Renderer* game::renderer = nullptr;
SDL_Rect collisionBox;
//SDL_Rect& camera;
int randomNumber = 5;
int blockCount = 0;
int spawnPoint;

game::game()
{
}


game::~game()
{
}

void game::init(const char* title, int width, int height, bool fullscreen)
{
	int flags = 0;

	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		}

		isRunning = true;
	}
	player = new GameObject("assets/player.png",0,545);
	//map = new Map();
	//block = new fallingObject("assets/platform.png", 0, 100);

}
void game::checkCollision()
{
	if (blockCount != 0)
	{
		for (int i = 0; i < blockCount; i++)
		{
			if ( player->getX() >= blockArray[i]->getXBox()-64 && player->getX() <= blockArray[i]->getXBox()+64
				&& player->getY() >= blockArray[i]->getYBox() -64&& player->getY() <= blockArray[i]->getYBox() + 64)
			{
				blockArray[i]->~fallingObject();
				cout << "X axis collision block " + i << blockArray[i]->getXBox() << endl;
				cout << "player" << player->getX() << endl;
			}
		}
	}
}
void spawnBlocks()
{

	if (blockCount < maxBlocks)
	{
		spawnPoint = rand() % screenWidth;
		blockArray[blockCount] = new fallingObject("assets/platform.png", 250, 100);
		blockCount += 1;
	}

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
		player->HandleEvent(event);
		//checkCollision();
		break;
	}

}

void game::update()
{
	spawnBlocks();
	if (blockCount != 0)
	{
		for (int i = 0; i < blockCount; i++)
		{
			blockArray[i]->Update();
		}
	}
	collisionBox.x = 150;
	collisionBox.y = 25;
	collisionBox.w = 32;
	collisionBox.h = 32;
	player->Update(collisionBox);
	//map->LoadMap();
}

void game::render()
{
	SDL_RenderClear(renderer);
	//map->DrawMap();
	if (blockCount != 0)
	{
		for (int i = 0; i < blockCount; i++)
		{
			blockArray[i]->Render();
		}
	}
	player->Render();
	SDL_RenderPresent(renderer);
}

void game::clean()
{
	
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}