#include "rpc_base.h"
#include "ec_rpc/rpc_define.h"

namespace EasyCard{
namespace RPC{

RpcBase::RpcBase()
    : port_(0)
    , loop_(NULL)
    , exit_(NULL)
    , thread_(NULL)
{

}

RpcBase::~RpcBase()
{

}

void RpcBase::SetAddress( const char* address, unsigned short port )
{
    if (address == NULL)
    {
        address_ = RPC_LOCAL_ADDRESS;
    }
    else
    {
        address_ = address;
    }
    port_ = port;
}

int RpcBase::Start()
{
    if (thread_ == NULL)
    {
        thread_ = new uv_thread_t;
        memset(thread_, 0, sizeof(*thread_));
        return uv_thread_create(thread_, WorkThread, this);
    }
    return EC_RPC_ALREADY_STARTED;
}

void RpcBase::WorkThread( void *arg )
{
    RpcBase* pThis = (RpcBase*)arg;
    pThis->Work();
}

void RpcBase::Work()
{
    uv_async_init(loop_, &exit_, Exit);
    uv_listen((uv_stream_t*)&server_, SOMAXCONN, ConnectionCallback);
    uv_run(loop_, UV_RUN_DEFAULT);

    uv_close((uv_handle_t*)&server_, NULL);
    uv_close((uv_handle_t*)&exit_, NULL);
    uv_loop_delete(loop_);
}

}
}