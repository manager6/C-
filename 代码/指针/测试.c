#include <stdio.h>
void update(int *a)
{
    *a = 20;
}

int main()
{
    char *str[] = {"a", "b", "cad", "d"};
    char **q;
    q = str + 2;
    printf("%p %p\n", *(str)[2], str + 2);
    return 0;
}