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

int RpcServer::Initialize()
{
    if (server_ == NULL)
    {
        server_ = new uv_tcp_t;
        memset(server_, 0, sizeof(*server_));
        return uv_tcp_init(loop_, server_);
    }
    return 0;
}

int RpcServer::BindAddress( const char* address, unsigned short port )
{
    assert(address != NULL);

}

int RpcServer::Listen()
{    
    sockaddr_in addr = {0};
    uv_ip4_addr(address_.c_str(), port_, &addr);
    uv_tcp_bind(server_, (sockaddr*)&addr);
    uv_listen((uv_stream_t*)server_, SOMAXCONN, ConnectionCallback);
    return RpcBase::Start();
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
        if (uv_accept((uv_stream_t*)server_, (uv_stream_t*)client) == 0)
        {

        }
    }
}

void RpcServer::WaitStop()
{
    uv_async_send(exit_);
    uv_thread_join(thread_);
}

}
}