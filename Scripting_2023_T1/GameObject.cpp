#include "GameObject.h"


GameObject::GameObject(std::string path)
{
	texture = new sf::Texture();

	try
	{
		if (!texture->loadFromFile(path))
			throw(1);
	}
	catch (int errorCode)
	{
		std::cout << "Error loading texture: " << errorCode << std::endl;
		texture->loadFromFile("T_Player.png");
	}

	sprite.setTexture(*texture);
	sprite.setPosition(transform.position);
}

void GameObject::Update() 
{

}

void GameObject::Render()
{
	
}