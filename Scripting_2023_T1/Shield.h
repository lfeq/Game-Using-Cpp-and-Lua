#pragma once
#include "GameObject.h"

class Shield : public GameObject
{
public:
	Shield() {}

	Shield(std::string path) : GameObject(path)
	{
		transform.position = sf::Vector2f(350, 350);
	}
};

