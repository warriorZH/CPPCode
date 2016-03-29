#ifndef _CPPSTACK_H_
#define _CPPSTACK_H_
/******  include  *******/
#include <iostream>
#include <stdio.h>
/****** define *********/
/****** variable ********/
struct Item
{
    int data;
    Item* p_next;
};

class CPPStack
{
public:
    CPPStack();
    CPPStack(const CPPStack & otherStack);//constructor reset
    CPPStack operator = (const CPPStack & otherStack);//'=' reset
    void push(int x);//in stack
    bool pop(int &x);//out stack
    bool isEmpty();
    void clearStack();
    int sizeStack();
    void printStack();
    ~CPPStack();
public:
    Item* p_top;//stack top
};
/****** function *******/
#endif // _CPPSTACK_H_
