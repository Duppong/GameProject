#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

class game
{
public:
	game(const char * title, int width, int height, bool fullscreen);
	//title of window, width, height px
	void handleEvents();
	void update();
	bool running() { return isRunning; }
	void render();
	void clean();

	static SDL_Renderer *renderer;
private:
	bool isRunning = false;
	SDL_Window *window;
};

