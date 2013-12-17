#ifndef _LUA_PLUS_TABLE_H_
#define _LUA_PLUS_TABLE_H_

#include <string>
#include <functional>
#include "utility.h"

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
        inline bool get_string(T index)
        {
            return get_value(index, ptr_fun(lua_isstring));
        }

        template<typename T>
        inline bool get_integer(T index)
        {
            return get_value(index, ptr_fun(lua_isnumber));
        }

        template<typename T>
        inline bool get_number(T index)
        {
            return get_value(index, ptr_fun(lua_isnumber));
        }

        template<typename T>
        inline bool get_unsigned(T index)
        {
            return get_value(index, ptr_fun(lua_isnumber));
        }

        template<typename T>
        inline bool get_table(T index)
        {
            return get_value(index, ptr_fun(luau_istable));
        }

        template<typename T>
        inline bool get_function(T index)
        {
            return get_value(index, ptr_fun(luau_isfunction));
        }

        template<typename T>
        inline bool get_userdata(T index)
        {
            return get_value(index, ptr_fun(lua_isuserdata));
        }

        template<typename T>
        inline bool get_any(T index)
        {
            return get_value(index, not2(ptr_fun(luau_isnoneornil)));
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

    template <typename T>
    bool table::get_value( lua_Unsigned index, T& check )
    {
        assert(is_valid());
        if (!is_valid())
        {
            return false;
        }
        lua_pushunsigned(m_state, index);
        lua_gettable(m_state, m_index);
        if (!check(m_state, -1))
        {
            lua_pop(m_state, 1);
            return false;
        }
        return true;
    }    

    template <typename T>
    bool table::get_value( const char* szName, T& check )
    {
        assert(is_valid());
        if (!is_valid())
        {
            return false;
        }
        lua_getfield(m_state, m_index, szName);
        if (!check(m_state, -1))
        {
            lua_pop(m_state, 1);
            return false;
        }
        return true;
    }
}

#endif