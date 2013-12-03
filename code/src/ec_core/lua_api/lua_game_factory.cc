#include "lua_game_factory.h"
#include "lua_plus/stack_frame.h"

namespace EasyCard
{
    int load_config(lua_State *L)
    {

    }

    bool CreateFactory( lua_State* lua )
    {
        stack_frame sf(lua);
        lua_pushnil(lua);
        lua_pushcclosure(lua, load_config, 1);
        lua_call(lua, 0, 1);
        return lua_toboolean(lua, -1);
    }

}