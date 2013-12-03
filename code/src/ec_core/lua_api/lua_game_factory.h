#ifndef _EASYCARD_LUAAPI_GAMEFACTORY_H_
#define _EASYCARD_LUAAPI_GAMEFACTORY_H_

struct lua_State;
namespace EasyCard
{
    typedef struct LuaGameFactory
    {

    }*PLuaGameFactory;

    bool CreateFactory(lua_State* lua);
}
#endif