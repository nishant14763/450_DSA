#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct stack
{
    struct node *top;
};

struct node* create_node(int k)
{
    struct node *new;
    new = (struct node*) malloc( sizeof(struct node) );
    new->data = k;
    new->next = NULL;
    return new;
}

int stack_empty(struct stack S)
{
    if(S.top == NULL)
    return -1;
    return 1;
}

void push(struct stack *S, struct node *x)
{
    x->next = S->top;
    S->top = x;    
}

int pop(struct stack *S)
{
    int x;
    struct node *p;
    p = S->top;
    S->top = S->top->next;
    x = p->data;
    free (p);
    return x;
}

int main()
{
    char x;
    int y;

    struct stack S;
    S.top = NULL;

    while(1)
    {
        scanf("%c", &x);
        if(x == 'i')
        {
            scanf("%d",&y);
            push(&S, create_node(y));
        }
        if(x == 'd')
        {
            if(stack_empty(S) == 1)
            printf("%d\n",pop(&S));
            else
            printf("-1\n");
        }
        if(x == 'e')
        {
            printf("%d\n",stack_empty(S));
        }
        if(x == 't')
        break;
    }
    return 0;
}