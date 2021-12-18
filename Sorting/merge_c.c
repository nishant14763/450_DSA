#include<stdio.h>
int count=0;
void print(int arr[], int n);
void mergesort(int arr[], int l, int h);
void merge(int arr[], int l, int mid, int h);
int main()
{
    int arr[100001],n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    scanf("%d",&arr[i]);

    mergesort(arr,0,n-1);
    print(arr,n);

    printf("\n%d",count);

    return 0;
}

void mergesort(int arr[], int l, int h)
{
    int mid;
    if(l<h)
    {
        mid = l+(h-l)/2;
        mergesort( arr , l, mid);
        mergesort( arr, mid+1, h);
        merge( arr, l, mid, h);
    }
}

void merge(int arr[], int p, int q, int r)
{
    int i,j,k,n1,n2;
    n1=q-p+1;
    n2=r-q;

    int L[n1],R[n2];

    for(i=0;i<n1;i++)
    L[i]=arr[p+i];
    for(j=0;j<n2;j++)
    R[j]=arr[q+j+1];

    i=j=0; k=p;
    while(i<n1 && j<n2)
    {
        count++;
        if(L[i]<=R[j])
        {
            arr[k]=L[i];
            i++;
        }
        else
        {
            arr[k]=R[j];
            j++;
        }
        k++;
    }

     while(i<n1)
    {
        count++;
        arr[k]=L[i];
        i++; k++;
    }

     while (j<n2)
    {
        count++;
        arr[k]=R[j];
        j++; k++;
    }
}

void print(int arr[], int n)
{
    int i;
    for(i=0;i<n;i++)
    printf("%d ",arr[i]);
}
