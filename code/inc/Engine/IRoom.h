#ifndef _EASY_CARD_ROOM_INTERFACE_H_
#define _EASY_CARD_ROOM_INTERFACE_H_

#include "Platform/type_def.h"

using namespace Platform;

namespace EasyCard
{
    class IRoom 
    {
    public:
        virtual uint GetPlayerCount() = 0;
        virtual uint Join() = 0;
        virtual uint StartGame() = 0; 
        virtual bool Exit() = 0;
    };

}
#endif