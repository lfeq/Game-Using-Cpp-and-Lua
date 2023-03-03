#pragma once
#include "GameObject.h"
#include "Sword.h"

class Player : public GameObject
{
public:
	Sword sword;

	Player(std::string path) : GameObject(path)
	{
		transform.position = sf::Vector2f(0, 0);
	}

	int Test() 
	{
		return 5;
	}
};