#ifndef _PLATFORM_TYPE_DEFINE_H_
#define _PLATFORM_TYPE_DEFINE_H_

#include <vector>
using namespace std;

namespace Platform
{
    typedef unsigned long ulong;
    typedef unsigned int uint;
    typedef vector<void*> ptr_vector;
    typedef vector<string> string_vector;
    typedef vector<int>     int_vector;
    typedef vector<long>    long_vector;
    typedef vector<uint>    uint_vector;
    typedef vector<ulong> ulong_vector;
}

#endif