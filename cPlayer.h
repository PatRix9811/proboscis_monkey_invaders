#ifndef cPlayer_h
#define cPlayer_h

#include<SFML\Graphics.hpp>
#include<SFML\Window.hpp>
#include<SFML\System.hpp>
#include "cBullet.h"

using namespace sf;

class cPlayer : public Drawable
{
public:
	cPlayer() = delete;
	cPlayer(float x, float y);
	~cPlayer() = default;

	void move(Vector2i position);
	float Left();
	float Right();
	float Top();
	float Bottom();
	cBullet shot();
	void setTexture(Texture texture);

private:
	void draw(RenderTarget& target, RenderStates states)const override;
	Texture texture;
	RectangleShape shape;
	Vector2i position;
	Vector2f size;
	Vector2f origin;
};

#endif