#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    long long data = 1;
    for(int i=0; i<n; i++)
        data = (data*2)%1000000007;
    cout<<data<<endl;
    return 0;
}