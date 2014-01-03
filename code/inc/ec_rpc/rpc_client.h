#ifndef _EASY_CARD_RPC_CLIENT_H_
#define _EASY_CARD_RPC_CLIENT_H_

#include "ec_common/interface.h"

namespace EasyCard{
namespace RPC{


class IRpcSender : public Interface
{
public:
    virtual int GetAddress() = 0;
    virtual void Close() = 0;
};

}
}


#endif