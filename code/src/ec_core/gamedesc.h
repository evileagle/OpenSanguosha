#ifndef _EASY_CARD_GAME_DESCRIPTOTION_CLASS_H_
#define _EASY_CARD_GAME_DESCRIPTOTION_CLASS_H_

#include "EC_Core/IGameDesc.h"

namespace EasyCard
{
    class CGameDesc : public IGameDesc
    {
    public:
        CGameDesc();
        CGameDesc(const char* szName, const char* szDisplayName, size_t nPlayerNumber);
        ~CGameDesc();

        virtual const char* GetName();
        virtual const char* GetDisplayName();
        virtual size_t GetPlayerNumber();

        void SetName(const char* szName);
        void SetDisplayName(const char* szDisplayName);
        void SetPlayerNumber(size_t nNumber);
    private:
        string m_name;
        string m_displayName;
        size_t m_number;
    };
}

#endif