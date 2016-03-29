/****************************
file description: get the max sub arry
author: warrior mail:15933533880@163.com
date:2016-3-24
log:
****************************/

#include "maxSubArry.h"

using namespace std;
using namespace boost;

/****************
description: get input list
input:
    none
output:
    none
****************/
void maxSubArry::input()
{
    string stringInput;
    cout<<"please input int arry: ";
    cin>>stringInput;

    regex pattern("((-)(\\d+))|(\\d+)");
    string::const_iterator sstart = stringInput.begin();
    string::const_iterator send = stringInput.end();
    smatch sm;
    int itmp=0;
    while(regex_search(sstart, send, sm, pattern))
    {
//        cout<<sm[0]<<"  ";
        sstart = sm[0].second;
        stringstream ss;
        ss<<sm[0];
        ss>>itmp;
//        itmp = lexical_cast<int>(sm[0]);
//        cout<<itmp<<"  ";
        this->int_list.push_back(itmp);
//        cout<<endl;
    }
}
/****************
description: get length of list
input:
    none
output:
    none
****************/
int maxSubArry::getListLen()
{
    return this->int_list.size();
}
/****************
description: use divide to get max sub
input:
    RES: sotrage the max sub arry list
output:
    none
****************/
int maxSubArry::divide_solve(int list_len, list<int>::const_iterator itL, list<int>::const_iterator itR)
{
    int maxL, maxR;
    int sum_both = 0;
    int max_right, max_left, max_both;
    list_len = list_len/2;
    if(list_len>0)
    {

        list<int>::const_iterator itRR = itR;
        for(int i=0;i<list_len;i++)
        {
            itRR--;
        }
        maxL = divide_solve(list_len, itL, itRR);
        list<int>::const_iterator itLL = itL;
        for(int i=0;i<list_len;i++)
        {
            itLL++;
        }
        maxR = divide_solve(list_len, itLL, itR);

        //get max left+right
        sum_both = 0;
        max_right = MIN_VALUE;
        for(list<int>::const_iterator it=itRR; it!=itR; ++it)
        {
            sum_both += *it;
            if(sum_both>max_right)
            {
                max_right = sum_both;
            }
        }
        sum_both = 0;
        max_left = MIN_VALUE;
        for(list<int>::const_iterator it=itL; it!=itRR; ++it)
        {
            sum_both += *it;
            if(sum_both>max_left)
            {
                max_left = sum_both;
            }
        }
        max_both = max_left+max_right;

        if(max_both>maxL)
        {
            if(max_both>maxR)
                return max_both;
            else
                return maxR;
        }
        else
        {
            if(maxL>maxR)
                return maxL;
            else
                return maxR;
        }

    }

}
/****************
description: use dynamic to get max sub
input:
    RES: sotrage the max sub arry list
output:
    none
****************/
void maxSubArry::dynamic_solve(list<int>& RES)
{
    int len_list = this->int_list.size();
    cout<<"list length: "<<len_list;
    int cur_sum = 0;
    int max_sum = 0;
    for(list<int>::const_iterator it=this->int_list.begin(); it!=this->int_list.end(); ++it)
    {
        cur_sum += *it;
        RES.push_back(*it);
        if(cur_sum<0)
        {
            cur_sum = 0;
            RES.clear();
        }
        if(cur_sum>max_sum)
        {
            max_sum = cur_sum;
            for(list<int>::const_iterator it=RES.begin(); it!=RES.end(); ++it)
            {
                cout<<*it<<"  ";
            }
            cout<<endl;
        }
    }
    cout<<"max sub sum: "<<max_sum<<endl;
}




