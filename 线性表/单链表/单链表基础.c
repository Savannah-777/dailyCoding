#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct node
{
    ElemType data;
    struct node *next;
} Node;

Node *initList()
{
    Node *head = (Node *)malloc(sizeof(Node));
    head->data = 0;
    head->next = NULL;
    return head;
}
Node *initListWithElem(ElemType e)
{
    Node *head = (Node *)malloc(sizeof(Node));
    head->data = e;
    head->next = NULL;
    return head;
}
Node *insertHead(Node *L, ElemType e)
{
    Node *p = (Node *)malloc(sizeof(Node));
    if (p == NULL)
        return NULL;
    p->data = e;
    p->next = L->next;
    L->next = p;
    return L;
}
Node *insertHeadWithNode(Node *L, Node *New)
{
    New->next = L->next;
    L->next = New;
    return L;
}
Node *insertTail(Node *tail, ElemType e)
{
    Node *q = (Node *)malloc(sizeof(Node));
    q->data = e;
    tail->next = q;
    q->next = NULL;
    return q;
}
void insertTailWithNode(Node *tail, Node *New)
{
    tail->next = New;
    New->next = NULL;
}
Node *get_tail(Node *L)
{
    Node *p = L;
    while (p->next != NULL)
    {
        p = p->next;
    }
    return p;
}
Node *insertNode(Node *L, int pos, ElemType e)
{
    Node *p = L;
    int i = 0;
    while (i < pos - 1)
    {
        p = p->next;
        i++;
        if (p == NULL)
            return NULL;
    }
    Node *q = (Node *)malloc(sizeof(Node));
    q->data = e;
    q->next = p->next;
    p->next = q;
    return L;
}
Node *deleNode(Node *L, int pos)
{
    Node *p = L;
    int i = 0;
    while (i < pos - 1)
    {
        p = p->next;
        i++;
        if (p == NULL)
            return NULL;
    }
    if (p->next == NULL)
    {
        printf("ɾ����λ�ò���ȷ\n");
        return NULL;
    }
    Node *q = p->next;
    p->next = q->next;
    free(q);
    return L;
}
void listNode(Node *L)
{
    Node *p = L->next;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
int listLength(Node *L)
{
    Node *p = L;
    int len = 0;
    while (p != NULL)
    {
        p = p->next;
        len++;
    }
    return len;
}
void freeList(Node *L)
{
    Node *p = L->next;
    Node *q;
    while (p != NULL)
    {
        q = p->next;
        free(p);
        p = q;
    }
    L->next = NULL;
}

Node *initList();                         //
Node *initListWithElem(ElemType e);       //
Node *insertTail(Node *tail, ElemType e); //
void insertTailWithNode(Node *tail, Node *New);
Node *insertHead(Node *L, ElemType e);        //
Node *insertHeadWithNode(Node *L, Node *New); //
Node *get_tail(Node *L);                      //
Node *insertNode(Node *L, int pos, ElemType e);
Node *deleNode(Node *L, int pos);
void listNode(Node *L);  //
int listLength(Node *L); //
void freeList(Node *L);  //

int main()
{
    Node *List = initList();
    Node *List2 = initListWithElem(3);

    insertHead(List, 1);
    insertHead(List, 2);
    insertTail(get_tail(List), 3);
    insertTail(get_tail(List), 4);
    listNode(List);
    insertNode(List, 2, 100);
    listNode(List);
    printf("List%d\n", listLength(List));
    deleNode(List, 3);
    listNode(List);
    printf("List%d\n", listLength(List));
    freeList(List);

    Node *New = (Node *)malloc(sizeof(Node));
    New->data = 99;
    insertHeadWithNode(List2, New);
    listNode(List2);
    printf("List2%d\n", listLength(List2));
    freeList(List2);
    return 0;
}