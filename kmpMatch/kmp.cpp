/*****************************
filename: kmp.cpp
description: realize the kmp match algorithm
author: warrior mail:15933533880@163.com
date:2016-3-12
log:
*****************************/

/******  include  *******/
#include "kmp.h"
using namespace std;
/****** define *********/
/****** variable ********/
/****** function *******/
/****************
description: get the max prefix of any index of pattern
input:
    string str_pattern
    int * prefixRecord
output:
    none
****************/
void MaxPrefix(char * str_pattern, int * prefixRecord)
{
    int lastPrefixRecord = 0; //k
    int currentIndex = 0; //m
    char curr_char = 'a';
    if((str_pattern==NULL)|(prefixRecord==NULL))
    {
        cout<<"input error!!"<<endl;
        return ;
    }
    lastPrefixRecord = 0;
    prefixRecord[0]=1;
    currentIndex = 2;
    curr_char = str_pattern[currentIndex-1];
    while(curr_char!='\0')
    {
        if(str_pattern[lastPrefixRecord]==curr_char)
            lastPrefixRecord += 1;
        else
            lastPrefixRecord = 0;

        prefixRecord[currentIndex-1] = currentIndex - lastPrefixRecord;
        currentIndex += 1;
        curr_char = str_pattern[currentIndex-1];
    }
}
