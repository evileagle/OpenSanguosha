#ifndef _EASY_CARD_RPC_SERVER_H_
#define _EASY_CARD_RPC_SERVER_H_

#include "ec_common/interface.h"

namespace EasyCard{
namespace RPC{

class IRpcServer : public Interface
{
public:
    virtual int BindAddress(const char* address, unsigned short port) = 0;
    virtual int Listen() = 0;
    virtual void Close() = 0;
};

IRpcServer* CreateServer(void* param);

}
}
#endif