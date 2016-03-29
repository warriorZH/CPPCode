#include <iostream>
#include <list>
#include <algorithm>
#include <iomanip>


using namespace std;

class searchFlower
{
    private:
    list<int> flower_data;
    list<int> res_data;
    public:
    void create_flower_data()
    {
        for(int it=100; it<1000; it++)
        {
            int ge = it%10;
            int shi = (it/10)%10;
            int bai = it/100;
            if(it == (pow(ge,3)+pow(shi,3)+pow(bai,3)))
            {
                this->flower_data.push_back(it);
            }
        }
    }
    void search_flower_data(int const start_value, int const end_value)
    {
        this->res_data.clear();
        for(int it=start_value; it<end_value; it++)
        {
            if(find(this->flower_data.begin(), this->flower_data.end(), it) != this->flower_data.end())
            {
                this->res_data.push_back(it);
            }
        }
        if(!this->res_data.empty())
        {
            for(list<int>::const_iterator itr=this->res_data.begin(); itr!=this->res_data.end(); ++itr)
            {
                cout<<*itr<<"  ";
            }
            cout<<endl;
        }
        else
        {
            cout<<"no"<<endl;
        }

    }
};

void get_serial_sum(int const n, int const m)
{
    list<double> serial_list;
    double tmp = n;
    double sum;
    if((m<=n)&&(m>0)&&(n>0))
    {
        serial_list.push_back(tmp);
        for(int i=1; i<m; i++)
        {
            tmp = sqrt(tmp);
            serial_list.push_back(tmp);
        }
        for(list<double>::const_iterator itr=serial_list.begin(); itr!=serial_list.end(); ++itr)
        {
            sum += *itr;
        }
        cout<<setiosflags(ios::fixed);
        cout<<setprecision(2)<<sum;
    }
    else
    {
        cout<<"error!!";
    }
}

int main()
{
    int start_value, end_value;
//    searchFlower sf;
//    sf.create_flower_data();
//    while(cin>>start_value>>end_value)
//    {
//        sf.search_flower_data(start_value, end_value);
//    }

    while(cin>>start_value>>end_value)
    {
        get_serial_sum(start_value, end_value);
    }
    return 0;
}
