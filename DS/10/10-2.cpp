#include <stdio.h>

// 折半插入排序
void binaryInsertSort(int arr[], int n)
{
    int i, j, mid, low, high;
    int key; // 要插入的元素

    // 从第2个元素开始（下标1），前面默认有序
    for (i = 1; i < n; i++)
    {
        key = arr[i]; // 保存当前要插入的数
        low = 0;      // 有序区间左边界
        high = i - 1; // 有序区间右边界

        // 折半查找：找插入位置
        while (low <= high)
        {
            mid = (low + high) / 2; // 中间位置
            if (arr[mid] > key)
            {
                high = mid - 1; // 插入点在左半部分
            }
            else
            {
                low = mid + 1; // 插入点在右半部分
            }
        }

        // 把 high+1 到 i-1 的元素全部后移一位
        for (j = i - 1; j >= high + 1; j--)
        {
            arr[j + 1] = arr[j];
        }

        // 插入到正确位置
        arr[high + 1] = key;
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
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("排序前：");
    printArray(arr, n);

    binaryInsertSort(arr, n);

    printf("排序后：");
    printArray(arr, n);

    return 0;
}