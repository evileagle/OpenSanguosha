#ifndef _EASY_CARD_CORE_ROUND_LOOP_H_
#define _EASY_CARD_CORE_ROUND_LOOP_H_

namespace EasyCard{

    class Game;
    class RoundLoop
    {
    public:
        bool Init(Game* game);
        size_t Current();
        void PushNext(size_t index);
        void Start();
    private:
        Game* game_;
    };

}


#endif