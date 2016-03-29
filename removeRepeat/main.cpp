#include <iostream>
#include <list>
#include "boost/regex.hpp"
#include <string>
#include <algorithm>

using namespace std;
using namespace boost;

class removeRepeat
{
    private:
    list<string> str_seg;
    list<string> rm_record;
    string test_str;
    protected:

    public:

    string input();
    list<string> word_seg(string const my_str);
    list<string> rm_repeat(const list<string> word_list);

};


//输入函数
string removeRepeat::input()
{
    cout<<"please input test string: ";
    getline(cin, this->test_str);//cin >> this->test_str;
    return this->test_str;
}


//对输入字符串进行分词和去除标点符号
list<string> removeRepeat::word_seg(string const my_str)
{
    string input_str = my_str;
    string::const_iterator sstart = input_str.begin();
    string::const_iterator send = input_str.end();
    const regex pattern("\\w+");
    smatch sm_buff;
    while(regex_search(sstart, send, sm_buff, pattern))
    {
        sstart = sm_buff[0].second;
        this->str_seg.push_back(sm_buff[0]);
    }
    return this->str_seg;
}


//对分词结果进行单词去重
list<string> removeRepeat::rm_repeat(const list<string> word_list)
{
    if(!word_list.empty())
    {
        for(list<string>::const_iterator it=word_list.begin(); it!=word_list.end(); ++it)
        {
            if(find(this->rm_record.begin(), this->rm_record.end(), *it) == this->rm_record.end())
            {
                this->rm_record.push_back(*it);
            }
        }
        return this->rm_record;
    }
}


int main()
{
    list<string> word_list;
    list<string> result;
    //测试字符串
    string test_string;
    removeRepeat rmrp;
    test_string = rmrp.input();
    cout<<test_string<<endl;
    word_list = rmrp.word_seg(test_string);
    //输出分词结果
    for(list<string>::const_iterator it=word_list.begin(); it!=word_list.end(); ++it)
        cout<<*it<<"  ";
    cout<<endl;
    result = rmrp.rm_repeat(word_list);
    //输出去重结果
    for(list<string>::const_iterator it=result.begin(); it!=result.end(); ++it)
        cout<<*it<<"  ";
    cout<<endl;
    return 0;
}
