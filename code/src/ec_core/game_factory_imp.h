#ifndef _EASY_CARD_GAME_FACTORY_H_
#define _EASY_CARD_GAME_FACTORY_H_

#include "EC_Core/IGameFactory.h"
#include "lua/lua.h"
#include "lua/lauxlib.h"
#include "lua/lualib.h"
#include "LuaPlus/table.h"


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
        virtual const IGameDesc* GetGameDesc(size_t nIndex);
        virtual const IGame* CreateGame(const char* szName);
    private:
        bool CreateDescriptor(lua_State* state, table& desc );
        bool CreateDescriptors(lua_State* state, table& games);

	private:
        ptr_vector m_descriptors;
	};

}
#endif

