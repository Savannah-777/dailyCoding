#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct node
{
    ElemType data;
    struct node *next;
} Node;

int delMiddleNode(Node *head)
{
    Node *fast = head;
    Node *slow = head;
    while (fast->next != NULL && fast != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node *q = slow->next;
    slow->next = q->next;
    free(q); // q即为中间节点
    return 1;
}

Node *initList()
// 动态分配初始化
{
    Node *head = (Node *)malloc(sizeof(Node));
    head->data = 0;
    head->next = NULL;
    return head;
}
Node *insertHead(Node *L, ElemType e)
// 头插法
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
// 遍历链表
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
    Node *L = initList();
    insertHead(L, 1);
    insertHead(L, 2);
    insertHead(L, 3);
    insertHead(L, 4);
    insertHead(L, 5);
    insertHead(L, 6);
    insertHead(L, 7);
    listNode(L);

    delMiddleNode(L);
    listNode(L);
    return 0;
}