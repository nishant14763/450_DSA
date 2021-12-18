#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node *next;
};

struct List
{
    struct node *head;
};

struct node* create_node( int k )                                       // creating a new node
{
    struct node *new;
    new = (struct node *)malloc( sizeof(struct node) );
    new->data = k;
    new->next = NULL;
    return new;
}

void list_insert_front( struct List *L, struct node *x )                // inserting node at front
{
    x->next = L->head;
    L->head = x;
}

void list_insert_after( struct List *L, struct node *x, struct node *y )                  // inserting node after node y
{
    x->next = y->next;
    y->next = x;
}

void list_insert_before( struct List *L, struct node *x, struct node *y )                 // inserting node before node y
{
    struct node *p;
    p = L->head;
    while( p->next != y )
    {
        p = p->next;
    }
    x->next = p->next;
    p->next = x;
}

void list_insert_tail( struct List *L, struct node *x )                          // inserting node at end
{
    struct node *p;
    p = L->head;
    while( p->next != NULL)
    {
        p = p->next;
    }
    p->next = x;
}

void list_delete( struct List *L, struct node *x )                               // delete a particular node
{
    int value;
    struct node *p = L->head;

    while( p->next != x )
    {
        p = p->next;
    }    
    p->next = x->next;
    value = x->data;
    printf("%d\n", value );
    free (x);
}

void list_delete_first( struct List *L )                                // delete first node
{
    int value;
    struct node *p = L->head;
    L->head = L->head->next;
    value = p->data;
    printf("%d\n", value );
    free (p);
}

void list_delete_last( struct List *L )                                 // delete last node
{
    int value;
    struct node *p = L->head;
    struct node *x = NULL;
    while( p->next != NULL )
    {
        x = p;
        p = p->next;
    }   
    x->next = NULL;
    value = p->data;
    printf("%d\n", value );
    free (p);

}

struct node*  list_search( struct List *L, int k )                      // search a particular node
{
    struct node *p = L->head;

    while( p != NULL )
    {
        if( k == p->data )
            return p;
        p = p->next;
    }
    return NULL;
}

int main()
{
    int k, x, y;
    char c;

    struct List L;
    L.head = NULL;

restart:

    scanf( "%c", &c );

    if( c == 'f' )
    {
        scanf( "%d", &x );
        list_insert_front( &L, create_node(x) );
    }

    if( c == 't' )
    {
        scanf( "%d", &x );
        list_insert_tail( &L, create_node(x) );
    }

    if( c == 'a' )
    {
        scanf( "%d %d", &x, &y );
        list_insert_after( &L, create_node(x) , list_search(&L, y) );

    }

    if( c == 'b' )
    {
        scanf( "%d %d", &x, &y );
        list_insert_before( &L, create_node(x) , list_search(&L, y) );
    }

    if( c == 'd' )
    {
        scanf( "%d", &x );
        list_delete( &L , list_search(&L, x) );
    }

    if( c == 'i' )
    {
        list_delete_first(&L);
    }

    if( c == 'l' )
    {
        list_delete_last(&L);
    }

    if( c == 's' )
    {
        scanf( "%d", &k );
        if( list_search( &L, k ) != NULL )
        printf("1\n");
        else
        printf("-1\n");

    }

    if( c != 'e' )
        goto restart;
    return 0;
}