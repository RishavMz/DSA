#include<iostream>
#include<set>
#include<algorithm>
using namespace std;
int main()
{
    int n, m;
    cin>>n>>m;
    multiset<long long>v;
    long long val;
    for(int i=0; i<n; i++)
    {
        cin>>val;
        v.insert(val);
    }
    for(int i=0; i<m; i++)
    {
        cin>>val;
        auto it = v.upper_bound(val);
        if(it == v.begin())
            cout<<-1<<endl;
        else
        {
            cout<<*(--it)<<endl;
            v.erase(it);
        }
    }
    return 0;
}