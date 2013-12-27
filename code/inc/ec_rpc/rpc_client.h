#ifndef _EASY_CARD_RPC_CLIENT_H_
#define _EASY_CARD_RPC_CLIENT_H_

namespace EasyCard{
namespace RPC{

class IRpcSender;

class IRpcClient
{
public:
    virtual int CreateSender(const char* name, IRpcSender** sender) = 0;
    virtual void Close() = 0;
};

}
}


#endif