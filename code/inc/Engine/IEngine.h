#ifndef _EASY_CARD_IENGINE_H_
#define _EASY_CARD_IENGINE_H_


namespace EasyCard
{
    class IGameFactory;

    class IEngine
    {
		virtual IGameFactory* GetGameFactory() = 0;
    };
}
#endif