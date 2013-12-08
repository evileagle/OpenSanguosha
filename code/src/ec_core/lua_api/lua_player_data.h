#ifndef _EASY_CARD_LUA_API_PLAYER_DATA_H_
#define _EASY_CARD_LUA_API_PLAYER_DATA_H_

struct lua_State;

namespace EasyCard{
namespace LuaApi{
namespace PlayerData{

bool Init(lua_State* lua, size_t number);
int Get(lua_State *lua, size_t index);
bool Dispose(lua_State* lua);

}
}
}
#endif