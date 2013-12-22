#ifndef _EASY_CARD_RPC_CLIENT_H_
#define _EASY_CARD_RPC_CLIENT_H_

namespace EasyCard{
namespace RPC{

class RpcClient : public IRpcClient
{
public:
    RpcClient();
    ~RpcClient();
    int Initialize();

};


}
}
#endif