#ifndef _EASY_CARD_RPC_H_
#define _EASY_CARD_RPC_H_

#include "ec_common/type_def.h"

namespace EasyCard{
namespace RPC{

const size_t IP_STR_SIZE = 16;

struct RpcAddress
{
    string address;
    unsigned short port;
};

}
}
#endif