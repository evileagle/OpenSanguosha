#include "round_loop.h"
#include <assert.h>
#include "ec_common/type_def.h"
#include "game_imp.h"

namespace EasyCard{

const size_t RoundLoop::ROUND_BEGIN = 0;
const size_t RoundLoop::ROUND_END = -1;

RoundLoop::RoundLoop()
    : game_(NULL)
    , current_(NULL)
{

}

RoundLoop::~RoundLoop()
{
    game_ = NULL;
}

bool RoundLoop::Init( Game* game )
{
    assert(game != NULL);
    game_ = game;
    return true;
}

size_t RoundLoop::Current()
{
    assert(current_ != NULL);
    return current_->index_;
}

void RoundLoop::AddRound(size_t index, size_t pos, bool temp)
{
    Round* round = new Round(index, temp);
    if (round == NULL)
    {
        return;
    }
    if (pos == ROUND_BEGIN)
    {
        round_queue_.push_front(round);
    }
    else if (pos == ROUND_END)
    {
        round_queue_.push_back(round);
    }
}

}

