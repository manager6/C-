#include <stdio.h>

// 插入排序
void insertionSort(int *arr, int size)
{
    for (int i = 1; i < size; i++)
    {
        // 默认数组第一位数据为以排序数据
        //  将需要插入的元素赋值给base，令j追踪已排序区间的最后一位
        int base = arr[i], j = i - 1;
        while (j >= 0 && arr[j] > base)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = base;
    }
}
int main()
{
    int arr[] = {2, 4, 1, 9, 8, 6, 5, 7};
    insertionSort(arr, 8);
    for (int i = 0; i < 8; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}