#ifndef _EASY_CARD_LUAGMAE_H_
#define _EASY_CARD_LUAGMAE_H_

struct lua_State;

namespace EasyCard
{
    class IGame;
	typedef struct LuaGame
	{
		const IGame* game;
	}*PLuaGame;

	
    PLuaGame LoadGame(lua_State* lua, const char* name, const IGame* game);
    void DestroyGame(PLuaGame game);
}

#endif

