#include <iostream>
#include <numeric> //accumalate
#include "calculate.h"

using namespace std;

unsigned short calculate_score(vector<unsigned short>& frame)
{
    unsigned short result=0;

    result=accumulate(frame.begin(),frame.end(),0);

    return result;
}