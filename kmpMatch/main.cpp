#include "kmp.h"
#include <string.h>
using namespace std;

int main()
{

    string str_1("abcdabcabcdaef");
    char *str_2 = new char[str_1.length()];
    strcpy(str_2, str_1.c_str());
    int* preARR = new int[str_1.length()];
    MaxPrefix(str_2, preARR);
    for(int i=0 ;i<str_1.length(); i++)
    {
        cout<<"  "<<preARR[i];
    }
    cout<<endl;
    delete str_2;
    return 0;
}
