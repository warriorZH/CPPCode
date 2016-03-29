#include <iostream>
#include <list>
#include <algorithm>
#include <string>

using namespace std;

void f(string s)
{
    char pre_rec;
    char cur_rec;
    int opt_num = 0;
    int i=1;
    cur_rec = s[0];
    while(i<s.length())
    {
        pre_rec = cur_rec;
        cur_rec=s[i];
        if((cur_rec == '.')&&(pre_rec == '.'))
        {
            opt_num++;
        }
    }
    cout<<opt_num<<endl;
}

int main()
{
    int str_len=0;
    int opt_num=0;
    string in_str;
    string tmp_str;
    int opt_index_tmp;
    char opt_cont_tmp;
    int i =0;
    list<int> opt_index;
    list<int>::const_iterator itr_index;
    list<char> opt_cont;
    list<char>::const_iterator itr_cont;

    while(cin>>str_len>>opt_num)
    {
        cin>>in_str;
        opt_index.clear();
        opt_cont.clear();
        i=0;
        while(opt_num-i>0)
        {
            i++;
            cin>>opt_index_tmp>>opt_cont_tmp;
            opt_index.push_back(opt_index_tmp);
            opt_cont.push_back(opt_cont_tmp);
        }
        tmp_str=in_str;
        i=0;
        itr_index = opt_index.begin();
        itr_cont = opt_cont.begin();
        while(opt_num-i>0)
        {
            tmp_str[*itr_index-1] = *itr_cont;
            f(tmp_str);
            tmp_str=in_str;
            itr_index++;
            itr_cont++;
        }

    }
    cout << "Hello world!" << endl;
    return 0;
}
