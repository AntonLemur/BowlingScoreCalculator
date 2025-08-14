#include <iostream>
#include "calculate.h"


std::string calculate_score()
{
    std::string tmp_string = "Hello from ";
    tmp_string.append(__FUNCTION__);

    return tmp_string;
}
