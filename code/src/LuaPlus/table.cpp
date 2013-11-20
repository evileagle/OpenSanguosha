#include "LuaPlus/table.h"

namespace LuaPlus
{


    table::table()
        : m_state(nullptr)
        , m_index(0)
    {

    }

    table::table( lua_State* state, int index )
    {
        init(state, index);
    }

    bool table::init( lua_State* state, int index )
    {
        m_state = state;
        m_index = lua_absindex( state, index);
    }

}