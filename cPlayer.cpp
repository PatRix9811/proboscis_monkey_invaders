#include "cPlayer.h"
using namespace sf;

cPlayer::cPlayer(float x, float y)
{
	this->position = { int(x),int(y) };
	this->size = { 50.f,50.f };
	this->origin = { 25.f, 25.f };
	this->shape.setPosition(Vector2f(this->position));
	this->shape.setSize(this->size);
	this->shape.setOrigin(this->origin);
}

void cPlayer::setTexture(Texture texture)
{
	this->texture = texture;
	this->shape.setTexture(&this->texture, false);
	this->shape.setTextureRect(IntRect{ 0,0,50,50 });
}

void cPlayer::draw(RenderTarget& target,RenderStates states) const
{
	target.draw(this->shape, states);
}

void cPlayer::move(Vector2i position)
{
	this->position = {position};
	this->shape.setPosition(Vector2f(this->position));
}

cBullet cPlayer::shot()
{
	return cBullet({ this->position.x-6,this->position.y });
}

float cPlayer::Left()
{
	return this->shape.getPosition().x - this->size.x / 2;
}

float cPlayer::Right()
{
	return this->shape.getPosition().x + this->size.x / 2;
}

float cPlayer::Top()
{
	return this->shape.getPosition().y - this->size.y / 2;
}

float cPlayer::Bottom()
{
	return this->shape.getPosition().y + this->size.y / 2;
}
