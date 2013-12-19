#ifndef _EASY_CARD_CORE_PLAYER_FACTORY_INTERFACE_H_
#define _EASY_CARD_CORE_PLAYER_FACTORY_INTERFACE_H_


namespace EasyCard{
namespace Core{

class IPlayer;
class IRpcClient;
class IPlayerFactory
{
public:
    virtual const IPlayer* Create(IRpcClient* client);
};

}
}
#endif