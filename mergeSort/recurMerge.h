#ifndef _RECURMERGE_H_
#define _RECURMERGE_H_
/******  include  *******/
#include <iostream>
#include <stdio.h>
#include<fstream>
/****** define *********/
/****** variable ********/
/****** function *******/
void recurMergeSort(int* arrIN, const int leftSide, const int rightSide);
void mergeTwo2One(
                int * arrOUT, const int arrOUT_start,
                int * arrIN1, const int arrIN1_start, const int arrIN1_end,
                int * arrIN2, const int arrIN2_start, const int arrIN2_end);
#endif // _RECURMERGE_H_

