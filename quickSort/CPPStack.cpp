/*****************************
filename: CPPStack.cpp
description: realize stack operate in CPP
                like, stack struct; push; pop; isEmpty; clear;
                size; print
author: warrior mail:15933533880@163.com
date:2016-1-31
log:
*****************************/

/******  include  *******/
#include "CPPStack.h"
using namespace std;
/****** define *********/
/****** variable ********/
/****** function *******/
/****************
description: stack operate class constructor
input:
    none
output:
    none
****************/
CPPStack::CPPStack()
{
    p_top = NULL;
}
CPPStack::CPPStack(const CPPStack & otherStack)
{
    *this = otherStack;
}

/****************
description: reset operator '=' for stack
input:
    const CPPStack otherStack : the right value of '='
output:
    CPPStack
****************/
CPPStack CPPStack::operator=(const CPPStack & otherStack)
{
    CPPStack temporaryStack;
    Item* copyElement = otherStack.p_top;

    while(copyElement)
    {
        temporaryStack.push(copyElement->data);
        copyElement = copyElement->p_next;
    }

    copyElement = temporaryStack.p_top;

    while(copyElement)
    {
        this->push(copyElement->data);
        copyElement = copyElement->p_next;
    }
    return *this;
}

/****************
description: insert one element into stack
input:
    const int x : the value to be insert into stack
output:
    none
****************/
void CPPStack::push(const int x)
{
    Item *temporaryElement;
    temporaryElement = new Item;
    temporaryElement->data = x;
    if(this->p_top != NULL)
    {
        temporaryElement->p_next = this->p_top;
        this->p_top = temporaryElement;
    }
    else
    {
        this->p_top = temporaryElement;
        this->p_top->p_next = NULL;
    }
    printf("push stack data: %d \n", temporaryElement->data);
}
/****************
description: get one element from stack
input:
    const int & x : storage the value get from stack into x
output:
    ture:success
    false:error
****************/
bool CPPStack::pop(int &x)
{
    if(this->p_top != NULL)
    {

        x = this->p_top->data;
        this->p_top = this->p_top->p_next;
        printf("pop stack data: %d \n", x);
        return true;
    }
    else
    {
        return false;
    }
}
/****************
description: judge whether stack empty
input:
    none
output:
    ture:not empty
    false:empty
****************/
bool CPPStack::isEmpty()
{
    if(this->p_top != NULL)
    {return true;}
    else
    {return false;}
}
/****************
description: clear all element of stack
input:
    none
output:
    none
****************/
void CPPStack::clearStack()
{
    Item* tempElement;
    while(this->p_top)
    {
        tempElement = this->p_top;
        this->p_top = this->p_top->p_next;
        delete tempElement;
    }
}
/****************
description: test the size of stack
input:
    none
output:
    int lenght
****************/
int CPPStack::sizeStack()
{
    int counter = 0;
    Item* tempElement;
    tempElement = this->p_top;
    while(tempElement)
    {
        counter++;
        tempElement = tempElement->p_next;
    }
    return counter;
}
/****************
description: print all elements of stack
input:
    none
output:
    none
****************/
void CPPStack::printStack()
{
    Item* tempElement = this->p_top;
    while(tempElement)
    {
        printf("  %d\n",tempElement->data);
        tempElement = tempElement->p_next;
    }
}

CPPStack::~CPPStack()
{
    Item* tempElement;
    while(this->p_top)
    {
        tempElement = this->p_top;
        this->p_top = this->p_top->p_next;
        delete tempElement;
    }
}
