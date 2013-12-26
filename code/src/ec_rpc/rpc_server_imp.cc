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
    server_.data = this;
    return err;
}

int RpcServer::BindAddress( const char* address, unsigned short port )
{
    assert(address != NULL);

    uv_ip4_addr(address, port, &addr_);
    return uv_tcp_bind(&server_, (sockaddr*)&addr_);
}

void RpcServer::Work()
{
    uv_listen((uv_stream_t*)&server_, SOMAXCONN, ConnectionCallback);
    uv_run(loop_, UV_RUN_DEFAULT);
}

int RpcServer::Start()
{
    return uv_thread_create(&thread_, WorkThread, this);
}

void RpcServer::WorkThread( void *arg )
{
    RpcServer* pThis = (RpcServer*)arg;
    pThis->Work();
}

void RpcServer::Close()
{
    WaitStop();
    Destroy();
}

void RpcServer::ConnectionCallback( uv_stream_t* server, int status )
{
    RpcServer* pThis = (RpcServer*)server->data;
    pThis->OnConnection(status);

}

void RpcServer::OnConnection( int status )
{
    if (status < 0)
    {
        uv_stop(loop_);
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

void RpcServer::Destroy()
{
    uv_close((uv_handle_t*)&server_, NULL);
    uv_loop_delete(loop_);
}

void RpcServer::WaitStop()
{
    uv_stop(loop_);
    uv_thread_join(&thread_);
}

}
}