#ifndef _MAXSUBARRY_H_
#define _MAXSUBARRY_H_
//include
#include <list>
#include <iostream>
#include <string>
#include "boost/regex.hpp"
#include "boost/lexical_cast.hpp"
#include <cstdlib>
#include <sstream>

#define MIN_VALUE -100000000 //负1亿
using namespace std;
using namespace boost;

class maxSubArry
{
    private:

    list<string> string_list;
    protected:

    public:
    list<int> int_list;
    void input();
    int getListLen();
    int divide_solve(int list_len, list<int>::const_iterator itL, list<int>::const_iterator itR);
    void dynamic_solve(list<int> &RES);
};


#endif // _MAXSUBARRY_H_
