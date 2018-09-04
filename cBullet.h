#ifndef cBullet_h
#define cBullet_h

#include<SFML\Graphics.hpp>
#include<SFML\Window.hpp>
#include<SFML\System.hpp>

using namespace sf;

class cBullet : public Drawable
{
public:
	cBullet()=delete;
	~cBullet()=default;
	cBullet(Vector2i position);
	void move();
	float Bottom();
	float Left();
	float Right();
	float Top();
	void setDestroy();
	bool isDestroyed();

private:
	void draw(RenderTarget& target, RenderStates states)const override;
	CircleShape shape;
	Vector2f velocity;
	Vector2i position;
	bool destroyed = { false };
};

#endif