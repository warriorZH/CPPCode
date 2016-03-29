/*****************************
filename: calculateLetterFrequency.cpp
description: given a string , calculate the frequency of characters ,
            output the array with the letter and frenquency.
author: warrior mail:15933533880@163.com
date:2016-1-30
log:
*****************************/

/******  include  *******/
#include "calculateLettterFrequency.h"
using namespace std;
/****** define *********/
/****** variable ********/
/****** function *******/
/****************
description: calculate letter frequency of string
input:
    char* str : the in put string
    int* arr : store frequency of letter
output:
    0:run error
    1:run success
****************/
bool calculateLetterFrequency(char * str, int * arr)
{
    int letterHash[27] = {0};
    int stringlength = 0;
    int temporary = 0;
    if (str==NULL || arr == NULL)
    {return 0;}
    stringlength = strlen(str);
    for(int i=0; i<stringlength; i++)
    {
        temporary = str[i]-'a';
        if(temporary>=0 && temporary<26)
        {
            letterHash[temporary]+=1;
        }
        else
        {letterHash[26]+=1;}
    }
    for(int i=0; i<27; i++)
    {arr[i]=letterHash[i];}
    return 1;
}
