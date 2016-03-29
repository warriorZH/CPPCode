/*****************************
filename: recurMerge.cpp
description: realize merge sort in recursion mode
author: warrior mail:15933533880@163.com
date:2016-2-21
log:
*****************************/

/******  include  *******/
#include "recurMerge.h"
using namespace std;
/****** define *********/
/****** variable ********/
/****** function *******/
/****************
description: realize merge sort in recursion mode
input:
    int * arrIN
    const int left
    const int right
output:
    none
****************/
void recurMergeSort(int* arrIN, const int leftSide, const int rightSide)
{
    int mid;
    if(leftSide<rightSide)
    {
        mid = (leftSide+rightSide)/2;
        recurMergeSort(arrIN, leftSide, mid);
        recurMergeSort(arrIN, mid+1, rightSide);
        mergeTwo2One(arrIN, leftSide,
                    arrIN, leftSide, mid,
                    arrIN, mid+1, rightSide);
    }
}
/****************
description: merge two sorted list to one sorted list
input:
    int * arrOUT, int arrOUT_start
    int * arrIN1, int arrIN1_start, int arrIN1_end
    int * arrIN2, int arrIN2_start, int arrIN2_end
output:
    none
****************/
void mergeTwo2One(
                int * arrOUT, const int arrOUT_start,
                int * arrIN1, const int arrIN1_start, const int arrIN1_end,
                int * arrIN2, const int arrIN2_start, const int arrIN2_end)
{
    int i,j,k=0;
    int tempARR[arrIN1_end-arrIN1_start + arrIN2_end-arrIN2_start +2];//= new int();
    i = arrIN1_start;
    j = arrIN2_start;
    k = 0;
    while((i<=arrIN1_end) && (j<=arrIN2_end))
    {
        if(arrIN1[i]<arrIN2[j])
        {
            tempARR[k] = arrIN1[i];
            k++;
            i++;
        }
        else
        {
            tempARR[k] = arrIN2[j];
            k++;
            j++;
        }
    }
    while(i<=arrIN1_end)
    {
        tempARR[k] = arrIN1[i];
        k++;
        i++;
    }
    while(j<=arrIN2_end)
    {
        tempARR[k] = arrIN2[j];
        k++;
        j++;
    }
    for(int h=0; h<k; h++)
    {
        arrOUT[arrOUT_start+h] = tempARR[h];
        cout<<" ,"<<tempARR[h];
    }
    cout<<endl;
    //delete tempARR;
}
