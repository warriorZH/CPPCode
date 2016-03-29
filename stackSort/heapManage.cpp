/*****************************
filename: HeapManage.cpp
description: realize heap operate in CPP
                like, create heap , modify heap
author: warrior mail:15933533880@163.com
date:2016-2-20
log:
*****************************/

/******  include  *******/
#include "heapManage.h"
using namespace std;
/****** define *********/
/****** variable ********/
/****** function *******/
/****************
description: sort a int list by heap sort
input:
    int * arrIN
    const int arrLength
output:
    none
****************/
void heapSort(int* arrIN, const int arrLength)
{
    int heapLength = arrLength;
    int tempItem;
    createHeap(arrIN, arrLength);
    for(int i=0; i<arrLength; i++)
    {
        deleteMaxHeap(arrIN, heapLength);
    }
    for(int i=0; i<arrLength; i++)
    {
        cout<<" ,"<<arrIN[i];
    }
    cout<<endl;
}
/****************
description: create heap by int list
input:
    int * arrIN
    int arrLength
output:
    none
****************/
void createHeap(int* arrIN, const int arrLength)
{
    int heapLength = 0;
    for(int i=0; i<arrLength; i++)
    {
        insertMaxHeap(arrIN, arrIN[i], heapLength);
    }
    for(int i=0; i<arrLength; i++)
    {
         cout<<" ,"<<arrIN[i];
    }
    printf("lala\n");
}
/****************
description: insert one item to max heap
input:
    int * Heap
    int dataIN
    int &heapLength
output:
    none
****************/
void insertMaxHeap(int* Heap, int dataIN, int &heapLength)
{
    int iterationLength;
    int parentItem;
    int sunItem;
    int tempItem;
    heapLength++;
    iterationLength = heapLength;
    Heap[iterationLength-1] = dataIN;
    if(iterationLength==1)
        return;
    else
    {
         while(iterationLength>1)
        {
            parentItem = Heap[iterationLength/2 - 1];
            sunItem = Heap[iterationLength-1];
            if(parentItem < sunItem)
            {
                tempItem = parentItem;
                parentItem = sunItem;
                sunItem = tempItem;
                Heap[iterationLength/2 - 1] = parentItem;
                Heap[iterationLength-1] = sunItem;
            }
            else
                break;
            iterationLength = iterationLength/2;
        }
    }
}
/****************
description: delete one item to max heap
input:
    int * Heap
    int &heapLength
output:
    none
****************/
void deleteMaxHeap(int* Heap, int &heapLength)
{
    int iterationLength;
    int parentItem;
    int sunItem;
    int tempItem;
    tempItem = Heap[0];
    Heap[0] = Heap[heapLength-1];
    Heap[heapLength-1] = tempItem;
    iterationLength = 1;
    heapLength--;
    while(iterationLength*2 <= heapLength)
    {
        if((iterationLength*2+1)<=heapLength)
        {
            if(Heap[iterationLength*2+1-1]>Heap[iterationLength*2-1])
            {
                if(Heap[iterationLength*2+1-1]>Heap[iterationLength-1])
                {
                    tempItem = Heap[iterationLength-1];
                    Heap[iterationLength-1] = Heap[iterationLength*2+1-1];
                    Heap[iterationLength*2+1-1] = tempItem;
                    iterationLength = iterationLength*2+1;
                }
                else
                    break;
            }
            else
            {
                if(Heap[iterationLength*2-1]>Heap[iterationLength-1])
                {
                    tempItem = Heap[iterationLength-1];
                    Heap[iterationLength-1] = Heap[iterationLength*2-1];
                    Heap[iterationLength*2-1] = tempItem;
                    iterationLength = iterationLength*2;
                }
                else
                    break;
            }
        }
        else
        {
            if(Heap[iterationLength*2-1]>Heap[iterationLength-1])
            {
                tempItem = Heap[iterationLength-1];
                Heap[iterationLength-1] = Heap[iterationLength*2-1];
                Heap[iterationLength*2-1] = tempItem;
                iterationLength = iterationLength*2;
            }
            else
                break;
        }
    }
    for(int i=0; i<heapLength; i++)
    {
        cout<<" ,"<<Heap[i];
    }
    cout<<"lulu"<<endl;

}

