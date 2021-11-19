#include<iostream>

using namespace std;
int palin(long long data)
{
    long long temp = data;
    long long rev = 0;
    while(temp>0)
    {
        rev = rev*10 + temp%10;
        temp /= 10;
    }
    if(rev==data)
        return 1;
    return 0;
}

int main()
{
    long long f = 0;
    for(long long i=999; i>=900; i--)
    {
        for(long long j=999; j>=900; j--)
        {
            long long data = i*j;
            if(palin(data))
            {
                f = (data>f)?data:f;
            }
        }
    }
    cout<<f<<endl;
    return 0;
}