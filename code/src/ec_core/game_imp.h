#ifndef _EASY_CARD_GAME_CLASS_H_
#define _EASY_CARD_GAME_CLASS_H_

#include "ec_core/game.h"
#include "ec_common/container.h"
#include "round_loop.h"

namespace EasyCard{
namespace Core{

class GameConfig;
class CECCore;
class IPlayer;

class Game : public IGame
{
public:
    typedef Container<IPlayer*> PlayerSet;
    Game();
    explicit Game(CECCore* core);
    Game(CECCore* core, GameConfig& config);
    ~Game();

    bool Init(CECCore* core);
    bool Load(GameConfig& config);
    bool Start();
    CECCore* GetCore();
    RoundLoop& GetRoundLoop();
    PlayerSet& GetPlayerSet();
private:
    CECCore* core_;
    PlayerSet players_;
    RoundLoop loop_;
};

}
}
#endif