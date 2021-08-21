#include<vector>
#include<iostream>

using namespace std;

template <typename T>
void mergeSort(vector<T>& arr, int low = 0, int high = -10)
{
    if(high == -10)
        high = arr.size();
    if(low >= high)
        return;
    int mid = (low+high)/2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid+1, high);

    int s1 = mid-low+1;
    int s2 = high-mid;
    T arr1[s1];
    T arr2[s2];
    for(int i=0; i<s1; i++)
        arr1[i] = arr[low+i] ;
    for(int i=0; i<s2; i++)
        arr2[i] = arr[mid+i+1] ;
        
    int i = 0, j = 0, k = low;
    while(i<s1 && j<s2)
    {
        if(arr1[i]<=arr2[j])
            arr[k++] = arr1[i++];
        else
            arr[k++] = arr2[j++];
    }
    while(i<s1)
        arr[k++] = arr1[i++];
    while(j<s2)
        arr[k++] = arr2[j++];
}





template <typename T>
void bubbleSort(vector<T>& arr)
{
    for(int i=0; i<arr.size(); i++)
    {
        for(int j=0; j<arr.size()-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                T temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}





template <typename T>
void selectionSort(vector<T>& arr)
{
    for(int i=0; i<arr.size()-1; i++)
    {
        if(arr[i]>arr[i+1])
        {
            for(int j=i; j>=0; j--)
            {
                if(arr[j]>arr[j+1])
                {
                    T temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
        }
    }
}