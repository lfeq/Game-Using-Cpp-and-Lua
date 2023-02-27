#include "GameObject.h"


GameObject::GameObject()
{
	texture = new sf::Texture();
	texture->loadFromFile("T_player.png");
	sprite.setTexture(*texture);
	sprite.setPosition(transform.position);
}

void GameObject::Update() 
{

}

void GameObject::Render()
{
	
}