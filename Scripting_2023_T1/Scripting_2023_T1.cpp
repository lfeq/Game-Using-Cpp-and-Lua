#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "Player.h"
#include <string>
#include "ScriptingSystem.h"

extern "C" 
{
#include "Lua542/include/lua.h"
#include "Lua542/include/lauxlib.h"
#include "Lua542/include/lualib.h"
}

#ifdef _WIN32
#pragma comment(lib, "lua542/liblua54.a")
#endif // _WIN32

using namespace std;

int main()
{
    ScriptingSystem luaModule = ScriptingSystem();
    luaModule.TestDataBase();

    sf::RenderWindow window(sf::VideoMode(540, 540), "Scripting Game", sf::Style::Default);
    sf::Event m_event;
    Player player;

    player = Player();
    player.transform.position = sf::Vector2f(100, 100);
    player.sprite.setPosition(player.transform.position);

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
        window.draw(player.sprite);
        window.display();
    }
}


