#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    long long n, x;
    cin>>n>>x;
    long long val;
    vector<long long>v;
    for(int i=0; i<n; i++)
    {
        cin>>val;
        v.push_back(val);
    }
    sort(v.begin(), v.end());
    int count = 0;
    int i=0;
    int j = n-1;
    while(i<j)
    {
        if(v[i]+v[j]<=x)
        {
            i++;
            j--;
        }
        else 
            j--;
            count++;
    }
    if(i==j)
        count++;
    cout<<count<<endl;
    return 0;
}