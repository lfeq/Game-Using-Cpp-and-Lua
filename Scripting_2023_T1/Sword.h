#pragma once
#include "GameObject.h"

class Sword : public GameObject
{
public:
	Sword() {}

	Sword(std::string path) : GameObject(path) 
	{
		transform.position = sf::Vector2f(150, 350);
	}
};

