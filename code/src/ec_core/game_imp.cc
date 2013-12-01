#include "game_imp.h"
#include <assert.h>
#include "lua/lauxlib.h"

namespace EasyCard{

CGame::CGame()
    : game_(NULL)
{
        
}

CGame::CGame( const char* name )
    : game_(NULL)
{
    set_name(name);
}

CGame::~CGame()
{

}


EasyCard::ecode CGame::Load()
{
    game_ = LoadGame(name_.c_str(), this);
}

}