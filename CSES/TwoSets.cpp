#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    long long sa = 0;
    long long sb = 0;
    vector<int>a;
    vector<int>b;
    for(int i=n; i>0; i--)
    {
        if(sa <= sb)
        {
            a.push_back(i);
            sa += i;
        }
        else
        {
            b.push_back(i);
            sb += i;
        }
    }
    if(sa == sb)
    {
        cout<<"YES"<<endl;
        cout<<a.size()<<endl;
        for(auto i: a)
            cout<<i<<" ";
        cout<<endl;
        cout<<b.size()<<endl;
        for(auto i: b)
            cout<<i<<" ";
        cout<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
}