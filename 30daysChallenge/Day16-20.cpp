//  COMPANY : ADOBE

#include<bits/stdc++.h>
using namespace std;

//  1.Find a continuous sub-array which adds to a given number S.
//  https://practice.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1
vector<int> subarraySum(int arr[], int n, long long s)
{
    int ptr1=0, ptr2=0;
    vector<int>v;
    long long sum=arr[ptr1];
    while(ptr2 != n)
    {
        if(sum==s)
        {
            v.push_back(ptr1+1);
            v.push_back(ptr2+1);
            return v;
        }
        else if(sum>s)
            sum -= arr[ptr1++];
        else if(sum<s)
            sum += arr[++ptr2];
    }
    v.push_back(-1);
    return v;
}

//  2.Find the length of the Longest Arithmetic Progression (LLAP) in it.
//  https://practice.geeksforgeeks.org/problems/longest-arithmetic-progression1019/1/

//  3.Number of distinct Words with k maximum contiguous vowels(Joe and his Dictionary Problem)
//  https://practice.geeksforgeeks.org/problems/7b9d245852bd8caf8a27d6d3961429f0a2b245f1/1/

//  4.Partition Equal Subset Sum
//  https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1

//  5.Total number of ways n can be expressed as sum of xth power of unique natural numbers
//  https://practice.geeksforgeeks.org/problems/express-as-sum-of-power-of-natural-numbers5647/1

//  6.Generate all combinations of well-formed(balanced) parentheses.
//  https://practice.geeksforgeeks.org/problems/generate-all-possible-parentheses/1/

//  7.Pots of Gold Game (Similar to Covid and Beds problem)
//  https://practice.geeksforgeeks.org/problems/pots-of-gold-game/1/

//  8.ATOI 
//  https://practice.geeksforgeeks.org/problems/implement-atoi/1/

//  9. Smallest palindromic number greater than N using the same set of digits as in N.
//  https://practice.geeksforgeeks.org/problems/next-higher-palindromic-number-using-the-same-set-of-digits5859/1/

//  10.Elections
//  https://practice.geeksforgeeks.org/problems/winner-of-an-election-where-votes-are-represented-as-candidate-names-1587115621/1/
vector<string> winner(string arr[],int n)
{
    map<string,int>mp;
    for(int i=0; i<n; i++)
    {
        if(mp.find(arr[i])==mp.end())
            mp[arr[i]]=1;
        else
            mp[arr[i]]++;
    }
    string max=mp.begin()->first;
    for(auto i: mp)
    {
        if(i.second>mp[max])
            max=i.first;
    }
    vector<string>v;
    v.push_back(max);
    v.push_back(to_string(mp[max]));
    return v;
}

//  11.String Amendment
//  https://practice.geeksforgeeks.org/problems/amend-the-sentence3235/1

//  12.Leaders in Array
//  https://practice.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1/
vector<int> leaders(int a[], int n)
{
    vector<int>v;
    v.push_back(a[n-1]);
    int now = a[n-1];
    for(int i=n-2; i>=0; i--)
    {
        if(a[i]>=now) 
        {
            v.push_back(a[i]);
            now = a[i];
        }
    }
    reverse(v.begin(), v.end());
    return v;
}

//  13.Minimum operations to convert array A to B 
//  https://practice.geeksforgeeks.org/problems/minimum-insertions-to-make-two-arrays-equal/1/

//  14.Smallest range in K lists 
//  https://practice.geeksforgeeks.org/problems/find-smallest-range-containing-elements-from-k-lists/1/

//  15.Given two library versions of an executable: for example, “10.1.1.3” and “10.1.1.9” or “10” and “10.1”. Find out which one is more recent? Strings can be empty also.
//  