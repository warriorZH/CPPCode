#include "maxSubArry.h"

using namespace std;
using namespace boost;

int main()
{
    list<int> max_sub_result;
    int max_sum = 0;
    maxSubArry max_sub;
    max_sub.input();
    max_sub.dynamic_solve(max_sub_result);
    max_sum = max_sub.divide_solve(int(max_sub.int_list.size()), max_sub.int_list.begin(), max_sub.int_list.end());
    cout<<"the max sum value: "<<max_sum<<endl;
    return 0;
}
