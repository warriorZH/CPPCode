/*****************************
filename: recurMerge.cpp
description: realize merge sort in iteration mode
author: warrior mail:15933533880@163.com
date:2016-2-21
log:
*****************************/

/******  include  *******/
#include "iteraMerge.h"
#include "recurMerge.h"
using namespace std;
/****** define *********/
/****** variable ********/
/****** function *******/
/****************
description: realize merge sort in iteration mode
input:
    int * arrIN
    const int arrLength
output:
    none
****************/
void iteraMergeSort(int* arrIN, const int arrLength)
{
    int stepLength = 1;
    int currentIndex = 0;
    int i=0;
    //ofstream outputFile;
    //outputFile.open("output.txt");
    while(stepLength<arrLength)
    {
        stepLength *= 2;
        mergeOnce(arrIN, arrLength, stepLength);
        cout<<"count "<<int(log(stepLength)/log(2))<<" :";
        //outputFile<<"count "<<int(log(stepLength)/log(2))<<" :";
        for(i=0; i<arrLength; i++)
        {
            cout<<" ,"<<arrIN[i];
            //outputFile<<" ,"<<arrIN[i];
        }
        //outputFile<<"\n";
        cout<<endl;
    }
    //outputFile.close();
    for(i=0; i<arrLength; i++)
    {
        cout<<" ,"<<arrIN[i];
    }
    cout<<endl;
}

/****************
description: excute once merge sort
input:
    int * arrIN
    const int arrLength
    const int stepLongth
output:
    none
****************/
void mergeOnce(int* arrIN, const int arrLength, const int stepLength)
{
    int iteratorNum = stepLength;
    int i=0;
    if(arrLength%iteratorNum == 0)
    {
        for(i=0; i<arrLength; i+=iteratorNum)
        {
            mergeTwo2One(
                        arrIN, i,
                        arrIN, i, i+iteratorNum/2-1,
                        arrIN, i+iteratorNum/2, i+iteratorNum-1);
        }
    }
    else
    {
        for(i=0; i<(arrLength-arrLength%iteratorNum); i+=iteratorNum)
        {
            mergeTwo2One(
                        arrIN, i,
                        arrIN, i, i+iteratorNum/2-1,
                        arrIN, i+iteratorNum/2, i+iteratorNum-1);
        }
        if(arrLength%iteratorNum > iteratorNum/2)
        {
            mergeTwo2One(
                        arrIN, i,
                        arrIN, i, i+iteratorNum/2-1,
                        arrIN, i+iteratorNum/2, arrLength-1);
        }
    }

}
