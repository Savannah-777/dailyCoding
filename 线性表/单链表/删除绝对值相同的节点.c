#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef int ElemType;
typedef struct node
{
    ElemType data;
    struct node *next;
} Node;

void removeNode(Node *L, int n)
{
    Node *p = L;
    int index;
    int *q = (int *)malloc(sizeof(int) * (n + 1));
    for (int i = 0; i < n + 1; i++)
    {
        *(q + i) = 0;
    }
    while (p->next != NULL)
    {
        index = abs(p->next->data);
        if (*(q + index) == 0)
        {
            *(q + index) = 1;
            p = p->next;
        }
        else
        {
            Node *temp = p->next;
            p->next = temp->next;
            free(temp);
        }
    }
    free(q);
}
Node *initList()
// 动态分配初始化
{
    Node *head = (Node *)malloc(sizeof(Node));
    head->data = 0;
    head->next = NULL;
    return head;
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
Node *insertTail(Node *tail, ElemType e)
// 尾插法
{
    Node *p = (Node *)malloc(sizeof(Node));
    if (p == NULL)
        return NULL;
    p->data = e;
    p->next = NULL;
    tail->next = p;
    return p;
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
    Node *tail = get_tail(list);
    tail = insertTail(tail, 21);
    tail = insertTail(tail, -15);
    tail = insertTail(tail, -15);
    tail = insertTail(tail, 7);
    tail = insertTail(tail, 15);
    tail = insertTail(tail, 21);
    listNode(list);

    removeNode(list, 21);
    printf("删除绝对值相同的节点之后：");
    listNode(list);
    return 0;
}