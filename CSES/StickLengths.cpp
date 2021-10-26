#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    cin>>n;
    long long val;
    vector<long long>v;
    for(int i=0; i<n; i++)
    {
        cin>>val;
        v.push_back(val);
    }
    sort(v.begin(), v.end());
    long long v1 = v[floor(n/2)];
    long long v2 = v[ceil(n/2)];
    long s1 = 0, s2 = 0;
    for(int i=0; i<n; i++)
    {
        s1 += abs(v[i]-v1);
        s2 += abs(v[i]-v2);
    }
    cout<<(s1<s2?s1:s2)<<endl;
    return 0;
}