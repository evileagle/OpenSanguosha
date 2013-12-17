#ifndef _LUA_PLUS_UTILITY_H_
#define _LUA_PLUS_UTILITY_H_

#include "lua/lua.hpp"


namespace LuaPlus{

    inline int luau_isfunction(lua_State* lua, int idx)
    {
        return lua_isfunction(lua, idx) || lua_iscfunction(lua, idx);
    }

    inline int luau_istable(lua_State* lua, int idx)
    {
        return lua_istable(lua, idx);
    }

    inline int luau_isnoneornil(lua_State* lua, int idx)
    {
        return lua_isnoneornil(lua, idx);
    }
}
#endif