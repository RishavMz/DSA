#include<iostream>

using namespace std;
int main()
{
    long long a = 1;
    long long b = 1;
    long long c;
    long long s = 0;
    for(int i=0; i<=1000000000; i++)
    {
        c = a+b;
        if(c>=4000000)
            break;
        if(i%3==0)
        {
            s += c;
        }
        a = b;
        b = c;
    }
    cout<<s<<endl;
    return 0;
}