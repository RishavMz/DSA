#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int n = 100;
    long long s1 = (n*(n+1)*(2*n+1))/6;
    long long s2 = (pow(n,4) + pow(n,3)*2 + pow(n,2))/4;
    cout<<(s2-s1)<<endl;
    return 0;
}