#include <stdio.h>
#include <string.h>

// strcpy memcpy 等函数使用
int main()
{
    char ch[] = "hello"; // 这种方式初始化数组 编译器会自动在结尾补充 `\0`
    int str_1 = strlen(ch);
    int str_2 = sizeof(ch);
    int date_1 = 10;
    int date_2 = 20;

    memcpy(&date_1, &date_2, 1);
    printf("%d %d %s %d %d", date_1, date_2, ch, str_1, str_2);

    return 0;
}