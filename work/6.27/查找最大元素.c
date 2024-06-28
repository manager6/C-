#include <stdio.h>

/*
 编写一个函数 find_max(int *arr, int size)，查找并返回整型数组 arr 中的最大元素。同样要求使用指针访问数组元素
*/
int find_max(int *arr, int size);

int find_max(int *arr, int size)
{
    int max = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}
int main()
{
    int arr[10] = {8, 1, -2, 32, 45, 6, 9, 10, 5, 7};
    int *p = arr;
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    int result = find_max(p, 10);
    printf("%d\n", result);
    return 0;
}