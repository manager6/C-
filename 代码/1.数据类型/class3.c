#include <stdio.h>

int main()
{
    short s_date = 10000;
    printf("%hd\n", s_date);

    unsigned short s_date2;
    printf("输入一个数:");
    scanf("%hd", &s_date2);
    printf("%hd\n", s_date2);

    return 0;
}