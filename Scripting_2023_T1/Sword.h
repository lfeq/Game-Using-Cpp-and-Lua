#pragma once
#include "GameObject.h"

class Sword : public GameObject
{
public:
	Sword() {}

	Sword(std::string path) :GameObject(path) 
	{
	
	}
};

