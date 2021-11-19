#include<iostream>

using namespace std;
int main()
{
    int a , b , c;
    int f = 0;
    for(a=1; a<1000; a++)
    {
        for(b=a; b<1000-a; b++)
        {
            c = 1000-(b+a);
            long c1 = c*c;
            long a1 = a*a;
            long b1 = b*b;
            if(a1+b1==c1 || a1+c1==b1 || b1+c1==a1)
            {
                f = 1;
                break;
            }
        }
        if(f)
            break;
    }
    cout<<(a*b*c)<<endl;
    return 0;
}