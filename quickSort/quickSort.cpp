/*****************************
filename: quickSort.cpp
description: permutation a list of integers in O(1) and no recursion
author: warrior mail:15933533880@163.com
date:2016-1-30
log:
*****************************/

/******  include  *******/
#include "quickSort.h"
#include "CPPStack.h"
using namespace std;
/****** define *********/
/****** variable ********/

/****** function *******/
/****************
description: permutation a list of integers in O(1) and no recursion
input:
    int* arrIN : the in put interger array
    int arrLength : length of array "arrIN"
output:
    0:run error
    1:run success
****************/
bool quickSort(int* arrIN, int arrLength)
{
    int supportElement;
    int emptySign = 0;
    int lowRecord = 0;
    int highRecord = 0;
    int temp;
    int lowSign = 0;
    int highSign = arrLength-1;
    CPPStack quickSortStack;
    if(arrIN==NULL)
    {return 0;}

    quickSortStack.push(arrLength-1);
    quickSortStack.push(0);

    while(quickSortStack.isEmpty())
    {
        quickSortStack.pop(lowSign);
        quickSortStack.pop(highSign);

        lowRecord = lowSign;
        highRecord = highSign;
        emptySign = lowSign;
        supportElement = arrIN[emptySign];

        if(highSign-lowSign>1)
        {
            while(lowSign<highSign)
            {
                //search from high
                while((lowSign<highSign) && (supportElement<=arrIN[highSign]))
                {
                    highSign--;
                    //printf(", %d\n", highSign);
                }
                if(lowSign<highSign)
                {
                    arrIN[emptySign] = arrIN[highSign];
                    emptySign = highSign;
                }
                //search from low
                while((lowSign<highSign) && (supportElement>=arrIN[lowSign]))
                {
                    lowSign++;
                    //printf(", %d\n", lowSign);
                }
                if(lowSign<highSign)
                {
                    arrIN[emptySign] = arrIN[lowSign];
                    emptySign = lowSign;
                }
            }
            arrIN[emptySign] = supportElement;
            printf("the sorting line:\n");
            for(int i = 0; i<arrLength; i++)
            {
                printf(", %d", arrIN[i]);
            }
            printf("\n");
            //push high
            quickSortStack.push(highRecord);
            if(lowSign == highRecord)
                quickSortStack.push(lowSign);
            else
                quickSortStack.push(lowSign+1);
            //push low
            if(lowSign == lowRecord)
                quickSortStack.push(lowSign);
            else
                quickSortStack.push(lowSign-1);
            quickSortStack.push(lowRecord);

        }
        else
        {
            if(arrIN[lowSign]>arrIN[highSign])
            {
                temp = arrIN[highSign];
                arrIN[highSign] = arrIN[lowSign];
                arrIN[lowSign] = temp;
            }
        }
    }
    printf("the sorted line:\n");
    for(int i = 0; i<arrLength; i++)
    {
        printf(", %d", arrIN[i]);
    }
    printf("\n");
}
