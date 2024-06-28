#include <stdio.h>
#include <stdlib.h>

void *fun();

void *fun()
{
    int(*arr)[15] = (int(*)[])malloc(sizeof(int) * 15);
    if (arr == (int(*)[])NULL)
    {
        perror("分配空间失败...");
        return (void *)-1;
    }

    (*arr)[7] = 666;
    (*arr)[8] = 555;
    arr[0][6] = 222;
    return (int(*)[])arr;
}

int main()
{

    int(*result)[] = /*(int(*)[])*/ fun();
    if (result == (int(*)[]) - 1)
    {
        return -1;
    }
    printf("%d\n", (*result)[7]);
    printf("%d\n", (*result)[8]);
    printf("%d\n", (*result)[6]);
    free(result);
    return 0;
}