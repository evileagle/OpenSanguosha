#include "game_imp.h"
#include <assert.h>
#include "lua/lauxlib.h"

namespace EasyCard{

CGame::CGame()
{
        
}

CGame::CGame( const char* name )
{
    set_name(name);
}

CGame::~CGame()
{

}


EasyCard::ecode CGame::Load()
{
}

}