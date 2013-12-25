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
    return uv_tcp_init(loop_, &server_);
}

int RpcServer::BindAddress( const char* address, unsigned short port )
{
    assert(address != NULL);

    uv_ip4_addr(address, port, &addr_);
    return uv_tcp_bind(&server_, (sockaddr*)&addr_);
}

void RpcServer::Work()
{
    uv_listen((uv_stream_t*)&server_, SOMAXCONN, OnConnection);
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
    uv_thread_join(&thread_);
}

}
}