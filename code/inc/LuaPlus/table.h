#ifndef _LUA_PLUS_TABLE_H_
#define _LUA_PLUS_TABLE_H_

#include "lua/lua.h"
#include "lua/luaconf.h"
#include <string>

using namespace std;

namespace LuaPlus
{
    class table
    {
    public:
        table();
        table(lua_State* state, int index);

        bool is_valid();
        lua_Unsigned get_len();

        bool get_value(lua_Unsigned index, string& value);
        bool get_value(lua_Unsigned index, lua_Integer& value);
        bool get_value(lua_Unsigned index, lua_Number& value);
        bool get_value(lua_Unsigned index, lua_Unsigned& value);
        bool get_value(lua_Unsigned index, table& value);

        bool get_value(const char* szName, string& value);
        bool get_value(const char* szName, lua_Integer& value);
        bool get_value(const char* szName, lua_Number& value);
        bool get_value(const char* szName, lua_Unsigned& value);
        bool get_value(const char* szName, table& value);

    private:
        bool init(lua_State* state, int index);
        lua_State* m_state;
        int m_index;

    };
}

#endif