#include<iostream>
#include<vector>
#include<cmath>

long long minm(long long a, long long b) { return a<b?a:b; }

using namespace std;
int main()
{
    int n;
    cin>>n;
    int val;
    vector<int>v;
    long long sum = 0;
    long long minun = 99999999999999999;
    for(int i=0; i<n; i++)
    {
        cin>>val;
        v.push_back(val);
        sum += val;
    }
    for(int i=0; i<pow(2, n); i++)
    {
        long long sumn = 0;
        int data = i;
        for(int j=0; j<n; j++)
        {
            sumn += (data&1)*v[j];
            data >>= 1;
        }
        minun = minm(minun, abs(2*sumn-sum));
    }
    cout<<minun<<endl;
    return 0;
}