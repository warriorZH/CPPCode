#ifndef _HEAPMANAGE_H_
#define _HEAPMANAGE_H_
/******  include  *******/
#include <iostream>
#include <stdio.h>
/****** define *********/
/****** variable ********/
/****** function *******/
void heapSort(int* arrIN, const int arrLenght);
void createHeap(int* arrIN, const int arrLength);
void insertMaxHeap(int* Heap, int dataIN, int &heapLength);
void deleteMaxHeap(int* Heap, int &heapLength);
#endif // _HEAPMANAGE_H_
