#ifndef _EASY_CARD_RPC_ERROR_H_
#define _EASY_CARD_RPC_ERROR_H_

#include "ec_common/interface.h"

namespace EasyCard{
namespace RPC{

class IRpcHandler;

class IRpcError : public Interface
{
public:
    virtual int SetHander(IRpcHandler* handler) = 0;
};

}
}
#endif