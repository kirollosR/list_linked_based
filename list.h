#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

typedef char EntryType;

typedef struct node
{
    EntryType info;
    struct node *next;
}Node;

//typedef Node *ListType;
typedef struct
{
    Node *head;
    int size;
}ListType;

void CreateList(ListType *);
int EmptyList(ListType);
int FullList(ListType);
int listSize(ListType );
void Insert(EntryType ,ListType *, int);
void Retrieve(EntryType *,ListType *,int);
void ClearList(ListType *);
EntryType FirstElement(ListType *);
EntryType CopyElement(ListType l,int);
void CopyList(ListType ,ListType *);

#endif // LIST_H_INCLUDED
