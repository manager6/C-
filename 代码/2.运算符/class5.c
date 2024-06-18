#include <stdio.h>
#include <math.h>
int main()
{
    // 类型转换的过程中 int 接收的数据不会进行四舍五入 而是直接舍弃除了整数部分外的数据
    double b = 2.7;
    int a = b;
    printf("%d\n", a);

    int roundedValue = (int)round(b);
    printf("%d\n", roundedValue);

    return 0;
}