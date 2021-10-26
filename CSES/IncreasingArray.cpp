#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>v;
    int val;
    for(int i=0; i<n; i++)
    {
        cin>>val;
        v.push_back(val);
    }
    long long count = 0;
    for(int i=1; i<n; i++)
    {
        if(v[i]<v[i-1])
        {
            count += v[i-1]-v[i];
            v[i] = v[i-1];
        }
        
    }
    cout<<count<<endl;
    return 0;
}