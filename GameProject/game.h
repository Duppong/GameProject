#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

class game
{
public:
	game();
	~game();
	//title of window, width, height px
	void init(const char* title, int width, int height, bool fullscreen);
	void handleEvents();
	void checkCollision();
	void update();
	bool running() { return isRunning; }
	void render();
	void clean();

	static SDL_Renderer *renderer;
private:
	bool isRunning = false;
	SDL_Window *window;
};

