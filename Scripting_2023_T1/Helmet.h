#pragma once
#include "GameObject.h"

class Helmet : public GameObject
{
public:
	Helmet() {}

	Helmet(std::string path) : GameObject(path)
	{
		transform.position = sf::Vector2f(250, 150);
	}
};

