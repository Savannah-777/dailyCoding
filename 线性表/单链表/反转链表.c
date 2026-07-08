#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct node
{
    ElemType data;
    struct node *next;
} Node;

Node *initList();
Node *reverseList(Node *head)
{
    Node *first = NULL;
    Node *second = head->next;
    Node *third;
    head->next = NULL;
    while (second != NULL)
    {
        third = second->next;
        second->next = first;
        first = second;
        second = third;
    }
    head->next = first;
    return head;
}

Node *initList()
{
    Node *head = (Node *)malloc(sizeof(Node));
    head->data = 0;
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
int main()
{
    Node *list = initList();
    insertHead(list, 1);
    insertHead(list, 2);
    insertHead(list, 3);
    insertHead(list, 4);
    insertHead(list, 5);
    insertHead(list, 6);
    insertHead(list, 7);
    listNode(list);
    reverseList(list);
    listNode(list);
    return 0;
}