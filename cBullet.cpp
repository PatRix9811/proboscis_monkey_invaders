#include "cBullet.h"

using namespace sf;



cBullet::cBullet(Vector2i position)
{
	this->position = position;
	this->velocity = {0.f,15.f};
	this->shape.setPosition(Vector2f(this->position));
	this->shape.setFillColor(Color::Yellow);
	this->shape.setRadius(1.f);
}

void cBullet::draw(RenderTarget& target, RenderStates states)const
{
	target.draw(this->shape, states);
}

void cBullet::move()
{
	position.y = position.y - velocity.y;
	this->shape.setPosition(Vector2f(position));
}

float cBullet::Top()
{
	return this->position.y;
}

float cBullet::Right()
{
	return this->position.x;
}

float cBullet::Bottom()
{
	return this->Top();
}

float cBullet::Left()
{
	return this->Right();
}


void cBullet::setDestroy()
{
	this->destroyed = true;
}

bool cBullet::isDestroyed()
{
	return this->destroyed;
}
