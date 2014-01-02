#ifndef _EASY_CARD_RPC_BASE_H_
#define _EASY_CARD_RPC_BASE_H_

#include "ec_rpc/rpc_manager.h"
#include "uv.h"
#include <string>

namespace EasyCard{
namespace RPC{
using namespace std;

class RpcBase : public IRpcManager
{
public:
    RpcBase();
    ~RpcBase();
    virtual int Initialize();
    void SetAddress(const char* address, unsigned short port);

    virtual int CreateSender(const char* name, IRpcSender** sender);
    virtual int RegistListener(const char* name, IRpcListener* listener);

protected:
    int Start();
    void ProcessError();
    virtual void CleanUp();

private:
    void Work();
    static void WorkThread(void *arg);
    static void Exit(uv_async_t* handle, int status);
    void Stop();

protected:
    string address_;
    unsigned short port_;
    uv_thread_t* thread_;
    uv_loop_t* loop_;
    uv_async_t* exit_;
};

}
}
#endif