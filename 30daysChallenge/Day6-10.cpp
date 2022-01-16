//  COMPANY : AMAZON

#include<bits/stdc++.h>
using namespace std;



//  1.Calculating Maximum Profit (Multiple Ladders Question)
//  https://practice.geeksforgeeks.org/problems/maximum-profit4657/1

//  2.Longest Mountain 
//  https://leetcode.com/problems/longest-mountain-in-array/
int longestMountain(vector<int>& arr) 
{
    vector<int>left;
    vector<int>right;
    left.push_back(0);
    for(int i=1; i<arr.size(); i++)
    {
        if(arr[i]>arr[i-1]) left.push_back(left[left.size()-1]+1);
        else                left.push_back(0);
    }
    right.push_back(0);
    for(int i=arr.size()-2; i>=0; i--)
    {
        if(arr[i]>arr[i+1]) right.push_back(right[right.size()-1]+1);
        else                right.push_back(0);
    }
    reverse(right.begin(), right.end());
    int max = 0;
    for(int i=0; i<left.size(); i++)
    {
        int val = left[i]+right[i]+1;
        if(val>max && left[i]>0 && right[i]>0) max=val;
    }
    return max;
}

//  3.IPL 2021 - Match Day 2 (similar to maximum in subarray)
//  https://practice.geeksforgeeks.org/problems/deee0e8cf9910e7219f663c18d6d640ea0b87f87/1/

//  4.Brackets in Matrix Chain Multiplication 
//  https://practice.geeksforgeeks.org/problems/brackets-in-matrix-chain-multiplication1024/1/

//  5.Phone directory (Question similar to this based on Amazon Pay as a service)
//  https://practice.geeksforgeeks.org/problems/phone-directory4628/1/

//  6.Maximum of all subarrays of size k
//  https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1

//  7.First non-repeating character in a stream
//  https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1

//  8.Count ways to N'th Stair(Order does not matter)
//  https://practice.geeksforgeeks.org/problems/count-ways-to-nth-stairorder-does-not-matter1322/1/

//  9.Which among them forms a perfect Sudoku Pattern ?
//  https://practice.geeksforgeeks.org/problems/is-sudoku-valid4820/1/
int isValid(vector<vector<int>> mat)
{
    for(int i=0; i<9; i++)
    {
        unordered_set<int>s1;
        for(int j=0; j<9; j++)
        {
            if(mat[i][j]==0)                        continue;
            else if (s1.find(mat[i][j])==s1.end())  s1.insert(mat[i][j]);
            else                                    return 0;
        }
        unordered_set<int>s2;
        for(int j=0; j<9; j++)
        {
            if(mat[j][i]==0)                        continue;
            else if(s2.find(mat[j][i])==s2.end())   s2.insert(mat[j][i]);
            else                                    return 0;
        }
    }
    for(int i=0; i<9; i+=3)
    {
        for(int j=0; j<9; j+=3)
        {
            unordered_set<int>s;
            for(int k=0; k<3; k++)
            {
                for(int l=0; l<3; l++)
                {
                    if(mat[i+k][j+l] == 0)                  continue;
                    else if(s.find(mat[i+k][j+l])==s.end()) s.insert(mat[i+k][j+l]);
                    else                                    return 0;
                }
            }
        }
    }
    return 1;
}

//  10.Nuts and Bolts Problem
//  https://practice.geeksforgeeks.org/problems/nuts-and-bolts-problem0431/1
void matchPairs(char nuts[], char bolts[], int n) 
{
    map<int,int>mp;
    mp['!']=0; mp['#']=0; mp['$']=0;mp['%']=0; mp['&']=0;
    mp['*']=0; mp['@']=0; mp['^']=0; mp['~']=0; 
    for(int i=0; i<n; i++)  mp[nuts[i]]++;
    int ptr=0;
    for(auto i: mp)
    {
        if(i.second==1)
        {
            nuts[ptr]   =i.first;
            bolts[ptr++]=i.first;
        }
    }
}

//  11.Tree Serialization and Deserialization
//  https://practice.geeksforgeeks.org/problems/serialize-and-deserialize-a-binary-tree/1

//  12.Column name from a given column number
//  https://practice.geeksforgeeks.org/problems/column-name-from-a-given-column-number4244/1/

//  13.Rotten Oranges -Multiple Repetitions
//  https://leetcode.com/problems/rotting-oranges/
int orangesRotting(vector<vector<int>>& grid) 
{
    queue<pair<int,int>>q;
    for(int i=0; i<grid.size(); i++)
    {
        for(int j=0; j<grid[0].size(); j++)
        {
            if(grid[i][j]==2)   q.push(pair<int,int>(i,j));
        }
    }
    int count = 0;
    while(q.size()>0)
    {
        int pos=0;
        queue<pair<int,int>>temp;
        while(q.size()>0)
        {
            int xpos = q.front().first;
            int ypos = q.front().second;
            if(xpos>0 && grid[xpos-1][ypos]==1)
            { 
                temp.push(pair<int,int>(xpos-1,ypos));
                grid[xpos-1][ypos]=2;
                pos++;
            }
            if(ypos>0 && grid[xpos][ypos-1]==1)
            { 
                temp.push(pair<int,int>(xpos,ypos-1));
                grid[xpos][ypos-1]=2;
                pos++;
            }
            if(xpos<grid.size()-1 && grid[xpos+1][ypos]==1)
            {
                temp.push(pair<int,int>(xpos+1,ypos));
                grid[xpos+1][ypos]=2;
                pos++;
            }
            if(ypos<grid[0].size()-1 && grid[xpos][ypos+1]==1)
            {
                temp.push(pair<int,int>(xpos,ypos+1));
                grid[xpos][ypos+1]=2;
                pos++;
            }
            q.pop();
        }
        if(pos==0)  break;
        count++;
        q=temp;
    }
    for(auto i: grid)
        for(auto j: i)
            if(j==1)    return -1;
    return count;
}

//  14.Tree Burning 
//  https://practice.geeksforgeeks.org/problems/burning-tree/1/

//  15. Delete N nodes after M nodes of a linked list 
//  https://practice.geeksforgeeks.org/problems/delete-n-nodes-after-m-nodes-of-a-linked-list/1/

