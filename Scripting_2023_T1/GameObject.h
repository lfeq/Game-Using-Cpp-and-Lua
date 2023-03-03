#pragma once
#include "SFML/System.hpp";
#include "SFML/Graphics.hpp";
#include <iostream>;

struct Transform
{
	sf::Vector2f position;
	float rotation;
	sf::Vector2f scale;
};

class GameObject
{
public:
	sf::Texture* texture;
	Transform transform;
	sf::Sprite sprite;

	GameObject() {}
	GameObject(std::string path);

	void Update();
	void Render();
	int Test() 
	{
		return 0;
	}
};

