#ifndef _EASY_CARD_GAME_FACTORY_H_
#define _EASY_CARD_GAME_FACTORY_H_

#include "ec_core/game_factory.h"
#include "lua/lua.h"
#include "lua/lauxlib.h"
#include "lua/lualib.h"
#include "lua_plus/table.h"


namespace EasyCard
{
    using namespace LuaPlus;
	class CGameFactory : public IGameFactory
	{
	public:
		CGameFactory();
		~CGameFactory();
        bool Initialize();
        virtual size_t GetGameCount();
        virtual const IGame* CreateGame(size_t index);
    private:

	};

}
#endif

