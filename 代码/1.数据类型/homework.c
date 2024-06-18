#include <stdio.h>
#include <stdbool.h>
int main()
{
    // 各个类型的数据 地址进行加减 就是根据字节大小进行移位
    // 移位大小为 （移位量）*(数据类型)所占空间字节大小
    int a = 10;
    char b = 'a';
    short c = 11;
    // 因为 数据存储在空间中是连续的 所以 数据名取地址就是数据的首地址

    //  int
    printf("int类型 \t%p\n", &a);
    printf("int + 1 \t%p\n", &a + 1);
    printf("int - 1 \t%p\n", &a - 1);

    // char
    printf("char类型\t%p\n", &b);
    printf("char + 1\t%p\n", &b + 1);
    printf("char - 1\t%p\n", &b - 1);

    // short
    printf("short类型\t%p\n", &c);
    printf("short + 1\t%p\n", &c + 1);
    printf("short - 1\t%p\n", &c - 1);

    return 0;
}