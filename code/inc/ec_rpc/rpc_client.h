#ifndef _EASY_CARD_RPC_CLIENT_H_
#define _EASY_CARD_RPC_CLIENT_H_

namespace EasyCard{
namespace RPC{

struct RpcAddress;

class IRpcReceiver
{
public:
    virtual int OnReceiveCmd(unsigned int cmd, const char* data) = 0;
    virtual int OnReceive(const char* data, unsigned long size) = 0;
    virtual int OnError(unsigned long code) = 0;
};

class IRpcClient
{
public:
    virtual void SetReceiver(IRpcReceiver* receiver) = 0;
    virtual int Bind(RpcAddress& address) = 0;
    virtual int Connect(RpcAddress& address) = 0;
    virtual int GetRemote(RpcAddress& address) = 0;
    virtual int Send(const char* data, size_t len) = 0;
    virtual int SendCmd(unsigned int cmd, const char* data, unsigned long timeout) = 0;
    virtual void Close() = 0;
};

}
}
#endif