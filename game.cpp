#include "game.h"
#include <algorithm>

using namespace sf;

template<class T1, class T2> bool cGame::colisionTest(T1& A, T2& B)
{
	return A.Right() >= B.Left() && A.Left() <= B.Right() && A.Top() <= B.Bottom() && A.Bottom() >= B.Top();
}

cGame::cGame()
{
	this->gamestate = GS_NOSTARTED;
	this->bgImage.loadFromFile("img\\space.jpg");
	this->enemyImage.loadFromFile("img\\nosacz_gra.png");
	this->playerImage.loadFromFile("img\\ship.png");
	this->bg.setTexture(bgImage);
	this->player.setTexture(this->playerImage);
}

void cGame::runGame(RenderWindow& Window)
{
	if (this->gamestate == GS_STARTED)
	{
		this->setEnemies(this->enemiesList, 10.f, 10.f);
	}

	Mouse::setPosition({ 300,500 }, Window);
	while (true)
	{
		Event event;
		while (Window.pollEvent(event))
		{
			switch (event.type)
			{
				case Event::Closed: 
				{
					Window.close(); 
					return; 
				}break;

				case Event::MouseMoved:
				{
					this->playerMove(Window);
					this->playerColision();

					if (this->gamestate == GS_LOS)
					{
						Window.setMouseCursorVisible(true);
						return;
					}
				} break;

				case Event::MouseButtonPressed:
				{
					this->playerShot();
				}break;

				case Event::KeyPressed:
				{
					if (Keyboard::isKeyPressed(Keyboard::Escape))
					{
						Window.setMouseCursorVisible(true);
						this->gamestate = GS_PAUSED;
						return;
					}
				}
			}
		}

		this->bulletControl();
		Window.clear();
		Window.draw(bg);
		this->bulletDraw(Window);
		this->enemiesDraw(Window);
		this->playerDraw(Window);
		Window.display();
	}

}

void cGame::setEnemies(std::vector<cEnemies>& enemiesList, float x, float y)
{
	enemiesList.clear();

	for (int i = 0; i<8; i++)
		for (int j = 0; j<3; j++)
			enemiesList.push_back(cEnemies({ 70.f + x + (i * 63),50.f + y + (j * 63),100}));

	for (auto& enemy : this->enemiesList)
		enemy.setTexture(this->enemyImage);

}

void cGame::bulletControl()
{
	if (!this->bulletList.empty())
	{
		for (auto& bullet : this->bulletList)
		{
			bullet.move();

			if (bullet.Top() < 0)
			{
				bullet.setDestroy();
				continue;
			}

			for (auto& enemy : this->enemiesList)
				if (this->colisionTest(bullet, enemy))
				{
					bullet.setDestroy();

					if (enemy.hp()>0)
					{
						enemy.hit();
						continue;
					}
					else
					{
						enemy.setDestroy();
						continue;
					}

				}
		}

		auto iterator = remove_if(begin(this->bulletList), end(this->bulletList), [](cBullet& bullet) {return bullet.isDestroyed(); });
		this->bulletList.erase(iterator, end(this->bulletList));

		auto iterator2 = remove_if(begin(this->enemiesList), end(this->enemiesList), [](cEnemies& enemy) {return enemy.isDestroyed(); });
		this->enemiesList.erase(iterator2, end(this->enemiesList));
	}
}

void cGame::bulletDraw(RenderWindow& Window)
{
	if (!this->bulletList.empty())
		for (auto& bullet : this->bulletList)
			Window.draw(bullet);
}

void cGame::enemiesDraw(RenderWindow& Window)
{
	if (!this->enemiesList.empty())
	{
		for (auto& enemy : this->enemiesList)
		{
			if (!enemy.isDestroyed())
			{
				enemy.move(Window);
				Window.draw(enemy);
			}
		}
	}
			
}

void cGame::playerDraw(RenderWindow& Window)
{
	Window.draw(player);
}

void cGame::playerMove(RenderWindow& Window)
{
		Vector2i pos = { Mouse::getPosition().x - Window.getPosition().x - 10, Mouse::getPosition().y - Window.getPosition().y - 25 };
		if (pos.y <= Window.getPosition().x + Window.getSize().x)
			player.move(pos);
}

void cGame::playerShot()
{
	if (Mouse::isButtonPressed(Mouse::Button::Left))
		this->bulletList.push_back(this->player.shot());
}

void cGame::playerColision()
{
	for(auto& enemy: this->enemiesList)
		if (colisionTest(this->player, enemy))
		{
			this->gamestate = GS_LOS;
			return;
		}

	return; 
}

GAMESTATE cGame::getGamestate()
{
	return this->gamestate;
}
