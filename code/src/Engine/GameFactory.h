#ifndef _EASY_CARD_GAME_FACTORY_H_
#define _EASY_CARD_GAME_FACTORY_H_

#include "Engine/IGameFactory.h"
#include "lua/lua.h"
#include "lua/lauxlib.h"
#include "lua/lualib.h"
#include "LuaPlus/table.h"

using namespace LuaPlus;

namespace EasyCard
{
	class CGameFactory : public IGameFactory
	{
	public:
		CGameFactory();
		~CGameFactory();
        bool Initialize();
        virtual uint GetGameCount();
        virtual const IGameDesc* GetGameDesc(uint nIndex);
        virtual IGame* CreateGame(char* szName);
    private:
        bool CreateDescriptor(lua_State* state, table& desc );
        bool CreateDescriptors(lua_State* state, table& games);

	private:
        ptr_vector m_descriptors;
	};

}
#endif

