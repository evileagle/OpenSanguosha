#ifndef _LUA_PLUS_TABLE_H_
#define _LUA_PLUS_TABLE_H_

#include <string>
#include "lua/lua.hpp"

namespace LuaPlus
{
    using namespace std;
    class table
    {
    public:
        table();
        table(lua_State* state, int index);
        ~table();

        static table regist_table(lua_State* lua);

        bool is_valid();
        lua_Unsigned get_len();

        template<typename T>
        bool get_value(T index, string& value)
        {
            if (!get_value(index))
            {
                return false;
            }
            if (!lua_isstring(m_state, -1))
            {
                return false;
            }
            value = lua_tostring(m_state, -1);
            return true;
        }

        template<typename T>
        bool get_value(T index, lua_Integer& value)
        {
            if (!get_value(index))
            {
                return false;
            }
            if (!lua_isnumber(m_state, -1))
            {
                return false;
            }
            value = lua_tointeger(m_state, -1);
            return true;
        }

        template<typename T>
        bool get_value(T index, lua_Number& value)
        {
            if (!get_value(index))
            {
                return false;
            }
            if (!lua_isnumber(m_state, -1))
            {
                return false;
            }
            value = lua_tonumber(m_state, -1);
            return true;
        }

        template<typename T>
        bool get_value(T index, lua_Unsigned& value)
        {
            if (!get_value(index))
            {
                return false;
            }
            if (!lua_isnumber(m_state, -1))
            {
                return false;
            }
            value = lua_tounsigned(m_state, -1);
            return true;
        }

        template<typename T>
        bool get_value(T index, table& value)
        {
            if (!get_value(index))
            {
                return false;
            }
            return value.init(m_state, -1);
        }

    private:
        bool get_value(lua_Unsigned index);
        bool get_value(const char* szName);
        bool init(lua_State* state, int index);
        lua_State* m_state;
        int m_index;

    };
}

#endif