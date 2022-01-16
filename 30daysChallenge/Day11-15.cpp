//  COMPANY : MICROSOFT

#include<bits/stdc++.h>
using namespace std;



//  1.Divide an array into two sets S1 and S2 such that the absolute difference between their sums is minimum and find the minimum difference
//  https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1/
    
//  2.Prerequisite Tasks (Similar to Question of Modern Park)
//  https://practice.geeksforgeeks.org/problems/prerequisite-tasks/1/
    
    
//  3.Rotate by 90 degree
//  https://practice.geeksforgeeks.org/problems/rotate-by-90-degree0356/1/
void rotate(vector<vector<int> >& matrix)
{
    for(int i=0; i<matrix.size(); i++)
        for(int j=i+1; j<matrix[0].size(); j++)
            swap(matrix[i][j],matrix[j][i]);
    for(int i=0; i<matrix.size()/2; i++)
        for(int j=0; j<matrix[0].size(); j++)
            swap(matrix[i][j],matrix[matrix.size()-1-i][j]);
}
    
//  4. Given a matrix of size r*c. Traverse the matrix in spiral form. 
//  https://practice.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1/
    
//  5. Stock span problem
//  https://practice.geeksforgeeks.org/problems/stock-span-problem-1587115621/1
    
//  6.Possible Words From Phone Digits
//  https://practice.geeksforgeeks.org/problems/possible-words-from-phone-digits-1587115620/1/
    
//  7.Unit Area of largest region of 1's 
//  https://practice.geeksforgeeks.org/problems/length-of-largest-region-of-1s-1587115620/1/
    
//  8.Connect Nodes at Same Level
//  https://practice.geeksforgeeks.org/problems/connect-nodes-at-same-level/1/
    
//  9.Count Number of SubTrees having given Sum 
//  https://practice.geeksforgeeks.org/problems/count-number-of-subtrees-having-given-sum/1/
    
//  10.Stickler Thief (Similar to Alibaba and Thiefes Question) 
//  https://practice.geeksforgeeks.org/problems/stickler-theif-1587115621/1/
int FindMaxSum(int arr[], int n)
{
    vector<int>v;
    if(n==1)    return arr[0];
    else        v.push_back(arr[0]);
    if(n==2)    return arr[0]>arr[1]?arr[0]:arr[1];
    else        v.push_back(arr[1]);
    if(n==3)    return max(arr[0]+arr[2],arr[1]);
    else        v.push_back(arr[2]+arr[0]);
    for(int i=3; i<n; i++)
    {
        v.push_back(arr[i]+max(v[i-2],v[i-3]));
    }
    return max(v[n-1],v[n-2]);
}
    
//  11.Generate and print all binary numbers with decimal values from 1 to N.  
//  https://practice.geeksforgeeks.org/problems/generate-binary-numbers-1587115620/1/
    
//  12.Find all the unique quadruple from the given array that sums up to the given number.
//  https://practice.geeksforgeeks.org/problems/find-all-four-sum-numbers1732/1
    
//  13.Given a Graph of V vertices and E edges and another edge(c - d), the task is to find if the given edge is a Bridge. i.e., removing the edge disconnects the graph.
//  https://practice.geeksforgeeks.org/problems/bridge-edge-in-graph/1
    
//  14.Given a destination D , find the minimum number of steps required to reach that destination.
//  https://practice.geeksforgeeks.org/problems/minimum-number-of-steps-to-reach-a-given-number5234/1/
    
//  15.Find the order of characters in the alien language.
//  https://practice.geeksforgeeks.org/problems/alien-dictionary/1/