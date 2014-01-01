#ifndef _EASY_CARD_RPC_BASE_H_
#define _EASY_CARD_RPC_BASE_H_

#include "uv.h"
#include <string>

namespace EasyCard{
namespace RPC{
using namespace std;

class RpcManager;

class RpcBase
{
public:
    RpcBase();
    ~RpcBase();
    virtual int Initialize(RpcManager* manager);
    void SetAddress(const char* address, unsigned short port);

protected:
    int Start();

private:
    void Work();
    static void WorkThread(void *arg);

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