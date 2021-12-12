#include "list.h"
#include <stdlib.h>

void CreateList(ListType *L)
{
    L->head=NULL;
    L->size=0;
}

int EmptyList(ListType L)
{
    return(L.head==NULL);
}

int FullList(ListType L)
{
    return 0;
}

int listSize(ListType L)
{
    return L.size;
}

void Insert(EntryType item ,ListType *L, int pos)
{
    Node *p=(Node*)malloc(sizeof(Node));
    p->info=item;
    if(pos==0)
    {
        p->next=L->head;
        L->head=p;
        L->size++;
    }
    else
    {
        Node *q;
        int i;
        for(q=L->head,i =0;i<pos-1;i++)
            q=q->next;
        p->next=q->next;
        q->next=p;
        L->size++;
    }
}

void Retrieve(EntryType *item,ListType *L,int pos)
{
    Node *temp, *q;
    int i;
    if(pos==0)
    {
        *item=(L->head)->info;
        temp=L->head;
        L->head=(L->head)->next;
        free(temp);
        L->size--;
    }
    else
    {
        for(i=0,q=L->head;i<pos-1;i++)
            q=q->next;
        *item=q->next->info;
        temp=q->next;
        q->next=temp->next;
        free(temp);
        L->size--;
    }
}

void ClearList(ListType *L)
{
    Node *q;
    L->size=0;
    while(L->head)
    {
        q=L->head;
        L->head=(L->head)->next;
        free(q);
    }
}

//sheet 5
//1
EntryType FirstElement(ListType *L)
{
    Node *temp;
    EntryType item;

    item=(L->head)->info;
    temp=L->head;
    L->head=temp->next;
    free(temp);
    L->size--;
    return item;
}

//2
EntryType CopyElement(ListType L,int pos)
{
    Node *q;
    int i;

    for(i=0,q=L.head;i<pos;i++)
        q=q->next;
    return q->info;
}

//4
void CopyList(ListType l,ListType *newL)
{
    Node *q;
    int i;
    *newL=l;
    //newL->head=l.head;
    //newL->size=l.size;
    for(i=0,q=l.head;i<=l.size;i++)
    {
        q->info=(l.head)->info;
        q->next=(l.head)->next;
    }
}
