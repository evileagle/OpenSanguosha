#ifndef _EASY_CARD_RPC_LOCAL_SENDER_H_
#define _EASY_CARD_RPC_LOCAL_SENDER_H_

#include "ec_rpc/rpc_sender.h"

namespace EasyCard{
namespace RPC{

class LocalSender : public IRpcSender
{
public:
    LocalSender();
    ~LocalSender();
    virtual int Send(const char* data, size_t len);
    virtual int SendCmd(unsigned int cmd, const char* data, unsigned long timeout);
    virtual void Close();
};
}
}
#endif