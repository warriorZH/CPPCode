#include <iostream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

bool wordBreak(string s, set<string>& wordDict) {
    if((!s.empty()) && (wordDict.size()>0))
         {
         string my_s = s;
         string for_string;
         string bac_string;
         string::iterator fir;
         string::iterator sec;
         fir = my_s.begin();
         sec = my_s.end();
         while(1)
             {
             for_string.assign(fir, sec);
             if(wordDict.find(for_string) != wordDict.end())
                 {
                 //my_s.erase(fir, sec);
                 sec--;
                 fir = sec;
                 sec = my_s.end();
                 if(++fir == my_s.end())
                     {
                     return true;
                 }
             }
             else
                 {
                 if(sec == fir)
                     {
                     return false;
                 }
                 sec--;
             }
         }
     }
    return false;
}
int main()
{
    string my_str("aaaaaaa");
    set<string> my_dict;
    my_dict.insert("aaaa");
    my_dict.insert("aaa");
    if(wordBreak(my_str, my_dict))
        cout<<"good!!";
    else
        cout<<"bad!!";
    cout << "Hello world!" << endl;
    return 0;
}
