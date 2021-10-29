#include<iostream>
#include<vector>
#include<map>

int maxm(int a, int b){ return a>b?a:b; }

using namespace std;
int main()
{
    int n;
    cin>>n;
    long long val;
    vector<long long> v;
    map<long long, int> mp;
    for(int i=0; i<n; i++)
    {
        cin>>val;
        v.push_back(val);
        mp[val] = 0;
    }
    int right = 0, left = 0;
    int max = 0;
    mp[v[right]]++;
    while(right<n)
    {
        while(mp[v[right]]>1)
        {
            mp[v[left++]]--;
        }
        max = maxm(max, right-left+1);
        mp[v[++right]]++;
    }
    cout<<max<<endl;
    return 0;
}