#ifndef _EASY_CARD_GAME_CLASS_H_
#define _EASY_CARD_GAME_CLASS_H_

#include "ec_core/game.h"

namespace EasyCard
{
class GameConfig;
class CECCore;
class Game : public IGame
{
public:
    Game();
    explicit Game(CECCore* core);
    Game(CECCore* core, GameConfig& config);
    ~Game();

    bool Init(CECCore* core);
    bool Load(GameConfig& config);
private:
    CECCore* core_;
};
}

#endif