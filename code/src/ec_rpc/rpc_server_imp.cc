#include "rpc_server_imp.h"
#include <assert.h>
#include "event2/event.h"
#include "event2/listener.h"

namespace EasyCard{
namespace RPC{

RpcServer::RpcServer()
    : manager_(NULL)
    , port_(0)
{

}

RpcServer::~RpcServer()
{

}

int RpcServer::Initialize( RpcManager* manager )
{
    assert(manager != NULL);
    manager_ = manager;
}

int RpcServer::BindAddress( const char* address, unsigned short port )
{
    assert(address != NULL);
    address_ = address;

}

void RpcServer::Work()
{

}

int RpcServer::Start()
{

}

}
}