#include "ec_core.h"

namespace EasyCard{
namespace Core{

ICore* GetCore()
{
    return CECCore::GetInstace();
}

}
}