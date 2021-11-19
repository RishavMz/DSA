#include<iostream>

using namespace std;
int hcf(int a, int b)
{
    if(b==0)
        return a;   
    return hcf(b, a%b);
}
int main()
{
    long long lcm = 1;
    for(int j=2; j<=20; j++)
        lcm = (lcm*j)/hcf(lcm,j);
    cout<<lcm<<endl;
    return 0;
}