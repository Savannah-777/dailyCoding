#include <stdio.h>
#include <stdlib.h>
typedef char ElemType;
typedef struct node
{
    ElemType data;
    struct node *next;
} Node;

Node *findIntersectionNode(Node *headA, Node *headB)
{
    if (headA == NULL || headB == NULL)
    {
        return NULL;
    }
    Node *p = headA;
    int lenA = 0;
    int lenB = 0;
    while (p != NULL)
    {
        p = p->next;
        lenA++;
    }
    p = headB;
    while (p != NULL)
    {
        p = p->next;
        lenB++;
    }
    int step = 0;
    Node *fast;
    Node *slow;
    if (lenA > lenB)
    {
        step = lenA - lenB;
        fast = headA;
        slow = headB;
    }
    else
    {
        step = lenB - lenA;
        fast = headB;
        slow = headA;
    }
    for (int i = 0; i < step; i++)
    {
        fast = fast->next;
    }
    while (fast != slow)
    {
        fast = fast->next;
        slow = slow->next;
    }
    return fast;
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
Node *insertTail(Node *tail, ElemType e)
// 尾插法
{
    Node *q = (Node *)malloc(sizeof(Node));
    q->data = e;
    tail->next = q;
    q->next = NULL;
    return q;
}
Node *insertTailWithNode(Node *tail, Node *New)
// 尾插法(插入节点)
{
    tail->next = New;
    New->next = NULL;
    return New;
}
void listNode(Node *L)
// 遍历链表
{
    Node *p = L->next;
    while (p != NULL)
    {
        printf("%c ", p->data);
        p = p->next;
    }
    printf("\n");
}
int main()
{
    Node *list1 = initList();
    Node *list2 = initList();
    Node *q = get_tail(list1);
    Node *w = get_tail(list2);
    q = insertTail(q, 'l');
    q = insertTail(q, 'o');
    q = insertTail(q, 'a');
    q = insertTail(q, 'd');
    w = insertTail(w, 'b');
    w = insertTail(w, 'e');

    Node *nodeI = initListWithElem('i');
    q = insertTailWithNode(q, nodeI);
    w = insertTailWithNode(w, nodeI);
    Node *nodeN = initListWithElem('n');
    q = insertTailWithNode(q, nodeN);
    w = insertTailWithNode(w, nodeN);
    Node *nodeG = initListWithElem('g');
    q = insertTailWithNode(q, nodeG);
    w = insertTailWithNode(w, nodeG);

    listNode(list1);
    listNode(list2);

    printf("相交的节点数据为:%c\n", findIntersectionNode(list1, list2)->data);
    return 0;
}