#ifndef _EASY_CARD_CORE_ROUND_LOOP_H_
#define _EASY_CARD_CORE_ROUND_LOOP_H_

#include "ec_common/type_def.h"

namespace EasyCard{

class Game;
class RoundLoop
{
public:
    RoundLoop();
    ~RoundLoop();
    bool Init(Game* game);
    size_t Current();
    void AddRound(size_t index, size_t pos, bool temp);
    void Start();
    void Dispose();
    static const size_t ROUND_BEGIN;
    static const size_t ROUND_END;
private:

    struct Round
    {
        size_t index_;
        bool temp_;
        Round(size_t index, bool temp)
        {
            index_ = index;
            temp_ = temp;
        }
    };

    Game* game_;
    Round* current_;
    ptr_queue round_queue_;
    
};

}


#endif