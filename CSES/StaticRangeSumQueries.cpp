#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n, q;
    cin>>n>>q;
    vector<long long>v;
    long long val;
    v.push_back(0);
    for(int i=0; i<n; i++)
    {
        cin>>val;
        v.push_back(val);
    }
    for(int i=1; i<=n; i++)
        v[i] += v[i-1];
    for(int qq=0; qq<q; qq++)
    {
        int a, b;
        cin>>a>>b;
        cout<<(v[b]-v[a-1])<<endl;
    }
    return 0;
}