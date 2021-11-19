#include<iostream>
#include<map>
#include<vector>
#include<set>
using namespace std;
int main()
{
    long long n, x;
    cin>>n>>x;
    vector<long long> v;
    set<long long> s;
    long long val;
    for(int i=0; i<n; i++)
    {
        cin>>val;
        v.push_back(val);
        s.insert(val);
    }
    map<long long, vector<int>>mp;
    for(auto i: s)
    {
        vector<int>temp;
        mp[i] = temp;
    }
    for(int i=0; i<n; i++)
    {
        mp[v[i]].push_back(i);
    }
    int pos = 0;
    for(auto i: s)
    {
        long data = x-i;
        if(s.find(data) == s.end())
            continue;
        else
        {
            if(data == i && mp[i].size()>1)
            {
                cout<<mp[i][0]+1<<" "<<mp[i][1]+1<<endl;
                pos++;
            }
            else if(data != i)
            {
                cout<<mp[i][0]+1<<" "<<mp[data][0]+1<<endl;
                pos++;
            }
            else
                continue;
        }
    }
    if(pos==0)
        cout<<"IMPOSSIBLE"<<endl;
    return 0;
}