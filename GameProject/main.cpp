#include "game.h"


game *gameLoad = nullptr;


int main(int argc, char *argv[])
{
	gameLoad = new game();
	gameLoad->init("GameWindow", 800, 640, false);
	while (gameLoad->running())
	{
		gameLoad->handleEvents();
		gameLoad->update();
		gameLoad->render();
	}
	gameLoad->clean();
	return 0;
}