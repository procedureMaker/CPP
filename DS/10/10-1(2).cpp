#include <bits/stdc++.h>
#define Max 10
using namespace std;

typedef struct
{
    // data[0] 是哨兵位！有效元素从 data[1] 开始
    int data[Max + 1];
    int length;
} *SqList;

// 带哨兵的插入排序（你要的函数）
void InsertSort(SqList &L)
{
    int i, j;
    // 从第 2 个有效元素开始排序（i 从 2 到 L->length）
    for (i = 2; i <= L->length; i++)
    {
        // 哨兵：把待插入元素放到 0 号位置
        L->data[0] = L->data[i];
        j = i - 1;

        // 不用判断 j >= 0！哨兵自动终止循环
        while (L->data[j] > L->data[0])
        {
            L->data[j + 1] = L->data[j]; // 元素后移
            j--;
        }

        // 插入到正确位置
        L->data[j + 1] = L->data[0];
    }
}

// 打印顺序表（有效元素从 1 开始）
void PrintSqList(SqList L)
{
    for (int i = 1; i <= L->length; i++)
    {
        cout << L->data[i] << " ";
    }
    cout << endl;
}

int main()
{
    // 初始化顺序表
    SqList L;
    L->length = 5; // 5 个有效元素

    // 赋值：元素从 data[1] 开始
    L->data[1] = 12;
    L->data[2] = 11;
    L->data[3] = 13;
    L->data[4] = 5;
    L->data[5] = 6;

    cout << "排序前：";
    PrintSqList(L);

    // 调用插入排序（带哨兵）
    InsertSort(L);

    cout << "排序后：";
    PrintSqList(L);

    return 0;
}