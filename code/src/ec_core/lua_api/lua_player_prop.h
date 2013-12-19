#ifndef _EASY_CARD_LUA_API_PLAYER_PROP_H_
#define _EASY_CARD_LUA_API_PLAYER_PROP_H_

struct lua_State;

namespace EasyCard{
namespace Core{
namespace LuaApi{

bool InitPlayerProp(lua_State* lua, size_t number);


int GetPlayerProp(lua_State *lua);
int SetPlayerProp(lua_State *lua);

}
}
}
#endif