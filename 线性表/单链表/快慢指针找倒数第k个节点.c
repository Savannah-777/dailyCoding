#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct node
{
    ElemType data;
    struct node *next;
} Node;

int findNodeFS(Node *L, int k)
{
    Node *fast = L->next;
    Node *slow = L->next;
    for (int i = 0; i < k; i++)
    {
        fast = fast->next;
    }
    while (fast != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }
    printf("倒数第%d个节点值为%d\n", k, slow->data);
    return 0;
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
    Node *list = initList();
    insertHead(list, 1);
    insertHead(list, 2);
    insertHead(list, 3);
    insertHead(list, 4);
    insertHead(list, 5);
    insertHead(list, 6);
    insertHead(list, 7);
    listNode(list);
    findNodeFS(list, 3);
    return 0;
}