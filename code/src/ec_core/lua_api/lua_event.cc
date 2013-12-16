#include "lua_event.h"
#include <assert.h>

namespace EasyCard{
namespace LuaApi{

int CreateEvent( lua_State* lua )
{
    assert(lua != NULL);
    assert(lua_isstring(lua, 1));
    assert(lua_istable(lua, 2));
    lua_newtable(lua);
    lua_pushvalue(lua, 1);
    lua_setfield(lua, -2 ,"name");
    lua_pushvalue(lua, 2);
    lua_setfield(lua, -2, "data");

}

}
}
