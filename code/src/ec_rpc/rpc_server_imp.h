#ifndef _EASY_CARD_RPC_SERVER_IMP_H_
#define _EASY_CARD_RPC_SERVER_IMP_H_

#include "ec_common/type_def.h"
#include "ec_rpc/rpc_server.h"
#include "uv.h"

namespace EasyCard{
namespace RPC{

using namespace std;

class RpcManager;
class IRpcListener;

class RpcServer : public IRpcServer
{
public:
    RpcServer();
    ~RpcServer();
    int Initialize(RpcManager* manager, const char* address, unsigned short port);
    virtual int Start();
    virtual int RegistListener(const char* name, IRpcListener* listener);
    virtual void Close();
private:
    void Work();
    void OnConnection(int status);
    void NotifyListener();
    static void WorkThread(void *arg);
    static void ConnectionCallback(uv_stream_t* server, int status);
    static Read(uv_stream_t* stream, ssize_t nread, const uv_buf_t* buf);
    static void Exit(uv_async_t* handle, int status);
    void WaitStop();
    RpcManager* manager_;
    string address_;
    unsigned short port_;
    uv_thread_t thread_;
    uv_loop_t* loop_;
    uv_async_t exit_notify_;
    ptr_vector clients_;
    string_ptr_map listeners_;

    class RemoteClient
    {
    public:
        RemoteClient();
        ~RemoteClient();
    };
};

}
}
#endif