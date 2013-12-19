#ifndef _EASY_CARD_LUA_LOADER_ROUND_H_
#define _EASY_CARD_LUA_LOADER_ROUND_H_

struct lua_State;

namespace EasyCard{
namespace Core{
namespace LuaLoader{

bool LoadRound(lua_State* lua);
bool CallRound(lua_State* lua);
bool GetRound(lua_State* lua);
void DisposeRound(lua_State* lua);
}
}
}
#endif