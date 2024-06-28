#include <stdio.h>

int main()
{
    char *ch[] = {"123", "234", "32333"};

    printf("%d", *ch[2]);
    return 0;
}