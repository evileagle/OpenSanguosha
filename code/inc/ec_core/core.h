#ifndef _EASY_CARD_CORE_H_
#define _EASY_CARD_CORE_H_


namespace EasyCard
{
    class IGameFactory;

    class ICore
    {
		virtual IGameFactory* GetGameFactory() = 0;
    };
}
#endif