#include<iostream>

using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long a, b;
        cin>>a>>b;
        if(a<b)
        {
            long long temp = a;
            a = b;
            b = temp;
        }
        if((a+b)%3 == 0 && a <= 2*b)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}