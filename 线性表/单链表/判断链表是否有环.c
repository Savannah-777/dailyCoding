#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct node
{
    ElemType data;
    struct node *next;
} Node;

int isCycle(Node *head)
{
    Node *fast = head;
    Node *slow = head;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
        {
            return 1;
        }
    }
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
Node *initListWithElem(ElemType e)
// 动态分配初始化(带数据域)
{
    Node *head = (Node *)malloc(sizeof(Node));
    head->data = e;
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
Node *insertHeadWithNode(Node *L, Node *New)
// 头插法(插入节点)
{
    New->next = L->next;
    L->next = New;
    return L;
}
Node *insertTail(Node *tail, ElemType e)
// 尾插法
{
    Node *q = (Node *)malloc(sizeof(Node));
    q->data = e;
    tail->next = q;
    q->next = NULL;
    return q;
}
void insertTailWithNode(Node *tail, Node *New)
// 尾插法(插入节点)
{
    tail->next = New;
    New->next = NULL;
}
Node *get_tail(Node *L)
// 返回尾节点
{
    Node *p = L;
    while (p->next != NULL)
    {
        p = p->next;
    }
    return p;
}
Node *insertNode(Node *L, int pos, ElemType e)
// 指定位置插入节点
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
// 删除节点
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
        printf("删除的位置不正确\n");
        return NULL;
    }
    Node *q = p->next;
    p->next = q->next;
    free(q);
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
int listLength(Node *L)
// 获取链表长度
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
// 释放链表
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

    Node *tail = get_tail(list);

    tail = insertTail(tail, 1);
    tail = insertTail(tail, 2);
    tail = insertTail(tail, 3);
    Node *three = tail; // 在3这里重新有一个节点
    tail = insertTail(tail, 4);
    tail = insertTail(tail, 5);
    tail = insertTail(tail, 6);
    tail = insertTail(tail, 7);
    tail = insertTail(tail, 8);
    tail->next = three;

    // listNode(list);

    if (isCycle(list))
    {
        printf("有环\n");
    }
    else
    {
        printf("无环\n");
    }
    return 0;
}