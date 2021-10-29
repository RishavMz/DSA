#include<iostream>
#include<map>

using namespace std;
int main()
{
    int n;
    cin>>n;
    int val;
    map<int, int> mp;
    for(int i=0; i<n; i++)
    {
        cin>>val;
        mp[val]=i;
    }
    int count = 1;
    for(int i=1; i<n; i++)
    {
        if(mp[i+1]<mp[i])
            count++;
    }
    cout<<count<<endl;
    return 0;
}