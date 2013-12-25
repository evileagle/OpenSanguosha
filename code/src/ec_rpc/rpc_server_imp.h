#ifndef _EASY_CARD_RPC_SERVER_IMP_H_
#define _EASY_CARD_RPC_SERVER_IMP_H_

#include "ec_common/type_def.h"
#include "uv.h"

namespace EasyCard{
namespace RPC{

using namespace std;

class RpcManager;

class RpcServer : public IRpcServer
{
public:
    RpcServer();
    ~RpcServer();
    int Initialize(RpcManager* manager);
    virtual int Start();
    virtual int RegistListener(const char* name, IRpcListener* listener);
    virtual int BindAddress(const char* address, unsigned short port);
    virtual void Close();
private:
    void Work();
    static void WorkThread(void *arg);
    static void OnConnection(uv_stream_t* server, int status);
    RpcManager* manager_;
    sockaddr_in addr_;
    uv_thread_t thread_;
    uv_tcp_t server_;
    uv_loop_t* loop_;
};

}
}
#endif