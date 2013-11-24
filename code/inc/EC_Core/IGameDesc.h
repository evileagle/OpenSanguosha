#ifndef _EASY_CARD_GAME_DESCRIPTOTION_INTERFACE_H_
#define _EASY_CARD_GAME_DESCRIPTOTION_INTERFACE_H_


namespace EasyCard
{
	class IGameDesc
	{
	public:
		virtual const char* GetName() = 0;
		virtual const char* GetDisplayName() = 0;
		virtual int GetPlayerNumber() = 0;
	};
}
#endif