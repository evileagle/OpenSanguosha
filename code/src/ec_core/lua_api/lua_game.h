#ifndef _EASY_CARD_LUAGMAE_H_
#define _EASY_CARD_LUAGMAE_H_

struct lua_State;

namespace EasyCard{

class IGame;

namespace LuaApi{

namespace Game{

bool Create(lua_State* lua);
bool Set(lua_State* lua, const IGame* game);
void Destroy(lua_State* lua);

}
}
}

#endif

