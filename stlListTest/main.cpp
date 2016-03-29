#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

//template <class T>
void printlist(string elem)
{
    cout<<elem<<endl;
}

int main()
{
    list<string> mylist;
    mylist.push_back("I am tired today!!");
    mylist.push_back("I want to sleep!!");
    mylist.push_front("oh huhu!!");
    mylist.push_front("oh haha!!");
    mylist.push_back("Why dose it??");
    for_each(mylist.begin(), mylist.end(), printlist);
    cout<<"###################"<<endl;
    while(!mylist.empty())
    {
        cout<<mylist.back()<<endl;
        mylist.pop_back();
    }
    cout << "Hello world!" << endl;
    return 0;
}
