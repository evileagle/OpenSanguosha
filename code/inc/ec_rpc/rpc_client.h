#ifndef _EASY_CARD_RPC_CLIENT_H_
#define _EASY_CARD_RPC_CLIENT_H_

namespace EasyCard{
namespace RPC{

class IRpcClient
{
public:
    virtual int Send(const char* data, size_t len) = 0;
};

}
}
#endif