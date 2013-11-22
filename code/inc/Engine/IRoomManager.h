#ifndef _EASY_CARD_ROOM_MANAGER_INTERFACE_H_
#define _EASY_CARD_ROOM_MANAGER_INTERFACE_H_


#include "Platform/type_def.h"
#include "Platform/Iterator.h"

using namespace Platform;

namespace EasyCard
{
    class IRoom;

    typedef Iterator<IRoom> RoomIterator;

    class IRoomMgr
    {
    public:
        virtual IRoom* CreateRoom() = 0;
        virtual RoomIterator GetRoomIterator() = 0;

    };
}


#endif