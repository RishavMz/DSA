#include<iostream>
#include<vector>
#include<map>
#include<set>

using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<long long>beg;
    vector<long long>end;
    set<long long>pts;
    long long a, b;
    for(int i=0; i<n; i++)
    {
        cin>>a>>b;
        beg.push_back(a);
        end.push_back(b);
        pts.insert(a);
        pts.insert(b);
    }
    map<int, int>mp;
    for(auto i: pts)
        mp[i]=0;
    for(auto i: beg)
        mp[i]++;
    for(auto i: end)
        mp[i]--;
    int max = 0;
    int maxun = 1;
    for(auto i: pts)
    {
        max = max + mp[i];
        maxun = max>maxun?max:maxun;
        max = max<0?0:max;
    }
    maxun = max>maxun?max:maxun;
    cout<<maxun<<endl;
    return 0;

}