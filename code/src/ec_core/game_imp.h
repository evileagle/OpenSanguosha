#ifndef _EASY_CARD_GAME_CLASS_H_
#define _EASY_CARD_GAME_CLASS_H_

#include "ec_core/game.h"

namespace EasyCard
{
class GameConfig;
class CGame : public IGame
{
public:
    CGame();
    explicit CGame(GameConfig& config);
    ~CGame();

    bool Init(GameConfig& config);
private:
    CECCore* core;
};
}

#endif