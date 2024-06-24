#include <stdio.h>
void my_sort(int *arr, int len)
{
    // 冒泡排序
    int temp;
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int main()
{

    int arr[10] = {3, -1, 2, 1, 14, 23, -6, 7, 4, -10};
    int len = sizeof(arr) / sizeof(arr[0]);
    my_sort(arr, len);
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
}