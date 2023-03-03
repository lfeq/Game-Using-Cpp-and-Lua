#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "Player.h"
#include <string>
#include "ScriptingSystem.h"
#include <list>

int main()
{
    std::list<GameObject> gameObjectList;
    gameObjectList = std::list<GameObject>();

    ScriptingSystem luaModule = ScriptingSystem();
    PlayerData data = luaModule.TestDataBase();

    Player player = Player("T_Player.png");

    gameObjectList.push_back(player);

    player.sword = Sword(data.path_sword);

    gameObjectList.push_back(player.sword);

    sf::RenderWindow window(sf::VideoMode(540, 540), "Scripting Game", sf::Style::Default);
    sf::Event m_event;

    //ciclo principal
    while (window.isOpen())
    {
        //Detectar input
        while (window.pollEvent(m_event))
        {
            switch (m_event.type) 
            {
            case sf::Event::Closed:
                window.close();
                break;

            case sf::Event::KeyPressed:
                if (m_event.key.code == sf::Keyboard::Escape)
                    window.close();
                break;

            default:
                break;
            }
        }

        window.clear(sf::Color::Green);

        std::list<GameObject>::iterator it;

        for (it = gameObjectList.begin(); it != gameObjectList.end(); it++)
            window.draw(it->sprite);

        window.display();
    }
}


