#include "game.h"
#include "constants.h"


game *gameLoad = nullptr;


int main(int argc, char *argv[])
{
	gameLoad = new game();
	gameLoad->init("GameWindow", screenWidth, screenHeight, false);
	while (gameLoad->running())
	{
		gameLoad->handleEvents();
		gameLoad->update();
		gameLoad->checkCollision();
		gameLoad->render();
	}
	gameLoad->clean();
	return 0;
}