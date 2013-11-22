#ifndef _EASY_CARD_ROOM_MANAGER_INTERFACE_H_
#define _EASY_CARD_ROOM_MANAGER_INTERFACE_H_


#include "Platform/type_def.h"
#include "Platform/Iterator.h"

using namespace Platform;

namespace EasyCard
{
    class IRoom;


    class IRoomMgr
    {
    public:
    class Iterator : public Iterator<IRoom>;

        virtual IRoom* CreateRoom() = 0;
        virtual Iterator* OpenIterator() = 0;

    };
}


#endif