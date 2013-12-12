#ifndef _EASY_CARD_LUA_API_ROUND_LOOP_H_
#define _EASY_CARD_LUA_API_ROUND_LOOP_H_


struct lua_State;

namespace EasyCard{
namespace LuaApi{

int AddRound(lua_State* lua);
int StartLoop(lua_State* lua);
int GetCurrentPlayer(lua_State* lua);

}
}

#endif