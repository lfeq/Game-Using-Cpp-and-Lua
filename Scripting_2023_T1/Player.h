#pragma once
#include "GameObject.h"
#include "Sword.h"
#include "Helmet.h"
#include "Armor.h"
#include "Shield.h"

class Player : public GameObject
{
public:
	Sword sword;
	Helmet helmet;
	Armor armor;
	Shield shield;

	Player(std::string path) : GameObject(path)
	{
		transform.position = sf::Vector2f(250, 250);
	}

	int Test() 
	{
		return 5;
	}
};