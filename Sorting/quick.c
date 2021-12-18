#include<stdio.h>
#include<stdlib.h>
int count=0;

void swap(int *x, int*y)
{
    int temp;
    
    temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int arr[], int l, int h)
{
    int pivot, i, j;
    pivot = arr[h];
    i = l-1;

    for(j = l; j < h; j++)
    {
        if(arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
        count++;
    }
    swap(&arr[i + 1], &arr[h]); 

    return i + 1;
}

void Quicksort(int arr[], int l, int h)
{
    int pivot;

    if(l < h)
    {
        pivot = partition(arr, l, h);

        Quicksort(arr, l, pivot - 1);
        Quicksort(arr, pivot + 1, h);
    }
}

void print(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    printf("%d ",arr[i]);

    printf("\n%d",count);
}

int main()
{
    int* arr;
    int i, n;

    scanf("%d",&n);
    arr = (int*) malloc(n * sizeof(int));

    for(i = 0; i < n; i++)
    scanf("%d",&arr[i]);

    Quicksort(arr, 0, n-1);
    print(arr, n);

    return 0;
}