#include<stdio.h>
#include<stdlib.h>
int count=0;

struct heap
    {
        int* arr;
        int length;
        int heapsize;
    };

void swap ( int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}


void max_heapify ( struct heap h1, int i)
{
    int largest, l, r;
    l = 2 * i + 1;
    r = 2 * i + 2;
    if(l < h1.heapsize)
        count++;
    if(r < h1.heapsize)
        count++;
    if( (l < h1.heapsize) && (h1.arr[l] > h1.arr[i]) )
    {
        largest = l;
    }
    else
    {
        largest = i;
    }

    if( r < h1.heapsize && h1.arr[r] > h1.arr[largest] )
    {
        largest = r;
    }

    if(largest != i)
    {
        swap(&h1.arr[i], &h1.arr[largest]);
        max_heapify(h1, largest);
    }
}

void build_max_heap ( struct heap h1)
{
    int i;
    for ( i = (h1.length/2 - 1); i >= 0; i--)
        max_heapify(h1, i);
}

void Heapsort( struct heap h1)
{
    int i;
    build_max_heap(h1);

    for( i = ( h1.length - 1 ); i > 0 ; i--)
    {
        swap(&h1.arr[0], &h1.arr[i]);
        h1.heapsize -= 1;
        max_heapify( h1, 0);
    }
}

int main()
{
    int n, i;
    struct heap h1;

    scanf("%d",&n);
    h1.arr = (int*)malloc( n * sizeof(int));
    h1.length = n;
    h1.heapsize = h1.length;
    for( i = 0; i < n; i++ )
    scanf( "%d", &h1.arr[i] );

    Heapsort(h1);

    for (i = 0; i < n; i++)
    printf("%d ",h1.arr[i]);

    printf("\n%d",count);

    return 0;
}
