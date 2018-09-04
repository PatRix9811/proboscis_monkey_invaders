#include "cEnemies.h"
#include <cmath>

cEnemies::cEnemies(float x,float y ,int health)
{
	this->health = health;
	this->position = { x,y };
	this->shape.setPosition(this->position);
	this->shape.setOrigin(this->radius,this->radius);
}

void cEnemies::setTexture(Texture texture)
{
	this->texture = texture;
	this->shape.setTexture(this->texture,false);
	this->shape.setTextureRect(IntRect(0,0,60,60));
}

void cEnemies::draw(RenderTarget& target, RenderStates state)const
{
	target.draw(this->shape, state);
}

void cEnemies::setDestroy()
{
	this->destroyed = true;
}

bool cEnemies::isDestroyed()
{
	return this->destroyed;
}

float cEnemies::Left()
{
	return this->shape.getPosition().x - this->radius;
}

float cEnemies::Right()
{
	return this->shape.getPosition().x + this->radius;
}

float cEnemies::Top()
{
	return this->shape.getPosition().y - this->radius;
}

float cEnemies::Bottom()
{
	return this->shape.getPosition().y + this->radius;
}

int cEnemies::hp()
{
	return this->health;
}

void cEnemies::hit()
{
	this->health -= 20;
}

void cEnemies::move(RenderWindow& Window)
{
	if (this->Left() <= 0 || this->Right() >= Window.getSize().x)
		this->move_way*=-1;
	float x = this->shape.getPosition().x + this->move_way;
	float y = this->shape.getPosition().y - 0.5*sin(x/15);
	this->shape.setPosition(x,y);
}
