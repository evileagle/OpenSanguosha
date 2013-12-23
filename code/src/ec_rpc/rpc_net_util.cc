#include "rpc_net_util.h"

namespace EasyCard{
namespace RPC{
namespace Util{


void InitializeNetwork()
{
#ifdef WIN32
    WSAData wsa;
    WSAStartup(MAKEWORD(2, 2), &wsa);
#endif // WIN32
}

void UninitializeNetwork()
{
#ifdef WIN32
    WSACleanup();
#endif // WIN32
}

}
}
}