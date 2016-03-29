/*****************************
filename: kmp.cpp
description: use dynamic algorithm solute longthest commen sub string
author: warrior mail:15933533880@163.com
date:2016-3-16
log:
*****************************/


/******  include  *******/
#include "intSubString.h"
using namespace std;

/****** define *********/
/****** variable ********/
/****** function *******/

/****************
description: create matrix of record of sub string
input:
    string str_pattern
    int * prefixRecord
output:
    num: length of commen sub list
****************/
int getIntSubList(const int* listIN_1, const int* listIN_2, int* listOUT)
{
    if(listIN_1==NULL)|(listIN_2==NULL)|(listOUT==NULL))
    {
        printf("input error!!");
        return NULL;
    }
    const int len_1 = sizeof(listIN_1)/sizeof(int);
    const int len_2 = sizeof(listIN_2)/sizeof(int);
    int len_result = 0;
    //构造存储list匹配结果的矩阵
    vector<vector<int> > matrix_record(len_1+1);
    for(int i=0; i<len_1+1; i++)
    {
        matrix_record[i].resize(len_2+1);
    }
    //初始化边界
    for(i=0; i<len_2+1; i++)
    {
        matrix_record[len_1][i] = 0;
    }
    for(i=0; i<len_1+1; i++)
    {
        matrix_record[i][len_1] = 0;
    }





}
/****************
description: print a matrix
input:
    matrixIN;  to be output matrix
    row
    column
output:
    none
****************/
template <class T>
void printMatrix(const T* matrixIN, const int row, const int column)
{
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<column; j++)
        {
            printf("")
        }
    }
}
