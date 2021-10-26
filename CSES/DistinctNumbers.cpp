#include<iostream>
#include<set>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int val;
    set<int>s;
    for(int i=0; i<n; i++)
    {
        cin>>val;
        s.insert(val);
    }
    cout<<s.size()<<endl;
    return 0;
}