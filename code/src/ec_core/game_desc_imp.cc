#include "game_desc_imp.h"
#include <assert.h>

#include "ec_common/type_def.h"

namespace EasyCard
{

    CGameDesc::CGameDesc()
        : m_number(0)
    {

    }

    CGameDesc::CGameDesc( const char* szName, const char* szDisplayName, size_t nPlayerNumber )
    {
        SetName(szName);
        SetDisplayName(szDisplayName);
        SetPlayerNumber(nPlayerNumber);
    }

    CGameDesc::~CGameDesc()
    {

    }

    const char* CGameDesc::GetName()
    {
        return m_name.c_str();
    }

    const char* CGameDesc::GetDisplayName()
    {
        return m_displayName.c_str();
    }

    size_t CGameDesc::GetPlayerNumber()
    {
        return m_number;
    }

    void CGameDesc::SetName( const char* szName )
    {
        assert(szName);
        if (szName != NULL)
        {
            m_name = szName;
        }
    }

    void CGameDesc::SetDisplayName( const char* szDisplayName )
    {
        assert(szDisplayName);
        if (szDisplayName != NULL)
        {
            m_displayName = szDisplayName;
        }
    }

    void CGameDesc::SetPlayerNumber( size_t nNumber )
    {
        m_number = nNumber;
    }

}