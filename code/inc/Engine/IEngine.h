#ifndef _EASY_CARD_IENGINE_H_
#define _EASY_CARD_IENGINE_H_

class IGameFactory;

namespace EasyCard
{
    class IEngine
    {
		virtual IGameFactory* GetGameFactory() = 0;
    };
}
#endif