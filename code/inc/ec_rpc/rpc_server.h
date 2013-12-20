#ifndef _EASY_CARD_RPC_SERVER_H_
#define _EASY_CARD_RPC_SERVER_H_


namespace EasyCard{
namespace RPC{

    class IRpcClient;

    class IRpcListener
    {
    public:
        virtual int OnAccept(IRpcClient* client) = 0;
        virtual int OnError(unsigned long code) = 0;
    };

    class IRpcServer
    {
    public:
        virtual void SetListener(IRpcListener* listener) = 0;
        virtual void Close() = 0;
    };
}
}
#endif