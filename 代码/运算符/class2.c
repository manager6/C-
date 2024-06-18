#include <stdio.h>

int main()
{
    char ch;

    scanf("%c", &ch);
    if (ch <= 'z' && ch >= 'a')
    {
        printf("%c为小写字母\n", ch);
        ch -= 32;
    }
    else if (ch <= 'Z' && ch >= 'A')
    {
        printf("%c为大写字母\n", ch);
        ch += 32;
    }
    else
    {
        printf("不为字母\n");
    }
    printf("转换后为%c\n", ch);

    return 0;
}