#include "game.h"

using namespace sf;

int main()
{
	RenderWindow Window(VideoMode(600, 600), "Cos SFML");
	Window.setFramerateLimit(60);

	cGame Game = cGame();

	while (Window.isOpen())
	{
		
		switch(Game.getGamestate())
		{
			case GS_STARTED:
			case  GS_RESUME:
			{
				Game.runGame(Window);
			}break;

			case GS_NOSTARTED:
			case GS_PAUSED:
			case GS_LOS:
			{
				Game.startMenuDraw(Window);
			}break;
		}
	}

	return 0;
}


