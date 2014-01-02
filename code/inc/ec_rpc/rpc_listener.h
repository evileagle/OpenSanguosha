#ifndef _EASY_CARD_RPC_LISTENER_H_
#define _EASY_CARD_RPC_LISTENER_H_


namespace EasyCard{
namespace RPC{

class IRpcSender;

class IRpcListener
{
public:
    virtual void OnAccept(const char* name, IRpcClient* client) = 0;
    virtual void OnClose(const char* name) = 0;
};
}
}
#endif