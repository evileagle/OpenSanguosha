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
        bool get_string(T index)
        {
            return get_value(index, lua_isstring);
        }

        template<typename T>
        bool get_integer(T index)
        {
            return get_value(index, lua_isnumber);
        }

        template<typename T>
        bool get_number(T index)
        {
            return get_value(index, lua_isnumber);
        }

        template<typename T>
        bool get_unsigned(T index)
        {
            return get_value(index, lua_isnumber);
        }

        template<typename T>
        bool get_table(T index)
        {
            return get_value(index, lua_istable);
        }

        template<typename T>
        bool get_function(T index)
        {
            return get_value(index, lua_isfunction);
        }

    private:
        template <typename T>
        bool get_value(lua_Unsigned index, T& check);
        template <typename T>
        bool get_value(const char* szName, T& check);
        bool init(lua_State* state, int index);
        lua_State* m_state;
        int m_index;

    };
}

#endif