#include<iostream>
#include<vector>

using namespace std;
int main()
{
    vector<long long>number;
    vector<int>skip;
    long long sum = 0;;
    for(long long i=2; i<2000000; i++)
    {
        number.push_back(i);
        skip.push_back(0);
    }
    for(long long i=0; i<number.size(); i++)
    {
        if(skip[i])
            continue;
        sum += number[i];
        for(long long j = i; j < number.size(); j += number[i])
            skip[j]=1;
    }
    cout<<sum<<endl;
    return 0;
}