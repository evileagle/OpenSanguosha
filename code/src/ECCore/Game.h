#ifndef _EASY_CARD_GAME_CLASS_H_
#define _EASY_CARD_GAME_CLASS_H_

#include "EC_Core/IGame.h"
#include "EC_Common/type_def.h"
#include "lua/lua.h"

namespace EasyCard
{
    class CGame : public IGame
    {
    public:
        CGame();
        CGame(const char* szName);
        ~CGame();

        virtual const char* GetName();


        void SetName(const char* szName);
        ecode Load();
    private:
        string m_name;
    };
}
#endif