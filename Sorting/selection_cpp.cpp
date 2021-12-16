#include<bits/stdc++.h>
using namespace std;
void bubble_sort(int &arr)
{
    for(int i=1; i<n-1; i++) // Total 1 to n-1 passes
    {
        for(int j=0; j<n-i; j++)
        {
            if(arr[j] > arr[j+1])
            swap(arr[j], arr[j+1]);
        }
    }
}

int main()
{
    int arr[]={5,4,3,2,1};
    bubble_sort(*arr);
    return 0;
}