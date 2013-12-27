#ifndef _EASY_CARD_RPC_SERVER_H_
#define _EASY_CARD_RPC_SERVER_H_


namespace EasyCard{
namespace RPC{

class IRpcListener;

class IRpcServer
{
public:
    virtual int Start() = 0;
    virtual void Close() = 0;
    virtual int RegistListener(const char* name, IRpcListener* listener) = 0;
};

}
}
#endif