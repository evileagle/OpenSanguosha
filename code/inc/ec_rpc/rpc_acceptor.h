#ifndef _EASY_CARD_RPC_ACCEPTOR_H_
#define _EASY_CARD_RPC_ACCEPTOR_H_


namespace EasyCard{
namespace RPC{

class IRpcSender;

class IRpcAcceptor
{
public:
    virtual void OnAccept(IRpcSender* sender) = 0;
    virtual void OnClose(IRpcSender* sender) = 0;
};
}
}
#endif