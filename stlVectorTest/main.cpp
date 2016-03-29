#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<string> myvector;
    myvector.reserve(5);
    myvector.push_back("Hello world!!");
    myvector.push_back("I love U!!");
    myvector.push_back("I will go to a interview at friday!!");
    myvector.push_back("Good Luck!!");

    vector<string>::iterator ito;
    for(ito=myvector.begin(); ito!=myvector.end(); ito++)
    {
        cout<<*ito<<endl;
    }
    cout<<"size: "<<myvector.size()<<endl;
    cout<<"capacity: "<<myvector.capacity()<<endl;
    cout<<"max_size: "<<myvector.max_size()<<endl;

    myvector.resize(10);
    string temp;
    while(!myvector.empty())
    {
        temp = myvector.back();
        cout<<temp<<endl;
        myvector.pop_back();
    }

    myvector.push_back("Hello world!!");
    myvector.push_back("I love U!!");
    myvector.clear();
    cout<<"size: "<<myvector.size()<<endl;
    cout<<"capacity: "<<myvector.capacity()<<endl;
    cout<<"max_size: "<<myvector.max_size()<<endl;
    return 0;
}
