#ifndef _EASY_CARD_GAME_FACTORY_H_
#define _EASY_CARD_GAME_FACTORY_H_

#include "Engine/IGameFactory.h"
#include "lua/lua.h"
#include "lua/lauxlib.h"
#include "lua/lualib.h"

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
        bool CreateDescriptor(lua_State* state);

	private:
        ptr_vector m_descriptors;
	};

}
#endif

