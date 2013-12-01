#ifndef _EASY_CARD_GAME_DESCRIPTOTION_INTERFACE_H_
#define _EASY_CARD_GAME_DESCRIPTOTION_INTERFACE_H_

#include "ec_common/type_def.h"

namespace EasyCard
{
	class IGameDesc
	{
	public:
		virtual const char* GetName() = 0;
		virtual const char* GetDisplayName() = 0;
		virtual size_t GetPlayerNumber() = 0;
	};
}
#endif