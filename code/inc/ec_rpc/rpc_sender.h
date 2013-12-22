#ifndef _EASY_CARD_RPC_SENDER_H_
#define _EASY_CARD_RPC_SENDER_H_

namespace EasyCard{
namespace RPC{

class IRpcReceiver;

class IRpcSender
{
public:
    virtual int BindReceiver(IRpcReceiver* receiver) = 0;
    virtual int Send(const char* data, size_t len) = 0;
    virtual int SendCmd(unsigned int cmd, const char* data, unsigned long timeout) = 0;
    virtual void Close() = 0;
};

}
}
#endif