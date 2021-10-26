#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    if(n == 1)
        cout<<"1"<<endl;
    else if(n == 4)
        cout<<"2 4 1 3"<<endl;
    else if(n<4)
        cout<<"NO SOLUTION"<<endl;
    else
    {   
        int val1, val2;
        if(n%2==0)
        {
            val1 = n-1;
            val2 = n;
        }
        else
        {
            val1 = n;
            val2 = n-1;
        }
        for(int i=val2; i>0; i-=2)
            cout<<i<<" ";
        for(int i=val1; i>0; i-=2)
            cout<<i<<" ";
        cout<<endl;
    } 
    return 0;
}