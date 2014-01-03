#ifndef _EASY_CARD_RPC_RECEIVER_H_
#define _EASY_CARD_RPC_RECEIVER_H_

#include "ec_common/interface.h"

namespace EasyCard{
namespace RPC{

class IRpcSender;

class IRpcReceiver
{
public:
    virtual int OnReceiveCmd(IRpcSender* sender, unsigned int cmd, const char* data) = 0;
};

}
}
#endif