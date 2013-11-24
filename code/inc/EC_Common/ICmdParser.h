#ifndef _EASY_CARD_COMMON_CMD_PARSER_INTERFACE_H_
#define _EASY_CARD_COMMON_CMD_PARSER_INTERFACE_H_

#include "type_def.h"

namespace EasyCard
{
    class ICmd;

    class ICmdParser
    {
    public:
        virtual ecode EncodeCmd(ICmd* pCmd) = 0;
    };
}
#endif