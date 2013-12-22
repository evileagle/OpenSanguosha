#ifndef _EASY_CARD_RPC_H_
#define _EASY_CARD_RPC_H_

#include "ec_common/type_def.h"

namespace EasyCard{
namespace RPC{

class IRpcSender;

class IRpcReceiver
{
public:
    virtual int OnReceiveCmd(IRpcSender* sender, unsigned int cmd, const char* data) = 0;
    virtual int OnReceive(IRpcSender* sender, const char* data, unsigned long size) = 0;
    virtual int OnError(IRpcSender* sender, unsigned long code) = 0;
};

}
}
#endif