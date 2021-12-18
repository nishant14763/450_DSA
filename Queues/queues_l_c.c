#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct queue
{
    struct node *head;
    struct node *tail;
};

struct node* create_node(int k)
{
    struct node *new;
    new = (struct node*) malloc( sizeof(struct node) );
    new->data = k;
    new->next = NULL;
    return new;
}

int queue_empty(struct queue Q)
{
    if(Q.head == NULL)
    return -1;
    return 1;
}

void enqueue(struct queue *Q, struct node *x)
{
    if(Q->head == NULL)
    Q->head = x;
    else
    Q->tail->next = x;
    Q->tail = x;    
}

int dequeue(struct queue *Q)
{
    int x;
    struct node *p;
    p = Q->head;
    if(Q->head == Q->tail)
    Q->tail = NULL;
    Q->head = Q->head->next;
    x = p->data;
    free (p);
    return x;
}

int main()
{
    char x;
    int y;

    struct queue Q;
    Q.head = NULL;
    Q.tail = NULL;

    while(1)
    {
        scanf("%c", &x);
        if(x == 'i')
        {
            scanf("%d",&y);
            enqueue(&Q, create_node(y));
        }
        if(x == 'd')
        {
            if(queue_empty(Q) == 1)
            printf("%d\n",dequeue(&Q));
            else
            printf("-1\n");
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