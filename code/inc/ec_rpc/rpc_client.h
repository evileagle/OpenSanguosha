#ifndef _EASY_CARD_RPC_CLIENT_H_
#define _EASY_CARD_RPC_CLIENT_H_

#include "ec_common/interface.h"

namespace EasyCard{
namespace RPC{

class IRpcSender;

class IRpcClient : public Interface
{
public:
    virtual int Connect(const char* address, unsigned short port) = 0;
    virtual void Close() = 0;
};

IRpcClient* CreateClient(void* param);

}
}


#endif