#include <stdio.h>
#include <stdlib.h>

/*譬如有以下字符串数据：Gooogle，写一份代码实现消邻功能. Gooogle 变成 Gogle */
#define ARRAY_LENGTH(str) (sizeof(str) / sizeof(str[0]))

char *NeighborhoodElimination(char *str)
{
    int count = 0;
    // 分配的空间 必定大于或者等于原来的数组
    char *newStr = (char *)malloc(ARRAY_LENGTH(str) + 1);
    while (*str != '\0')
    {
        int isDuplicate = 0;
        for (int i = 0; i < count; i++)
        {
            if (*str == newStr[i])
            {
                isDuplicate = 1;
                break;
            }
        }
        if (!isDuplicate)
        {
            newStr[count++] = *str; // count 记录存入字符的长度
        }
        str++;
    }
    newStr[count] = '\0'; // 添加字符串结束符
    return newStr;
}
int main()
{
    char str[8] = "Gooogle";
    int i = 0;
    printf("消邻前:");
    while (str[i] != '\0')
    {
        printf("%c", str[i]);
        i++;
    }
    printf("\n");
    printf("消邻后:");
    char *newStr = NeighborhoodElimination(str);
    while (*newStr != '\0')
    {
        printf("%c", *newStr);
        newStr++;
    }
    printf("\n");

    return 0;
}