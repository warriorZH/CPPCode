#include "vectorSubString.h"
#include <iostream>
#include <string>
#include "boost/regex.hpp"

using namespace std;
using namespace boost;


int main()
{
    vector<string> charVec;
    vecSubString subString;
    subString.input();
    subString.dynamicProgramming(charVec);
    return 0;
}
