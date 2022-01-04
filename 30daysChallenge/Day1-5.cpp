//  COMPANY : GOLDMAN SACHS

#include<bits/stdc++.h>
using namespace std;


//  1 ->    PRINT ANAGRAMS TOGETHER
//  https://practice.geeksforgeeks.org/problems/print-anagrams-together/1/ 
vector<vector<string>> Anagrams(vector<string>& string_list) 
{
    vector<string>s;
    unordered_set<string>st;
    for(string i: string_list)
        s.push_back(i);
    for(int i=0; i<s.size(); i++)
        sort(s[i].begin(), s[i].end());
    for(string i: s)
        st.insert(i);
    vector<vector<string>>v;
    for(auto j: st)
    {
        vector<string>temp;
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]==j)
                temp.push_back(string_list[i]);
        }
        v.push_back(temp);
    }
    return v;
}

//  2 ->    OVERLAPPING RECTANGLES
//  https://practice.geeksforgeeks.org/problems/overlapping-rectangles1924/1/
int doOverlap(int L1[], int R1[], int L2[], int R2[]) 
{
    if(L1[0]>R2[0] || L2[0]>R1[0] || L2[1]<R1[1] || L1[1]<R2[1])
        return false;
    return true;
}

//  3 ->    UNSOLVED

//  4 ->    RUN LENGTH ENCODING
//  https://practice.geeksforgeeks.org/problems/run-length-encoding/1/
string encode(string src)
{     
    if(src.length()==1)
        return (src+'1');
    string s;
    int count = 1;
    for(int i=1; i<src.length(); i++)
    {
        if(src[i]==src[i-1])
            count++;
        else
        {
            s+=(src[i-1])+to_string(count);
            count=1;
        }
        if(i == src.length()-1)
            s+=(src[i])+to_string(count);
    }
    return s;
}  

//  5 ->    Nth UGLY NUMBER                                             
//  https://practice.geeksforgeeks.org/problems/ugly-numbers2254/1/
unsigned long long getNthUglyNo(int n) 
{
	set<unsigned long long>s;
    int count = 1;
    s.insert(1);
    while(count<n)
    {
        auto val = s.begin();
        s.insert(*val*2);
        s.insert(*val*3);
        s.insert(*val*5);
        s.erase(val);
        count++;
    } 
    return *s.begin();
}

//  6 ->    UNSOLVED

//  7 ->    Distributing M items in a circle of size N starting from K-th position
//  https://www.geeksforgeeks.org/distributing-m-items-circle-size-n-starting-k-th-position/
int position(int n, int m, int k)
{
    return (k+m-1)%n;
}

//  8 ->    UNSOLVED

//  9 ->    UNSOLVED

//  10 ->   Find max 10 numbers in a list having 10M entries
vector<long long> max10(vector<long long> v)
{
    vector<long long>mex;
    priority_queue<long long>pq;
    for(auto i: v)
        pq.push(i);
    for(int i=0; i<10; i++)
    {
        mex.push_back(pq.top());
        pq.pop();
    }
    return mex;
}

//  11 ->   Find one repeated and one missing character from unsorted array
//  https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1/
int *findTwoElement(int *arr, int n) 
{
    unordered_map<int, int>mp;
    for(int i=1; i<=n; i++)
        mp[i]=0;
    for(int i=0; i<n; i++)
        mp[arr[i]]++;
    int v[2];
    int* ptr = v;
    for(auto i: mp)
        if(i.second==2)
            v[0]=i.first;
        else if(i.second==0)
            v[1]=i.first;
    return ptr;
}

//  12 ->    UNSOLVED

//  13 ->    UNSOLVED

//  14 ->   Minimum size subarray sum
//  https://leetcode.com/problems/minimum-size-subarray-sum/submissions/
int minSubArrayLen(int target, vector<int>& nums) 
{
    int p1=0;
    int p2=0;
    int sum=nums[0];
    int pos=0;
    int max=nums.size();
    while(p2!=nums.size())
    {
        if(sum>=target)
        {
            int sz = (p2-p1+1);
            max = (sz<max)?sz:max;
            pos++;
        }
        if(sum>=target)
            sum-=nums[p1++];
        else 
        {
            if(p2 == nums.size()-1)
                break;
            sum+=nums[++p2];
        }
    }
    if(sum>target)
    {
        int sz = (p2-p1+1);
        max = (sz<max)?sz:max;
        pos++;
    }
    return pos==0?0:max;
}