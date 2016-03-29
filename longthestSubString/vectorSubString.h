#ifndef _VECTORSUBSTRING_H_

#define _VECTORSUBSTRING_H_
#include <iostream>
#include <vector>
#include <boost/regex.hpp>
#include <string>
using namespace std;

class vecSubString
{
    private:
    vector<string> mainList1;
    vector<string> mainList2;
    vector<string> subString;
    protected:

    public:

    vecSubString();
    void input();
    void dynamicProgramming(vector<string> & RES);
    ~vecSubString();

};


#endif // _VECTORSUBSTRING_H_
