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
    std::string fileName;
    int index;
    std::cout << "Lua file name: " << std::endl;
    std::cin >> fileName;

    std::cout << "Character index you want to load (1, 2, 3) " << std::endl;
    std::cin >> index;
    index--;

    std::list<GameObject> gameObjectList;
    gameObjectList = std::list<GameObject>();

    ScriptingSystem luaModule = ScriptingSystem();
    PlayerData data = luaModule.TestDataBase(fileName, index);

    //Crear player
    Player player = Player("T_Player.png");
    player.sprite.setPosition(player.transform.position);
    gameObjectList.push_back(player);

    //Crear espada
    player.sword = Sword(data.path_sword);
    player.sword.sprite.setPosition(player.sword.transform.position);
    gameObjectList.push_back(player.sword);

    //Crear armadura
    player.armor = Armor(data.path_armor);
    player.armor.sprite.setPosition(player.armor.transform.position);
    gameObjectList.push_back(player.armor);

    //Crear casco
    player.helmet = Helmet(data.path_helmet);
    player.helmet.sprite.setPosition(player.helmet.transform.position);
    gameObjectList.push_back(player.helmet);

    //Crear escudo
    player.shield = Shield(data.path_shield);
    player.shield.sprite.setPosition(player.shield.transform.position);
    gameObjectList.push_back(player.shield);

    sf::RenderWindow window(sf::VideoMode(500, 500), "Scripting Game", sf::Style::Default);
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


