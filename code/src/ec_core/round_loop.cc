#include "round_loop.h"
#include <assert.h>
#include "ec_common/type_def.h"
#include "game_imp.h"
#include "lua_loader/round_loader.h"
#include "ec_core.h"

namespace EasyCard{
using namespace LuaLoader;
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
    LoadRound(CECCore::GetInstace()->GetLua());
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

void RoundLoop::Start()
{
    bool next = true;
    while (next)
    {
        Round* round = (Round*)round_queue_.front();
        round_queue_.pop_front();
        current_ = round;
        next = CallRound(CECCore::GetInstace()->GetLua());
        current_ = NULL;
        if (round->temp_)
        {
            delete round;
            continue;
        }
        round_queue_.push_back(round);
    }
}

void RoundLoop::Dispose()
{
    DisposeRound(CECCore::GetInstace()->GetLua());
    while (!round_queue_.empty())
    {
        Round* round = (Round*)round_queue_.front();
        round_queue_.pop_front();
        delete round;
    }
    assert(current_ == NULL);
}

}

