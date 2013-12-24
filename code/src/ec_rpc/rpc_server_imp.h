#ifndef _EASY_CARD_RPC_SERVER_IMP_H_
#define _EASY_CARD_RPC_SERVER_IMP_H_

struct event_base;

namespace EasyCard{
namespace RPC{

class RpcManager;

class RpcServer : public IRpcServer
{
public:
    RpcServer();
    ~RpcServer();
    int Initialize(RpcManager* manager);
    virtual int Start() = 0;
    virtual int RegistListener(const char* name, IRpcListener* listener);
    virtual int BindAddress(const char* address, unsigned short port);
    virtual void Close();
private:
    void Work();
    RpcManager* manager_;
    string address_;
    unsigned short port_;
};

}
}
#endif