#include <stdio.h>

// 插入排序函数（普通数组）
// arr：待排序数组  n：数组长度
void insertionSort(int arr[], int n)
{
    // 从第2个元素开始遍历（下标1），前面默认已有序
    for (int i = 1; i < n; i++)
    {
        // 保存当前要插入的元素
        int key = arr[i];
        // j 指向已排序部分的最后一个元素
        int j = i - 1;

        // 向前查找插入位置：比key大的元素都往后移
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j]; // 元素后移
            j--;
        }
        // 找到位置，插入key
        arr[j + 1] = key;
    }
}

// 打印数组
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    // 待排序数组
    int arr[] = {12, 11, 13, 5, 6};
    // 计算数组长度
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("排序前：");
    printArray(arr, n);

    // 调用插入排序
    insertionSort(arr, n);

    printf("排序后：");
    printArray(arr, n);

    return 0;
}