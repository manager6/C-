#include <stdio.h>
#include <stdlib.h>

#define MY_MALLOC(TYPE, SIZE) (TYPE *)malloc(sizeof(TYPE) * SIZE)

int main()
{
    int *arr = MY_MALLOC(int, 3);
    if (arr == (int *)NULL)
    {
        perror("123...");
        return -1;
    }
    *arr = 123;
    printf("%d\n", *arr);
    free(arr);

    return 0;
}