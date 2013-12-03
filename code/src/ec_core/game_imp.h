#ifndef _EASY_CARD_GAME_CLASS_H_
#define _EASY_CARD_GAME_CLASS_H_

#include "ec_core/game.h"
#include "ec_common/type_def.h"
#include "lua/lua.h"
#include "lua_api/lua_game.h"

namespace EasyCard
{
class CGame : public IGame
{
public:
    CGame();
    explicit CGame(const char* name);
    ~CGame();

    inline const char* get_name() const { return name_.c_str(); }
    inline void set_name(const char* name) {name_ = name; }

    ecode Load();
private:

    string name_;
};
}

#endif