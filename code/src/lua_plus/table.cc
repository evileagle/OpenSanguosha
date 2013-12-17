#include "lua_plus/table.h"
#include <assert.h>

namespace LuaPlus
{
    table::table()
        : m_state(NULL)
        , m_index(0)
    {

    }

    table::table( lua_State* state, int index )
    {
        init(state, index);
    }

    table::~table()
    {
        m_index = 0;
        m_state = NULL;
    }

    bool table::init( lua_State* state, int index )
    {
        if (!lua_istable(state, index))
        {
            return false;
        }
        m_state = state;
        m_index = lua_absindex( state, index);
        return true;
    }

    bool table::is_valid()
    {
        return m_state != NULL && m_index != 0;
    }

    lua_Unsigned table::get_len()
    {
        lua_len(m_state, m_index);
        return lua_tounsigned(m_state, -1);
    }

    table table::regist_table( lua_State* lua )
    {
        return table(lua, LUA_REGISTRYINDEX);
    }

}