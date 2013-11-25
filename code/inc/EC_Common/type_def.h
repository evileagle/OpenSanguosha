#ifndef _EASY_CARD_COMMON_TYPE_DEFINE_H_
#define _EASY_CARD_COMMON_TYPE_DEFINE_H_

#include <vector>
using namespace std;

namespace EasyCard
{
    typedef enum ecode
    {
        EC_SUCESS = 0,
    };

    typedef vector<void*> ptr_vector;
    typedef vector<string> string_vector;
    typedef vector<int>     int_vector;
    typedef vector<long>    long_vector;
    typedef vector<unsigned int>    uint_vector;
    typedef vector<unsigned long> ulong_vector;
}

#endif