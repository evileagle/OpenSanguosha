#include "lua_round_loop.h"
#include "lua/lua.hpp"
#include "ec_common/type_def.h"
#include "lua_game.h"
#include "game_imp.h"
#include "round_loop.h"

namespace EasyCard{
namespace LuaApi{

int AddRound(lua_State* lua)
{
    if (!lua_isnumber(lua, 1) ||
        !lua_isnumber(lua, 2) ||
        !lua_isboolean(lua, 3))
    {
        return 0;
    }
    size_t index = lua_tounsigned(lua, 1);
    size_t pos = lua_tounsigned(lua, 2);
    bool temp = lua_toboolean(lua, 3) != 0;
    PLuaGame game = GetLuaGame(lua);
    if (game == NULL)
    {
        return 0;
    }
    RoundLoop loop = game->game->GetRoundLoop();
    loop.AddRound(index, pos, temp);
    return 0;
}

int StartLoop(lua_State* lua)
{
    PLuaGame game = GetLuaGame(lua);
    if (game == NULL)
    {
        return 0;
    }
    RoundLoop loop = game->game->GetRoundLoop();
    loop.Start();
    return 0;
}

int GetCurrentPlayer( lua_State* lua )
{
    PLuaGame game = GetLuaGame(lua);
    if (game == NULL)
    {
        return 0;
    }
    RoundLoop loop = game->game->GetRoundLoop();
    lua_pushunsigned(lua, loop.Current());
    return 1;
}

}
}