#ifndef _EASY_CARD_RPC_NET_CLIENT_IMP_H_
#define _EASY_CARD_RPC_NET_CLIENT_IMP_H_

#include "ec_rpc/rpc_client.h"

namespace EasyCard{
namespace RPC{

    class RpcTcpSender : public IRpcSender
    {
    public:
        virtual int BindReceiver(IRpcReceiver* receiver);
        virtual int Send(const char* data, size_t len);
        virtual int SendCmd(unsigned int cmd, const char* data, unsigned long timeout);
        virtual void Close();
    };

}
}

#endif