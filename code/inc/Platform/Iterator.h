#ifndef _PLATFORM_ITERATOR_TEMPLATE_H_
#define _PLATFORM_ITERATOR_TEMPLATE_H_

namespace Platform
{
    template <typename T>
    class Iterator
    {
    public:
        virtual T& Get() = 0;
        virtual bool HasNext() = 0;
        virtual void Next() = 0;
    };
}


#endif