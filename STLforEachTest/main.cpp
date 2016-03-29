#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <class T>

void InputValue(T& vect, int first, int last)
{
    if(last>=first)
    {
        for(int i=first;i<=last;i++)
        {
            vect.insert(vect.end(),i);
        }
    }
    else
    {
        cout<<"parameter error!!"<<endl;
    }
}
void printValue(int elem)
{
    cout<<elem<<" ";
}
void addValue(int &elem)
{
    elem *= 3;
}
int main()
{
    vector <int> myvector;
    InputValue(myvector,1,10);
    for_each(myvector.begin(),myvector.end(),addValue);
    for_each(myvector.begin(), myvector.end(), printValue);
    cout << "Hello world!" << endl;
    return 0;
}
