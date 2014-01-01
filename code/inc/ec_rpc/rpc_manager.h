#ifndef _EASY_CARD_RPC_MANAGER_H_
#define _EASY_CARD_RPC_MANAGER_H_

#include "ec_common/interface.h"

namespace EasyCard{
namespace RPC{

class IRpcManager : public Interface
{
public:
    virtual int CreateSender(const char* name, IRpcSender** sender) = 0;
    virtual int RegistListener(const char* name, IRpcListener* listener) = 0;

};
}

}

#endif