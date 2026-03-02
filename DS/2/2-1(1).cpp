#include <stdio.h>
#include <stdbool.h>

#define MAXSIZE 100 // 数组最大容量

// 顺序表结构定义
typedef struct
{
    int data[MAXSIZE];
    int length; // 当前有效元素个数
} SqList;

// 查找元素：存在返回下标，不存在返回-1
int findElem(SqList L, int e)
{
    for (int i = 0; i < L.length; i++)
    {
        if (L.data[i] == e)
            return i;
    }
    return -1;
}

// 尾部插入元素（成功返回true，失败返回false）
bool insertElem(SqList *L, int e)
{
    if (L->length >= MAXSIZE)
        return false;
    L->data[L->length++] = e;
    return true;
}

// 核心：合并 LB 到 LA（去重）
void mergeSqList(SqList *LA, SqList LB)
{
    for (int i = 0; i < LB.length; i++)
    {
        int e = LB.data[i];
        if (findElem(*LA, e) == -1)
        {
            insertElem(LA, e);
        }
    }
}

// 打印顺序表
void printSqList(SqList L)
{
    for (int i = 0; i < L.length; i++)
    {
        printf("%d ", L.data[i]);
    }
    printf("\n");
}

int main()
{
    // 初始化 LA: {1,3,5}
    SqList LA = {{1, 3, 5}, 3};
    // 初始化 LB: {2,3,6,1}
    SqList LB = {{2, 3, 6, 1}, 4};

    printf("LA 原始：");
    printSqList(LA);
    printf("LB 原始：");
    printSqList(LB);

    mergeSqList(&LA, LB);

    printf("合并后 LA：");
    printSqList(LA);
    return 0;
}