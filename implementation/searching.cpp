#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

template <typename T>
int linearSearch(vector<T>& arr, T value)
{
    for(int i=0; i<arr.size(); i++)
    {
        if(arr[i] == value)
            return i;
    }
    return -1;
}

template <typename T>
int binarySearch(vector<T>& arr, T value)
{
    int low = 0, high = arr.size();
    int mid;
    while(low < high)
    {
        mid = (low+high)/2;
        if(arr[mid] == value)
            return mid;
        else if(arr[mid] < value)
            low = mid+1;
        else
            high = mid;
    }
    return -1;
}
