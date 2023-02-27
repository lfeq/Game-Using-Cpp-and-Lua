#pragma once
#include "SFML/System.hpp";
#include "SFML/Graphics.hpp";

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

	GameObject();

	void Update();
	void Render();
	virtual int Test() {
		return 0;
	}
};

