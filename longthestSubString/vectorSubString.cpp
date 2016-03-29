/****************************
file description: use dynamic programming to solve it
author: warrior mail:15933533880@163.com
date:2016-3-23
log:
****************************/

#include "vectorSubString.h"
using namespace std;
using namespace boost;
/****************
description: get input vector
input:
    none
output:
    none
****************/
//template <class T>
void vecSubString::input()
{
    cout<<"please input list1, like a b c: ";
    string line1;
    cin>>line1;
    string line2;
    cout<<"please input list2, like b c d: ";
    cin>>line2;
    char tmp;
    //get list1 to vec
    string::const_iterator sstart = line1.begin();
    string::const_iterator send = line1.end();
    const regex pattern("\\w+");
    smatch sm;
    while(regex_search(sstart, send, sm, pattern))
    {
        sstart = sm[0].second;
        this->mainList1.push_back(sm[0]);
    }
    cout<<endl;

    //get list2 to vec
    sstart = line2.begin();
    send = line2.end();
    while(regex_search(sstart, send, sm, pattern))
    {
        sstart = sm[0].second;
        this->mainList2.push_back(sm[0]);
    }
    cout<<endl;
}

/****************
description: use dynamic programming to search longthest sub string
input:
    none
output:
    none
****************/
//template <class T>
void vecSubString::dynamicProgramming(vector<string> &RES)
{
    int len_vec_one = this->mainList1.size();
    int len_vec_two = this->mainList2.size();
    cout<<"one lenght: "<<len_vec_one<<endl;
    cout<<"two lenght: "<<len_vec_two<<endl;
    for(vector<string>::iterator it=mainList1.begin();it!=mainList1.end();++it)
    {
        cout<<*it;
    }
    cout<<endl;
    for(vector<string>::iterator it=mainList2.begin();it!=mainList2.end();++it)
    {
        cout<<*it;
    }
    cout<<endl;
    int record_arr[len_vec_one+1][len_vec_two+1];
    bool flag_arr[len_vec_one][len_vec_two];
    for(int i=0;i<len_vec_one;i++)
        for(int j=0; j<len_vec_two;j++)
            flag_arr[i][j]=0;

    //initial boundary
    for(int i=0; i<=len_vec_one; i++)
    {
        for(int j=0; j<=len_vec_two; j++)
        {
            record_arr[i][j] = 0;
        }
    }

    bool find_flag = 0;
    //calculate optimize value
    for(int i=len_vec_one-1; i>=0; i--)
    {
        find_flag = 0;
        for(int j=len_vec_two-1; j>=0; j--)
        {
//            cout<<mainList1[i]<<"&&"<<mainList2[j]<<endl;
            if(this->mainList1[i] == this->mainList2[j])
            {
                if(find_flag == 0)
                {
                    find_flag = 1;
                    RES.push_back(mainList1[i]);
                }
                flag_arr[i][j] = 1;
                record_arr[i][j] = record_arr[i+1][j+1]+1;

            }
            else
            {
                if(record_arr[i][j+1]>record_arr[i+1][j])
                {
                    record_arr[i][j] = record_arr[i][j+1];
                }
                else
                {
                    record_arr[i][j] = record_arr[i+1][j];
                }
            }
        }
    }

    //output calculate process
    for(int i=0; i<=len_vec_one; i++)
    {
        for(int j=0; j<=len_vec_two; j++)
        {
            cout<<record_arr[i][j]<<"  ";
        }
        cout<<endl;
        cout<<endl;
    }
     //output calculate process
    for(int i=0; i<len_vec_one; i++)
    {
        for(int j=0; j<len_vec_two; j++)
        {
            cout<<flag_arr[i][j]<<"  ";
        }
        cout<<endl;
        cout<<endl;
    }

    for(vector<string>::iterator it=RES.end(); it!=RES.begin(); )
    {
        --it;
        cout<<*it;
    }
}

//template <class T>
vecSubString::vecSubString()
{
    ;
}
//
//template <class T>
vecSubString::~vecSubString()
{
    mainList1.clear();
    mainList2.clear();
    subString.clear();
}
