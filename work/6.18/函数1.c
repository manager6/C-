#include <stdio.h>

void caseConversionint(char *str_1, char *str_2, int strSize)
{
    // str_1 是原数组 str_2是赋值后的数组
    for (int i = 0; i < strSize; i++)
    {
        // 先将str_1数组的每一个值拿出来进行判断大小 大写+32 小写-32 然后再赋值给str_2
        if (*str_1 >= 'A' && *str_1 <= 'Z')
        {
            *str_2 = *str_1 + 32;
        }
        else if (*str_1 >= 'a' && *str_1 <= 'z')
        {
            *str_2 = *str_1 - 32;
        }
        // 循环完之后进行++ 自增
        str_1++;
        str_2++;
    }
}
int main()
{
    char a[9] = "QWERabcd";
    int size = sizeof(a) / sizeof(char);
    char b[9];
    caseConversionint(a, b, size);
    int i = 0;
    while (b[i] != '\0')
    {
        printf("%c", b[i]);
        i++;
    }
    printf("\n");
    return 0;
}