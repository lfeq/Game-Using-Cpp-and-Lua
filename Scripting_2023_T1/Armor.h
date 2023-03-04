#pragma once
#include "GameObject.h"

class Armor : public GameObject
{
public:
	Armor() {}

	Armor(std::string path) : GameObject(path)
	{
		transform.position = sf::Vector2f(250, 350);
	}
};

