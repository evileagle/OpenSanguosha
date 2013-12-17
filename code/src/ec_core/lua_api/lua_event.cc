#include "lua_event.h"
#include <assert.h>
#include "ec_common/type_def.h"
#include "lua_loader/main_loader.h"
#include "lua/lua.hpp"

namespace EasyCard{
namespace LuaApi{

using namespace LuaLoader;
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
    bool success = CallOnEvent(lua);
    lua_pushboolean(lua, success);
    return 1;
}

}
}
