#include <stdio.h>

// 带哨兵的插入排序
// 注意：有效元素从 arr[1] 开始，arr[0] 是哨兵
void insertionSortWithSentinel(int arr[], int n)
{
    int i, j;

    // 从第 2 个有效元素开始（下标1是第一个，所以i从2开始）
    for (i = 2; i <= n; i++)
    {
        arr[0] = arr[i]; // 哨兵：保存当前要插入的元素
        j = i - 1;       // 从前面一个元素开始比较

        // 不用写 j >= 0！哨兵帮我们防止越界
        while (arr[j] > arr[0])
        {
            arr[j + 1] = arr[j]; // 元素后移
            j--;
        }

        arr[j + 1] = arr[0]; // 插入到正确位置
    }
}

// 打印数组（有效元素从1开始）
void printArray(int arr[], int n)
{
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    // 带哨兵的数组：arr[0]空置，元素从1开始放
    int arr[6] = {0, 12, 11, 13, 5, 6};
    int n = 5; // 有效元素个数（从1~5）

    printf("排序前：");
    printArray(arr, n);

    insertionSortWithSentinel(arr, n);

    printf("排序后：");
    printArray(arr, n);

    return 0;
}