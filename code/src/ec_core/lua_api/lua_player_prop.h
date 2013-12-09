#ifndef _EASY_CARD_LUA_API_PLAYER_DATA_H_
#define _EASY_CARD_LUA_API_PLAYER_DATA_H_

struct lua_State;

namespace EasyCard{
namespace LuaApi{

bool InitPlayerProp(lua_State* lua, size_t number);
bool DisposePlayerProp(lua_State* lua);


int GetPlayerProp(lua_State *lua);
int SetPlayerProp(lua_State *lua);

}
}
#endif