#ifndef game_h
#define game_h

#include "cPlayer.h"
#include "cBullet.h"
#include "cEnemies.h"
#include <vector>
#include <iostream>

enum GAMESTATE {GS_NOSTARTED,GS_PAUSED,GS_RESUME,GS_STARTED,GS_WIN,GS_LOS};

class cGame
{
	cPlayer player = cPlayer(300.f, 500.f);
	std::vector<cBullet> bulletList;
	std::vector<cEnemies> enemiesList;
	GAMESTATE gamestate;
	Texture bgImage,enemyImage,playerImage;
	Sprite bg;

public:
	template<class T1, class T2> bool colisionTest(T1& A, T2& B);
	cGame();
	~cGame() = default;
	void runGame(RenderWindow& Window);
	void startMenuDraw(RenderWindow& Window);
	void setEnemies(std::vector<cEnemies>& enemiesList, float x, float y);
	void bulletControl();
	void bulletDraw(RenderWindow& Window);
	void enemiesDraw(RenderWindow& Window);
	void playerDraw(RenderWindow& Window);
	void playerMove(RenderWindow& Window);
	void playerShot();
	void playerColision();
	GAMESTATE getGamestate();
	Font font;
	Text Tstart, Texit;
};

#endif