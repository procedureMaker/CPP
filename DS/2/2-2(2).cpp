#include <stdio.h>
#include <stdlib.h>

// 单链表节点定义
typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode, *LinkList;

// 核心：有序链表归并（LA、LB非递减 → LC非递减）
void MergeLinkList(LinkList LA, LinkList LB, LinkList *LC)
{
    LNode *pa = LA->next; // LA工作指针
    LNode *pb = LB->next; // LB工作指针
    LNode *pc;            // LC工作指针

    *LC = (LinkList)malloc(sizeof(LNode)); // LC头结点
    pc = *LC;

    // 双指针比较，尾插法构建有序LC
    while (pa && pb)
    {
        if (pa->data <= pb->data)
        {
            pc->next = pa;
            pa = pa->next;
        }
        else
        {
            pc->next = pb;
            pb = pb->next;
        }
        pc = pc->next;
    }

    // 直接拼接剩余节点
    pc->next = pa ? pa : pb;

    free(LA); // 释放无用头结点
    free(LB);
}

// 尾插法创建有序链表
void CreateList(LinkList L, int arr[], int n)
{
    LNode *tail = L;
    for (int i = 0; i < n; i++)
    {
        LNode *s = (LNode *)malloc(sizeof(LNode));
        s->data = arr[i];
        s->next = NULL;
        tail->next = s;
        tail = s;
    }
}

// 打印链表
void PrintLinkList(LinkList L)
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
    LinkList LA = (LinkList)malloc(sizeof(LNode));
    LinkList LB = (LinkList)malloc(sizeof(LNode));
    LinkList LC;
    LA->next = NULL;
    LB->next = NULL;

    // 有序数据
    int a[] = {1, 3, 5, 7};
    int b[] = {2, 4, 6, 8, 9};
    CreateList(LA, a, 4);
    CreateList(LB, b, 5);

    printf("LA有序：");
    PrintLinkList(LA);
    printf("LB有序：");
    PrintLinkList(LB);

    MergeLinkList(LA, LB, &LC);

    printf("LC归并后有序：");
    PrintLinkList(LC);
    return 0;
}