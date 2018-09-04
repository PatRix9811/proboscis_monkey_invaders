#include "game.h"

void cGame::startMenuDraw(RenderWindow& Window)
{
	if (!this->font.loadFromFile("res\\arialbi.ttf"))
	{
		std::cout << "File not load" << std::endl;
	}

	this->Tstart.setFont(this->font);
	this->Tstart.setString("START");
	this->Tstart.setFillColor(Color::Green);
	this->Tstart.setPosition(Window.getSize().x/2-50,Window.getSize().y*1/5);

	this->Texit.setFont(this->font);
	this->Texit.setString("EXIT");
	this->Texit.setFillColor(Color::Red);
	this->Texit.setPosition(Window.getSize().x / 2-50, Window.getSize().y*3/5);

	while(true)
	{
		Event event;
		while (Window.pollEvent(event))
		{
			if (event.type == Event::MouseButtonPressed)
			{
				if (Mouse::getPosition(Window).x >= Window.getSize().x / 2 - 50 && Mouse::getPosition(Window).x <= Window.getSize().x / 2 + 50)
				{
					if (Mouse::getPosition(Window).y >= Window.getSize().y * 1 / 5 && Mouse::getPosition(Window).y <= Window.getSize().y * 1 / 5 + 30)
					{
						this->gamestate = (this->gamestate == GS_PAUSED ? GS_RESUME : GS_STARTED);
						Window.setMouseCursorVisible(false);
						this->runGame(Window);
					}

					if (Mouse::getPosition(Window).y >= Window.getSize().y * 3 / 5 && Mouse::getPosition(Window).y <= Window.getSize().y * 3 / 5 + 30)
					{
						Window.close();
						return;
					}
				}

			}

			if (event.type == Event::Closed)
			{
				Window.close();
				return;
			}
		}

		Window.clear();
		Window.draw(this->bg);
		Window.draw(this->Tstart);
		Window.draw(this->Texit);
		Window.display();
	}
}

