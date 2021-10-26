#include<iostream>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int count = 1;
    int maxcount = 1;
    char current = s[0];
    for(int i=1; i<s.length(); i++)
    {
        if(s[i]==current)
            count++;
        else
        {
            maxcount = (count>maxcount)?count:maxcount;
            count = 1;
            current = s[i];
        }
    }
    maxcount = (count>maxcount)?count:maxcount;
    cout<<maxcount<<endl;
    return 0;
}