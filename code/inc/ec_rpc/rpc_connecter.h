#ifndef _EASY_CARD_RPC_CONNECTER_H_
#define _EASY_CARD_RPC_CONNECTER_H_

#include "ec_common/interface.h"

namespace EasyCard{
namespace RPC{

class IRpcReceiver;

class IRpcConnecter : public Interface
{
public:
    virtual int Connect() = 0;
};

}
}
#endif