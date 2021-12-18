#include<stdio.h>
#include<stdlib.h>
int count=0;
void insort(int arr[], int n);
void print(int arr[], int n);

int main()
{
    int* arr;
    int n,i;
    arr = (int*)malloc(n * sizeof(int));

    scanf("%d",&n);
    for(i=0;i<n;i++)
    scanf("%d",&arr[i]);

    insort(arr,n);
    print(arr, n);
    printf("%d",count);

    return 0;
}
void insort(int arr[], int n)
{
    int i,j,key;
    for(j=1;j<n;j++)
    {
        key=arr[j];
        i=j-1;
        while(i>-1 && arr[i]>key)
        {
            count++;
            arr[i+1]=arr[i];
            i--;
        }
        arr[i+1]=key;
        if(arr[i]<=arr[i+1] && i>-1)
        count++;
    }
}

void print(int arr[], int n)
{
    int i;
    for(i=0;i<n;i++)
    printf("%d ",arr[i]);
    printf("\n");
}
