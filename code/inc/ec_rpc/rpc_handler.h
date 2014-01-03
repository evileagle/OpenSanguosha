#ifndef _EASY_CARD_RPC_HANDLER_H_
#define _EASY_CARD_RPC_HANDLER_H_

namespace EasyCard{
namespace RPC{

class IRpcError;

class IRpcHandler
{
public:
    virtual int OnError(IRpcError* error, int code) = 0;
};

}
}
#endif