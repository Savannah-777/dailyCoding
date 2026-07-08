#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
typedef int ElemType; // 使其具有通用性
typedef struct
{
    ElemType data[MAXSIZE];
    int length;
} SeqList;

SeqList *initList()
{
    SeqList *L = (SeqList *)malloc(sizeof(SeqList));
    // L->data = (ElemType *)malloc(sizeof(ElemType) * MAXSIZE);
    L->length = 0;
    return L;
}

// void initList(SeqList *L) // 栈内存初始化
// {
//     L->length = 0;
//     // 数组不需要初始化，因为写了ElemType data[MAXSIZE];默认开辟了100*400字节空间，但是length没有初始化
// }

int appendElem(SeqList *L, ElemType e)
// 在尾部添加元素
{
    if (L->length >= MAXSIZE)
    {
        printf("顺序表已满\n");
        return 0;
    }
    L->data[L->length] = e;
    L->length++;
    return 1; // 1是成功，0是失败
}

int insertElem(SeqList *L, int pos, ElemType e)
// 插入元素到pos位置，即data[pos-1]
{
    if (L->length >= MAXSIZE)
    {
        printf("表已经满了\n");
        return 0;
    }
    if (pos < 1 || pos > L->length)
    {
        printf("插入位置错误\n");
        return 0;
    }
    if (pos <= L->length) // 核心代码
    {
        for (int i = L->length - 1; i >= pos - 1; i--)
        {
            L->data[i + 1] = L->data[i];
        }
        L->data[pos - 1] = e;
        L->length++;
    }
    return 1;
}

int deleteElem(SeqList *L, int pos, ElemType *e) // 删除数据
{
    if (L->length == 0)
    {
        printf("空表\n");
        return 0;
    }
    if (pos < 1 || pos > L->length)
    {
        printf("删除数据位置有误\n");
        return 0;
    }
    *e = L->data[pos - 1]; //*e用来存储删除的元素（万一需要返回删除的元素时需要）
    if (pos < L->length)   // 核心代码
    {
        for (int i = pos; i < L->length; i++)
        {
            L->data[i - 1] = L->data[i];
        }
    }
    L->length--;
    return 1;
}

void listElem(SeqList *L) // 遍历顺序表
{
    for (int i = 0; i < L->length; i++)
    {
        printf("%d ", L->data[i]);
    }
    printf("\n");
}

int findElem(SeqList *L, ElemType e) // 查找数据位置
{
    if (L->length == 0)
    {
        printf("空列表\n");
        return 0;
    }
    for (int i = 0; i < L->length; i++)
    {
        if (L->data[i] == e)
        {
            return i + 1;
        }
    }
    return 0;
}
int main()
{
    SeqList *list = initList();
    // initList(&list);
    printf("初始化成功，目前长度占用%d\n", list->length);
    printf("目前占用内存%zu字节\n", sizeof(list->data));
    appendElem(list, 88);
    appendElem(list, 45);
    appendElem(list, 43);
    appendElem(list, 17);
    listElem(list);
    insertElem(list, 2, 18);
    listElem(list);
    ElemType delData;
    deleteElem(list, 2, &delData);
    printf("被删除的数据为:%d\n", delData);
    listElem(list);
    printf("%d\n", findElem(list, 45));
    return 0;
}