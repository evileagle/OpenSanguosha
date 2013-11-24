#ifndef _EASY_CARD_GAME_FACTORY_INTERFACE_H_
#define _EASY_CARD_GAME_FACTORY_INTERFACE_H_

#include "Platform/type_def.h"

using namespace Platform;

namespace EasyCard
{
    class IGame;
    class IGameDesc;

	class IGameFactory
	{
	public:
		virtual uint GetGameCount() = 0;
		virtual const IGameDesc* GetGameDesc(uint nIndex) = 0;
		virtual IGame* CreateGame(char* szName) = 0;
	};

}
#endif