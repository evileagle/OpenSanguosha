#ifndef _EASY_CARD_COMMON_CMD_INTERFACE_H_
#define _EASY_CARD_COMMON_CMD_INTERFACE_H_

namespace EasyCard
{
    class ICmd
    {
    public:
        virtual Execute() = 0;
    };
}
#endif