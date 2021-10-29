#include<iostream>
#include<set>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0);
    int n;
    cin>>n;
    long long val;
    multiset<long long>s;
    for(int i=0; i<n; i++)
    {
        cin>>val;
        auto it = s.upper_bound(val);
        if(it == s.end())
            s.insert(val);
        else
        {
            s.erase(it);
            s.insert(val);
        }
    }
    cout<<s.size()<<endl;
    return 0;
}