#ifndef _EASY_CARD_GAME_FACTORY_H_
#define _EASY_CARD_GAME_FACTORY_H_

#include "ec_core/game_factory.h"


namespace EasyCard
{
    class CECCore;
	class CGameFactory : public IGameFactory
	{
	public:
		CGameFactory();
		~CGameFactory();
        bool Initialize(CECCore* core);
        virtual size_t GetPredefineCount();
        virtual const IGame* CreatePredefineGame(size_t index);
    private:
        bool LoadPredefine();
        CECCore* core_;

	};

}
#endif

