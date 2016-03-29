#include <iostream>
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
template <class T>
class Multiple
{
    private:
        T theValue;
    public:
    Multiple(const T v)
    {
        theValue = v;
    }
    void operator()(T& elem) const
    {
        elem*=theValue;
    }
};
int main()
{
    vector<int> myVector;
    FillValue(myVector,1,10);
    for_each(myVector.begin(), myVector.end(), printValue);
    cout<<endl;
    Multiple<int> mul1(2);
    Multiple<int> mul2(10);
    for_each(myVector.begin(), myVector.end(), mul1);
    for_each(myVector.begin(), myVector.end(), printValue);
    cout<<endl;
    for_each(myVector.begin(), myVector.end(), mul2);
    for_each(myVector.begin(), myVector.end(), printValue);
    cout<<endl;
    cout << "Hello world!" << endl;
    return 0;
}
