#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 单链表节点定义
typedef struct Node
{
    int data;
    struct Node *next;
} LNode, *LinkList;

// 查找元素：存在返回true，不存在返回false
bool findElem(LinkList L, int e)
{
    LNode *p = L->next; // 跳过头结点
    while (p)
    {
        if (p->data == e)
            return true;
        p = p->next;
    }
    return false;
}

// 尾部插入元素
void insertTail(LinkList L, int e)
{
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = NULL;

    // 找到尾节点
    LNode *p = L;
    while (p->next)
        p = p->next;
    p->next = s;
}

// 核心：合并 LB 到 LA（去重）
void mergeLinkList(LinkList LA, LinkList LB)
{
    LNode *p = LB->next; // 遍历 LB
    while (p)
    {
        int e = p->data;
        if (!findElem(LA, e))
        {
            insertTail(LA, e);
        }
        p = p->next;
    }
}

// 创建链表（尾插法，方便初始化）
void createList(LinkList L, int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        insertTail(L, arr[i]);
    }
}

// 打印链表
void printLinkList(LinkList L)
{
    LNode *p = L->next;
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    // 创建头结点
    LinkList LA = (LNode *)malloc(sizeof(LNode));
    LinkList LB = (LNode *)malloc(sizeof(LNode));
    LA->next = NULL;
    LB->next = NULL;

    // 初始化数据
    int a[] = {1, 3, 5};
    int b[] = {2, 3, 6, 1};
    createList(LA, a, 3);
    createList(LB, b, 4);

    printf("LA 原始：");
    printLinkList(LA);
    printf("LB 原始：");
    printLinkList(LB);

    mergeLinkList(LA, LB);

    printf("合并后 LA：");
    printLinkList(LA);
    return 0;
}