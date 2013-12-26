#include "rpc_server_imp.h"
#include <assert.h>

namespace EasyCard{
namespace RPC{

RpcServer::RpcServer()
    : manager_(NULL)
{

}

RpcServer::~RpcServer()
{

}

int RpcServer::Initialize( RpcManager* manager )
{
    assert(manager != NULL);
    manager_ = manager;
    loop_ = uv_loop_new();
    int err = uv_tcp_init(loop_, &server_);
    loop_->data = this;
    return err;
}

int RpcServer::BindAddress( const char* address, unsigned short port )
{
    assert(address != NULL);

    uv_ip4_addr(address, port, &addr_);
    return uv_tcp_bind(&server_, (sockaddr*)&addr_);
}

void RpcServer::WorkThread( void *arg )
{
    RpcServer* pThis = (RpcServer*)arg;
    pThis->Work();
}

void RpcServer::Work()
{
    uv_async_init(loop_, &exit_, Exit);
    uv_listen((uv_stream_t*)&server_, SOMAXCONN, ConnectionCallback);
    uv_run(loop_, UV_RUN_DEFAULT);

    uv_close((uv_handle_t*)&server_, NULL);
    uv_close((uv_handle_t*)&exit_, NULL);
    uv_loop_delete(loop_);
}

int RpcServer::Start()
{
    return uv_thread_create(&thread_, WorkThread, this);
}

void RpcServer::Close()
{
    WaitStop();
}

void RpcServer::ConnectionCallback( uv_stream_t* server, int status )
{
    RpcServer* pThis = (RpcServer*)server->loop->data;
    pThis->OnConnection(status);

}

void RpcServer::OnConnection( int status )
{
    if (status < 0)
    {
        ProcessError();
        return;
    }
    else
    {
        uv_tcp_t* client = new uv_tcp_t;
        if (uv_accept((uv_stream_t*)&server_, (uv_stream_t*)client) == 0)
        {

        }
    }
}

void RpcServer::WaitStop()
{
    uv_async_send(&exit_);
    uv_thread_join(&thread_);
}

void RpcServer::ProcessError()
{
    Stop();
}

void RpcServer::Exit( uv_async_t* handle, int status )
{
    RpcServer* pThis = (RpcServer*)handle->loop->data;
    pThis->Stop();
}

void RpcServer::Stop()
{
    uv_stop(loop_);
}

}
}