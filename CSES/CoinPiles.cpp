#include<iostream>
#include<vector>
using namespace std;

vector<long long> reduce(vector<long long> arr)
{
    if(abs(arr[0]-arr[1])<=1)
        return arr;
    else
    {
        if(arr[0]>arr[1])
        {
            long long data = arr[0]-arr[1];
            if(data%2 == 1)
                data--;
            arr[0] -= data;
            arr[1] -= (data/2);
        }
        else
        {
            long long data = arr[1]-arr[0];
            if(data%2 == 1)
                data--;
            arr[1] -= data;
            arr[0] -= (data/2);
        }
        return reduce(arr);
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        vector<long long> v;
        long long data;
        for(int i=0; i<2; i++)
        {
            cin>>data;
            v.push_back(data);
        }
        reduce(v);
        if(v[0]==v[1])
        {
            if(v[0]%3==0)
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }
        else
        {
            int data;
            if(v[0]>v[1])
                data = v[1]-1;
            else
                data = v[0]-1;
            if(data%3 == 0)
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }
    }
    return 0;
}