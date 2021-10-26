#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int max = pow(2,n);
    for(int i=0; i<max; i++)
    {
        int data = i;
        string d;
        int temp = data&1;
        data>>=1;
        while(data>0)
        {
            int val = temp^(data&1);
            temp = data&1;
            d.push_back(char(val+48));
            data>>=1;

        }
        d.push_back(char(temp+48));
        while(d.length()<n)
            d.push_back('0');
        for(int i=0; i<d.length(); i++)
            cout<<d[n-1-i];
        cout<<endl;
    }
    return 0;
}