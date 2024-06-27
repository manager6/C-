#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *arr = NULL;
    size_t size = 5;
    size_t new_size = 10;

    // 初次分配
    arr = realloc(NULL, size * sizeof(int));
    if (arr == NULL)
    {
        fprintf(stderr, "初次内存分配失败\n");
        return EXIT_FAILURE;
    }

    // 初始化数组
    for (size_t i = 0; i < size; ++i)
    {
        arr[i] = i + 1;
    }

    // 打印数组
    for (size_t i = 0; i < size; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // 增大内存块
    int *temp = realloc(arr, new_size * sizeof(int));
    if (temp == NULL)
    {
        fprintf(stderr, "内存重新分配失败\n");
        free(arr); // 释放原来的内存
        return EXIT_FAILURE;
    }
    arr = temp;

    // 初始化新分配的内存
    for (size_t i = size; i < new_size; ++i)
    {
        arr[i] = 0; // 初始化新内存
    }

    // 打印数组
    for (size_t i = 0; i < new_size; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // 释放内存
    free(arr);

    return EXIT_SUCCESS;
}
