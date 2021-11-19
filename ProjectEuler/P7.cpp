#include<iostream>
#include<vector>

using namespace std;
int main()
{
    vector<long long>numbers;
    vector<long long>skip;
    vector<long long>prime;
    for(long long i=2; i<=5000000; i++)
    {
        numbers.push_back(i);
        skip.push_back(1);
    }
    long long ptr = 0;
    while(ptr < numbers.size())
    {
        if(skip[ptr])
        {
            prime.push_back(numbers[ptr]);
            for(long long i = ptr; i<numbers.size(); i+=numbers[ptr])
                skip[i]=0;
        }
        ptr++;
    }
    cout<<prime[10000]<<endl;
    return 0;
}