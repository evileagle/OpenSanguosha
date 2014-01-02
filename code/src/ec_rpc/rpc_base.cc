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

int RpcBase::Initialize()
{
    if (loop_ == NULL)
    {
        loop_ = uv_loop_new();
        exit_ = new uv_async_t;
        memset(exit_, 0, sizeof(*exit_));
        uv_async_init(loop_, exit_, Exit);
    }
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
    uv_run(loop_, UV_RUN_DEFAULT);
    CleanUp();
}

void RpcBase::ProcessError()
{
    Stop();
}

void RpcBase::Exit( uv_async_t* handle, int status )
{
    RpcBase* pThis = (RpcBase*)handle->loop->data;
    pThis->Stop();
}

void RpcBase::Stop()
{
    uv_stop(loop_);
}

void RpcBase::CleanUp()
{
    uv_close((uv_handle_t*)exit_, NULL);
    uv_loop_delete(loop_);
}

}
}