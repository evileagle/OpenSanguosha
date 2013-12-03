#include "game_desc_imp.h"
#include <assert.h>

#include "ec_common/type_def.h"

namespace EasyCard
{

    CGameDesc::CGameDesc()
        : player_number_(0)
    {

    }

    CGameDesc::CGameDesc( const char* name, const char* display_name, size_t player_number )
    {
        SetName(name);
        SetDisplayName(display_name);
        SetPlayerNumber(player_number);
    }

    CGameDesc::~CGameDesc()
    {

    }

    const char* CGameDesc::GetName()
    {
        return name_.c_str();
    }

    const char* CGameDesc::GetDisplayName()
    {
        return display_name_.c_str();
    }

    size_t CGameDesc::GetPlayerNumber()
    {
        return player_number_;
    }

    void CGameDesc::SetName( const char* name )
    {
        assert(name);
        if (name != NULL)
        {
            name_ = name;
        }
    }

    void CGameDesc::SetDisplayName( const char* display_name )
    {
        assert(display_name);
        if (display_name != NULL)
        {
            display_name_ = display_name;
        }
    }

    void CGameDesc::SetPlayerNumber( size_t player_number )
    {
        player_number_ = player_number;
    }

    bool CGameDesc::InitLua()
    {
        lua_ = luaL_newstate();
        if (lua_ == NULL)
        {
            return false;
        }
        luaL_openlibs(lua_);
        return true;
    }

}