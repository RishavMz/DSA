#include<iostream>

using namespace std;
int main()
{
    int n5 =  999/5;
    int n3 =  999/3;
    int n15 = 999/15;
    int s3 =   (n3*(6 +(n3-1) *3) )/2;
    int s5 =   (n5*(10+(n5-1) *5) )/2;
    int s15 = (n15*(30+(n15-1)*15))/2;
    cout<<s3+s5-s15<<endl;
    return 0;
}