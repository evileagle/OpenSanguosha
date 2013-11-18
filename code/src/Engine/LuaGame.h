#ifndef _EASY_CARD_LUAGMAE_H_
#define _EASY_CARD_LUAGMAE_H_

namespace EasyCard
{
	typedef struct LuaGame
	{
		IGame* m_pGame;
	}*PLuaGame;

	CreateLuaGame(lua_State* l);

}

#endif

