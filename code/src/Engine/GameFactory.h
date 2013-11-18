#ifndef _EASY_CARD_GAME_FACTORY_H_
#define _EASY_CARD_GAME_FACTORY_H_

#include "Engine/IGameFactory.h"

namespace EasyCard
{
	class CGameFactory : public IGameFactory
	{
	public:
		CGameFactory();
		~CGameFactory();
        bool Initialize();
        virtual uint GetGameCount();
        virtual IGameDesc* GetGameDesc(uint nIndex);
        virtual IGame* CreateGame(char* szName);

	private:
        ptr_vector m_descriptors;
	};

}
#endif

