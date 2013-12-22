#ifndef _EASY_CARD_RPC_SERVER_H_
#define _EASY_CARD_RPC_SERVER_H_


namespace EasyCard{
namespace RPC{

class IRpcServer
{
public:
    virtual int RegistServer(const char* name, IRpcListener* listener) = 0;
};

IRpcServer* GetServer();

}
}
#endif