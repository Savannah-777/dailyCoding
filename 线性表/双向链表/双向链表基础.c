#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct node
{
    ElemType data;
    struct node *prev, *next;
} Node;

Node *initList()
// 动态分配初始化
{
    Node *head = (Node *)malloc(sizeof(Node));
    head->data = 0;
    head->next = NULL;
    head->prev = NULL;
    return head;
}

void listNode(Node *L)
// 遍历
{
    Node *p = L->next;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
Node *get_tail(Node *L)
// 获取尾部节点
{
    Node *p = L;
    while (p->next != NULL)
    {
        p = p->next;
    }
    return p;
}
int insertHead(Node *L, ElemType e)
// 头插法
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = e;
    p->prev = L;
    p->next = L->next;
    if (L->next != NULL)
    {
        L->next->prev = p;
    }
    L->next = p;
    return 1;
}
Node *insertTail(Node *tail, ElemType e)
// 尾插法
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = e;
    p->prev = tail;
    tail->next = p;
    p->next = NULL;
    return p;
}

int insertNode(Node *L, int pos, ElemType e)
// 指定位置插入
{
    Node *p = L;
    int i = 0;
    while (i < pos - 1)
    {
        p = p->next;
        i++;
        if (p == NULL)
        {
            return 0;
        }
    }
    Node *q = (Node *)malloc(sizeof(Node));
    q->data = e;
    q->prev = p;
    q->next = p->next;
    p->next->prev = q;
    p->next = q;
    return 1;
}

int deleteNode(Node *L, int pos)
// 删除节点
{
    Node *p = L;
    int i = 0;
    while (i < pos - 1)
    {
        p = p->next;
        i++;
        if (p == NULL)
        {
            return 0;
        }
    }
    if (p->next == NULL)
    {
        printf("要删除的位置错误\n");
        return 0;
    }
    Node *q = p->next;
    p->next = q->next;
    q->next->prev = p;
    free(q);
    return 1;
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

int main()
{
    Node *list = initList();
    insertHead(list, 10);
    insertHead(list, 20);
    insertHead(list, 30);
    listNode(list);

    Node *tail = get_tail(list);
    tail = insertTail(tail, 10);
    tail = insertTail(tail, 20);
    tail = insertTail(tail, 30);
    listNode(list);
    insertNode(list, 2, 15);
    listNode(list);
    deleteNode(list, 3);
    listNode(list);
    return 0;
}