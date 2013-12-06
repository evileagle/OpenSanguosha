#ifndef _PLATFORM_COMMON_CONTAINER_TEMPLATE_H_
#define _PLATFORM_COMMON_CONTAINER_TEMPLATE_H_

namespace EasyCard
{

    template<typename T>
    class Container
    {
    public:
        class Iterator
        {
        public:
            T& Get();
            bool HasNext();
            void Next();
        };
        Iterator First();
        Iterator Last();
        void Add(T& item);
        void Remove(Iterator& iter);
        void Random();
        bool TryLock();
        void Unlock();
    };
}

#endif