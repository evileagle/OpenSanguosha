#ifndef _EASY_CARD_COMMON_INTERFACE_H_
#define _EASY_CARD_COMMON_INTERFACE_H_

#include "boost/uuid/uuid.hpp"

namespace EasyCard{

class Interface
{
public:
    int QueryInterface(boost::uuids::uuid iid, void** object) = 0;
};

}

#endif