#ifndef _EASY_CARD_GAME_DESCRIPTOTION_CLASS_H_
#define _EASY_CARD_GAME_DESCRIPTOTION_CLASS_H_

#include "EC_Core/IGameDesc.h"
#include "lua/lua.hpp"

namespace EasyCard
{
    using namespace std;
    class CGameDesc : public IGameDesc
    {
    public:
        CGameDesc();
        CGameDesc(const char* name, const char* display_name, size_t player_number);
        ~CGameDesc();

        virtual const char* GetName();
        virtual const char* GetDisplayName();
        virtual size_t GetPlayerNumber();

        void SetName(const char* name);
        void SetDisplayName(const char* display_name);
        void SetPlayerNumber(size_t player_number);
    private:
        bool InitLua();

        string name_;
        string display_name_;
        size_t player_number_;
        lua_State* lua_;
    };
}

#endif