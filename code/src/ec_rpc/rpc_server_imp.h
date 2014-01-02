#ifndef _EASY_CARD_RPC_SERVER_IMP_H_
#define _EASY_CARD_RPC_SERVER_IMP_H_

#include "ec_rpc/rpc_server.h"
#include "rpc_base.h"
#include "ec_common/type_def.h"

namespace EasyCard{
namespace RPC{

using namespace std;

class RpcManager;
class IRpcListener;

class RpcServer : public IRpcServer, public RpcBase
{
public:
    RpcServer();
    ~RpcServer();
    virtual int Initialize();
    virtual int Listen();
    virtual int RegistListener(const char* name, IRpcListener* listener);
    virtual int BindAddress(const char* address, unsigned short port);
    virtual void Close();
private:
    void OnConnection(int status);
    void NotifyListener();
    static void ConnectionCallback(uv_stream_t* server, int status);
    void WaitStop();
    RpcManager* manager_;
    uv_tcp_t* server_;
    ptr_vector clients_;
    string_ptr_map listeners_;
};

}
}
#endif