#ifndef _EASY_CARD_RPC_LISTENER_H_
#define _EASY_CARD_RPC_LISTENER_H_

#include "ec_common/interface.h"

namespace EasyCard{
namespace RPC{

class IRpcAcceptor;

class IRpcListener : public Interface
{
public:
    virtual int SetAcceptor(IRpcAcceptor* acceptor) = 0;
    virtual int Listen() = 0;
    virtual void Close() = 0;
};

}
}
#endif