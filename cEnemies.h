#ifndef cEnemies_h
#define cEnemies_h

#include<SFML\Graphics.hpp>
#include<SFML\Window.hpp>
#include<SFML\System.hpp>

using namespace sf;

class cEnemies : public Drawable
{
public:
	cEnemies()=delete;
	~cEnemies() = default;
	cEnemies(float x,float y,int health);
	void setTexture(Texture texture);
	void setDestroy();
	bool isDestroyed();
	float Left();
	float Right();
	float Top();
	float Bottom();
	int hp();
	void hit();
	void move(RenderWindow& Window);
		
private:
	void draw(RenderTarget& target, RenderStates states)const override;
	int move_way = 1;
	Texture texture;
	Sprite shape;
	Vector2f position;
	float radius = {30.f};
	int health;
	bool destroyed = { false };
};

#endif