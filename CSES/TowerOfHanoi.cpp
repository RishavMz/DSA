#include<iostream>
#include<vector>

using namespace std;

vector<pair<int,int>>v;

void towerOfHanoi(int n, int from, int to, int aux)
{
    if(n == 1)
    {
        v.push_back(pair<int,int>(from,to));
        return;
    }
    towerOfHanoi(n-1, from, aux, to);
    v.push_back(pair<int,int>(from,to));
    towerOfHanoi(n-1, aux, to, from);
}

int main()
{
    int n;
    cin>>n;
    towerOfHanoi(n, 1, 3, 2);
    cout<<v.size()<<endl;
    for(auto i: v)
        cout<<i.first<<" "<<i.second<<endl;
    return 0;
}