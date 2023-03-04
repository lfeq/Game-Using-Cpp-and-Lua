#pragma once
#include <string>
#include <iostream>


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

struct PlayerData
{
    PlayerData() {}
    string path_sword;
    string path_helmet;
    string path_armor;
    string path_shield;
};

class ScriptingSystem
{
public:
    lua_State* L;

	ScriptingSystem()
	{
        L = luaL_newstate();
	}

    void TestFunction() 
    {
        //Leer script 
        if (IsValidLuaCommand(L, luaL_dofile(L, "LuaTest.lua")))
        {
            lua_getglobal(L, "DoStuff");
            if (lua_isfunction(L, -1))
            {
                lua_pushnumber(L, 50);
                lua_pushnumber(L, 100);
                if (IsValidLuaCommand(L, lua_pcall(L, 2, 1, 0)))
                {
                    int x = lua_tonumber(L, -1);
                    std::cout << x << std::endl;
                }
            }
        }
    }

    PlayerData TestDataBase(string fileName, int index)
    {
        PlayerData data = PlayerData();


        if (IsValidLuaCommand(L, luaL_dofile(L, fileName.c_str())))
        {
            lua_getglobal(L, "GetCharacter");
            if (lua_isfunction(L, -1))
            {
                lua_pushnumber(L, index);

                if (IsValidLuaCommand(L, lua_pcall(L, 1, 1, 0)))
                {
                    if (lua_istable(L, -1))
                    {
                        lua_pushstring(L, "Sword");
                        lua_gettable(L, -2);
                        data.path_sword = lua_tostring(L, -1);
                        lua_pop(L, 1);
                    }

                    if (lua_istable(L, -1))
                    {
                        lua_pushstring(L, "Helmet");
                        lua_gettable(L, -2);
                        data.path_helmet = lua_tostring(L, -1);
                        lua_pop(L, 1);
                    }

                    if (lua_istable(L, -1))
                    {
                        lua_pushstring(L, "Armor");
                        lua_gettable(L, -2);
                        data.path_armor = lua_tostring(L, -1);
                        lua_pop(L, 1);
                    }

                    if (lua_istable(L, -1))
                    {
                        lua_pushstring(L, "Shield");
                        lua_gettable(L, -2);
                        data.path_shield = lua_tostring(L, -1);
                        lua_pop(L, 1);
                    }
                }
            }
        }

        return data;
    }

    void GetLuaNumber()
    {
        string codeLine = "x = 4 + 2";

        if (IsValidLuaCommand(L, luaL_dofile(L, "LuaTest.lua")))
        {
            lua_getglobal(L, "x");
            if (lua_isnumber(L, -1))
            {
                int x_in_cpp = lua_tonumber(L, -1);
                cout << x_in_cpp << endl;
            }
        }
    }

    bool IsValidLuaCommand(lua_State* L, int command)
    {
        if (command != LUA_OK)
        {
            string errorMessage = lua_tostring(L, -1);
            cout << errorMessage << endl;
            return false;
        }

        return true;
    }

    void TestTable()
    {
        if (IsValidLuaCommand(L, luaL_dofile(L, "LuaTest.lua")))
        {
            lua_getglobal(L, "Weapon");
            if (lua_istable(L, -1))
            {
                lua_pushstring(L, "Damage");
                lua_gettable(L, -2);
                int damage = lua_tonumber(L, -1);
                lua_pop(L, 1);
                cout << damage << endl;
            }
        }
    }

    void Close()
    {
        lua_close(L);
    }
};

