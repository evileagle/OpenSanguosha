#ifndef _EASY_CARD_RPC_FACTORY_H_
#define _EASY_CARD_RPC_FACTORY_H_

namespace EasyCard{
namespace RPC{

class IRpcClient;
class IRpcServer;

class IRpcFactory
{
public:
    virtual IRpcClient* CreateClient(unsigned char type) = 0;
    virtual IRpcServer* CreateServer() = 0;
};

IRpcFactory* GetFactory();

}
}


#endif