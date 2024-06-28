#include <stdio.h>

/*
编写一个函数 merge_sorted_arrays(int arr1[], int size1, int arr2[], int size2, int result[])，
将两个已排序的整数数组 arr1 和 arr2 合并成一个新的有序数组 result。
*/

void merge_sorted_arrays(int arr1[], int size1, int arr2[], int size2, int result[]);

void merge_sorted_arrays(int arr1[], int size1, int arr2[], int size2, int result[])
{
    int i = 0, j = 0, k = 0;
    while (i < size1 && j < size2)
    {
        if (arr1[i] < arr2[j])
        {
            result[k++] = arr1[i++];
        }
        else
        {
            result[k++] = arr2[j++];
        }
    }

    while (i < size1)

    {
        result[k++] = arr1[i++];
    }
    while (j < size2)
    {
        result[k++] = arr2[j++];
    }
}

void printfArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main()
{
    int array1[11] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21};

    int array2[10] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};

    int result[20] = {0};

    merge_sorted_arrays(array1, 11, array2, 10, result);

    printf("Array1: ");
    printfArray(array1, 11);
    printf("Array2: ");
    printfArray(array2, 10);
    printf("Array3: ");
    printfArray(result, 21);

    return 0;
}