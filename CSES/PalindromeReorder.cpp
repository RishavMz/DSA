#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    string s;
    cin>>s;
    vector<char>v;
    for(int i=0; i<s.length(); i++)
        v.push_back(s[i]);
    sort(v.begin(), v.end());
    string e;
    string mid;
    int i;
    for(i=0; i<v.size()-1; i++)
    {
        if(v[i]==v[i+1])
            e.push_back(v[i++]);
        else
            mid.push_back(v[i]);
    }
    if(i == v.size()-1)
        mid.push_back(v[i]);
    if(mid.length()<2)
    {
        for(int i=0; i<e.length(); i++)
            cout<<e[i];
        cout<<mid;
        for(int i=0; i<e.length(); i++)
            cout<<e[e.length()-1-i];
    }
    else
        cout<<"NO SOLUTION";
    cout<<endl;
    return 0;
}