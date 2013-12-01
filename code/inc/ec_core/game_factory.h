#ifndef _EASY_CARD_GAME_FACTORY_INTERFACE_H_
#define _EASY_CARD_GAME_FACTORY_INTERFACE_H_

#include "ec_common/type_def.h"


namespace EasyCard
{
    class IGame;
    class IGameDesc;

	class IGameFactory
	{
	public:
		virtual size_t GetGameCount() = 0;
		virtual const IGameDesc* GetGameDesc(size_t nIndex) = 0;
		virtual const IGame* CreateGame(const char* szName) = 0;
	};

}
#endif