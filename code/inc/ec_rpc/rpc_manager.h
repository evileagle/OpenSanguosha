#ifndef _EASY_CARD_RPC_MANAGER_H_
#define _EASY_CARD_RPC_MANAGER_H_

#include "ec_common/interface.h"

namespace EasyCard{
namespace RPC{

class IRpcSender;
class IRpcListener;

class IRpcManager : public Interface
{
public:
    IRpcSender* CreateSender(const char* address, unsigned short port) = 0;
    IRpcListener* CreateListener(const char* address, unsigned short port) = 0;
};
}

}

#endif