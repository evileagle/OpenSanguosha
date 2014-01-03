#ifndef _EASY_CARD_RPC_REGISTER_H_
#define _EASY_CARD_RPC_REGISTER_H_

namespace EasyCard{
namespace RPC{

class IRpcRecvFactory;

class IRpcRegister
{
public:
    virtual int RegistRpc(int cmd, IRpcRecvFactory* factory) = 0;
};
}
}
#endif