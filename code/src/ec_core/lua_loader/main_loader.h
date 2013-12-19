#ifndef _EASY_CARD_LUA_LOADER_MAIN_H_
#define _EASY_CARD_LUA_LOADER_MAIN_H_

struct lua_State;
namespace EasyCard{
namespace Core{

class GameConfig;

namespace LuaLoader{

    bool LoadMain(lua_State* lua);
    bool CallInit(lua_State* lua, GameConfig& config);
    bool CallStart(lua_State* lua);
    bool CallOnEvent(lua_State* lua);
    bool GetMain(lua_State* lua);
}
}
}
#endif