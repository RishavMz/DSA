#include<iostream>
#include<vector>
using namespace std;
#define max(a, b) a>b?a:b

int main()
{
    long long n;
    cin>>n;
    vector<long long> v;
    long long val;
    for(int i=0; i<n; i++)
    {
        cin>>val;
        v.push_back(val);
    }
    long long maxi = v[0];
    long long maxun = v[0];
    maxi = max(maxi, 0);
    for(int i=1; i<n; i++)
    {
        maxi += v[i];
        maxun = max(maxun, maxi);
        maxi = max(maxi, 0);
    }
    cout<<maxun<<endl;
    return 0;
}