#include "ec_core.h"

namespace EasyCard
{
ICore* GetCore()
{
    return CECCore::GetInstace();
}
}