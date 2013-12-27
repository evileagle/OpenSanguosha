#include "rpc_server_imp.h"
#include <assert.h>

namespace EasyCard{
namespace RPC{

RpcServer::RpcServer()
    : manager_(NULL)
    , loop_(NULL)
    , thread_(NULL)
{

}

RpcServer::~RpcServer()
{

}

int RpcServer::Initialize( RpcManager* manager, const char* address, unsigned short port )
{
    assert(manager != NULL);
    manager_ = manager;
    address_ = address;
    port_ = port;
    loop_ = uv_loop_new();
    loop_->data = this;
    uv_async_init(loop_, &exit_notify_, Exit);
    return 0;
}


void RpcServer::WorkThread( void *arg )
{
    RpcServer* pThis = (RpcServer*)arg;
    pThis->Work();
}

void RpcServer::Work()
{
    uv_tcp_t server;
    uv_tcp_init(loop_, &server);
    sockaddr_in addr = {0};
    uv_ip4_addr(address_.c_str(), port_, &addr);
    uv_tcp_bind(&server, (sockaddr*)&addr);
    uv_listen((uv_stream_t*)&server, SOMAXCONN, ConnectionCallback);
    uv_run(loop_, UV_RUN_DEFAULT);

    uv_close((uv_handle_t*)&server, NULL);
    uv_close((uv_handle_t*)&exit_notify_, NULL);
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
    if (status < 0)
    {
        uv_stop(server->loop);
        return;
    }
    else
    {
        uv_tcp_t* client = new uv_tcp_t;
        if (uv_accept((uv_stream_t*)&server, (uv_stream_t*)client) == 0)
        {
            uv_read_start((uv_stream_t*)client, );
        }
    }
}

void RpcServer::OnConnection( int status )
{
}

void RpcServer::WaitStop()
{
    if (loop_ != NULL)
    {
        uv_async_send(&exit_notify_);
        uv_thread_join(&thread_);
    }
}

void RpcServer::Exit( uv_async_t* handle, int status )
{
    uv_stop(handle->loop);
}

}
}