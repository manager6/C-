#include <stdio.h>

void sort(int (*arr)[12]);
void sort(int (*arr)[12])
{
    int len = sizeof(*arr) / sizeof(int);
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            if ((*arr)[i] > (*arr)[j])
            {
                int temp = (*arr)[i];
                (*arr)[i] = (*arr)[j];
                (*arr)[j] = temp;
            }
        }
    }
}
int main()
{
    int arr[12] = {2, 6, 8, 0, 221, 342, 323, 4, 9, 12, 3, 212};
    int(*arr_sort)[12] = NULL;
    arr_sort = &arr;
    printf("排序前:\n");
    for (int i = 0; i < 12; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    sort(arr_sort);
    printf("排序后:\n");
    for (int i = 0; i < 12; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}