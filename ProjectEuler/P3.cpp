#include<iostream>
#include<vector>
#include<cmath>

using namespace std;
int main()
{
    vector<long long>numbers;
    vector<long long>pr;
    vector<long long>prime;
    long long data = 600851475143;
    long long sq = sqrt(data);
    for(int i=2; i<=sq; i++)
    {
        numbers.push_back(i);
        pr.push_back(1);
    }
    int slider = 0;
    while(slider < numbers.size())
    {
        if(pr[slider]==0)
        {
            slider++;
            continue;
        }
        prime.push_back(numbers[slider]);
        for(int i = slider; i < numbers.size(); i+= numbers[slider])
            pr[i] = 0;
    }
    int i = 0;
    for(i = prime.size()-1; i>=0; i--)
        if(data%prime[i]==0)
            break;
    cout<<prime[i]<<endl;
    return 0;
}