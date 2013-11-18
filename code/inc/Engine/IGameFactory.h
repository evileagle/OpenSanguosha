#ifndef _EASY_CARD_GAME_FACTORY_INTERFACE_H_
#define _EASY_CARD_GAME_FACTORY_INTERFACE_H_

#include "ECCommon.h"

class IGame;
class IGameDesc;

namespace EasyCard
{

	class IGameFactory
	{
	public:
		virtual uint GetGameCount() = 0;
		virtual IGameDesc* GetGameDesc(uint nIndex) = 0;
		virtual IGame* CreateGame(char* szName) = 0;
	};

}
#endif