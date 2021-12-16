#include<bits/stdc++.h>
using namespace std;

void bubble_sort(int arr[], int n)
{    
    for(int i=1; i<n; i++)
    {
        bool flag = false;
        for(int j=0; j<n-i; j++)
        {
            if(arr[j] > arr[j+1]);
            swap(arr[j],arr[j+1]);
        }
    }
}

int main()
{
    int arr[]= {5, 4, 3, 2, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubble_sort(arr, n);
    for(auto x:arr)
    cout << x << " ";

    return 0;
}