#ifndef _EASY_CARD_LUAGMAE_H_
#define _EASY_CARD_LUAGMAE_H_

struct lua_State;

namespace EasyCard{

class Game;

namespace LuaApi{

bool CreateLuaGame(lua_State* lua, const Game* game);
void DestroyLuaGame(lua_State* lua);
void GetLuaGame(lua_State* lua);

}
}

#endif

