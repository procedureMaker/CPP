#include <stdio.h>
#include <stdbool.h>

#define MAXSIZE 100 // 数组最大容量

// 有序顺序表结构定义
typedef struct
{
    int data[MAXSIZE];
    int length; // 有效元素个数
} SqList;

// 核心：有序表归并（LA、LB非递减 → LC非递减）
void MergeSqList(SqList LA, SqList LB, SqList *LC)
{
    int i = 0, j = 0, k = 0;
    // 双指针遍历，逐个比较取小值
    while (i < LA.length && j < LB.length)
    {
        if (LA.data[i] <= LB.data[j])
        {
            LC->data[k++] = LA.data[i++];
        }
        else
        {
            LC->data[k++] = LB.data[j++];
        }
    }
    // 处理 LA 剩余元素
    while (i < LA.length)
    {
        LC->data[k++] = LA.data[i++];
    }
    // 处理 LB 剩余元素
    while (j < LB.length)
    {
        LC->data[k++] = LB.data[j++];
    }
    LC->length = k; // 更新LC长度
}

// 打印顺序表
void PrintSqList(SqList L)
{
    for (int i = 0; i < L.length; i++)
    {
        printf("%d ", L.data[i]);
    }
    printf("\n");
}

int main()
{
    // 初始化有序表（非递减）
    SqList LA = {{1, 3, 5, 7, 9}, 5};
    SqList LB = {{2, 4, 6, 8, 10}, 5};
    SqList LC; // 归并结果

    printf("LA有序：");
    PrintSqList(LA);
    printf("LB有序：");
    PrintSqList(LB);

    MergeSqList(LA, LB, &LC);

    printf("LC归并后有序：");
    PrintSqList(LC);
    return 0;
}