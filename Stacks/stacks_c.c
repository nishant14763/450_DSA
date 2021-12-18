#include<stdio.h>
#include<stdlib.h>
struct stack
{
    int size;           
    int top;
    int *arr;
};

int stack_empty(struct stack S)
{
    if(S.top == -1)
    return -1;
    return 1;
}

int stack_full(struct stack S)
{
    if(S.top == S.size-1)
    return -1;
    return 1;
}

void push(struct stack *S, int x)
{
    S->top++;
    S->arr[S->top] = x;
}
int pop(struct stack *S)
{
    int x = S->arr[S->top];
    S->top--;
    return x;
}

int main()
{
    char x;
    int y;

    struct stack S;
    scanf("%d",&S.size);
    S.arr = (int*) malloc (S.size * sizeof(int));
    S.top = -1;

    while(1)
    {
        scanf("%c", &x);
        if(x == 'i')
        {
            scanf("%d",&y);
            if(stack_full(S) == 1)
            push(&S, y);
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