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

class ScriptingSystem
{
public:
    lua_State* L;

	ScriptingSystem()
	{
        L = luaL_newstate();
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

