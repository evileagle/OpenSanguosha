#ifndef _EASY_CARD_GAME_FACTORY_H_
#define _EASY_CARD_GAME_FACTORY_H_

#include "ec_core/game_factory.h"


namespace EasyCard
{
    class CECCore;
	class GameFactory : public IGameFactory
	{
	public:
		GameFactory();
		~GameFactory();
        bool Initialize(CECCore* core);
        virtual size_t GetPredefineCount();
        virtual const IGame* CreatePredefineGame(size_t index);
        virtual const IGame* CreateGame(GameConfig& config);
    private:
        IGame* CreateFromeLua();
        bool LoadPredefine();
        CECCore* core_;

	};

}
#endif

