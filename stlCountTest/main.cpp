#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>

using namespace std;

template <class T>
void FillValue(T& vect, int first, int last)
{
    if(last>=first)
    {
        for(int i=first;i<=last;i++)
        {
            vect.insert(vect.end(), i);
        }
    }
    else
    {
        cout<<"the indexes id error: last<first"<<endl;
    }

}
void printValue(int elem)
{
    cout<<elem<<" ";
}

bool isEven(const int elem)
{
    return elem%2==0;
}
int main()
{
    vector <int> myvect;
    FillValue(myvect,1,10);
    for_each(myvect.begin(), myvect.end(), printValue);
    cout<<endl;
    int ct = count(myvect.begin(), myvect.end(), 4);
    int ctif = count_if(myvect.begin(), myvect.end(), isEven);
    int ctg = count_if(myvect.begin(), myvect.end(), bind2nd(greater<int>(), 3));
    cout<<"$$"<<ct<<"$$"<<ctif<<"$$"<<ctg<<endl;
    cout << "Hello world!" << endl;
    return 0;
}
