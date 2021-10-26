#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    long long val;
    long long sum = 0;
    for(int i=0; i<n-1; i++)
    {
        cin>>val;
        sum += val;
        cout<<sum<<endl;
    }
    long long ns = n*(n+1)/2;
    cout<<ns<<"  "<<sum<<endl;
    cout<<ns-sum<<endl;
    return 0;
}