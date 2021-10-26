#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    long n , m , k;
    cin>> n >> m >> k;
    vector<long>req;
    vector<long>size;
    long val;
    for(long i=0; i<n; i++)
    {
        cin>>val;
        req.push_back(val);
    }
    for(long i=0; i<m; i++)
    {
        cin>>val;
        size.push_back(val);
    }
    int pt1 = 0;
    int pt2 = 0;
    long count = 0;
    sort(req.begin(), req.end());
    sort(size.begin(), size.end());
    while(true)
    {
        if((pt1 == n) || (pt2 == m))
            break;
        if(abs(req[pt1] - size[pt2]) <= k)
        {
            count++;
            pt1++;
            pt2++;
        }    
        else if((size[pt2] - req[pt1])>k)
            pt1++;
        else
            pt2++;    
    }
    cout<<count<<endl;
    return 0;
}