#include <stdio.h>

int isSorted(int arr[], int size)
{
    // 在此处编写你的代码
    /*     for (int i = 0; i < size; i++)
        {
            for (int j = i; j < size - 1; j++)
            {
                if (arr[i] > arr[j])
                {
                    return 1;
                }
                else
                {
                    return 0;
                }

        } */
    // 修正
    for (int i = 0; i < size; i++)
    {
    }
}

int main()
{
    int arr1[] = {1, 2, 3, 4, 5};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    printf("Array is%s sorted.\n", isSorted(arr1, size1) ? "" : " not");

    int arr2[] = {5, 4, 3, 2, 1};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    printf("Array is%s sorted.\n", isSorted(arr2, size2) ? "" : " not");

    return 0;
}
