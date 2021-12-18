#include<stdio.h>
#include<stdlib.h>

int count = 0;

struct queue
{
    int size;
    int head;           
    int tail;
    int *arr;
};

int queue_empty(struct queue Q)
{
    if(count == 0)
    return -1;
    return 1;
}

int queue_full(struct queue Q)
{
    if(count == Q.size)
    return -1;
    return 1;
}

void enqueue(struct queue *Q, int x)
{
    count++;
    Q->arr[Q->tail] = x;
    Q->tail = ((Q->tail) + 1)%(Q->size);
}
int dequeue(struct queue *Q)
{
    count--;
    int x = Q->arr[Q->head];
    Q->head =((Q->head) + 1)%(Q->size);
    return x;
}

int main()
{
    char x;
    int y;

    struct queue Q;
    scanf("%d",&Q.size);
    Q.arr = (int*) malloc (Q.size * sizeof(int));
    Q.head = 0;
    Q.tail = 0;

    while(1)
    {
        scanf("%c", &x);

        if(x == 'i')
        {
            scanf("%d",&y);
            if(queue_full(Q) == 1)
            enqueue(&Q, y);
            else
            printf("-1\n");
        }
        if(x == 'd')
        {
            if(queue_empty(Q) == 1)
            printf("%d\n",dequeue(&Q));
            else
            printf("-1\n");
        }
        if(x == 'f')
        {
            printf("%d\n",queue_full(Q));
        }
        if(x == 'e')
        {
            printf("%d\n",queue_empty(Q));
        }
        if(x == 't')
        break;
    }
    return 0;
}