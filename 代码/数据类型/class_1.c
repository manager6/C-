#include <stdio.h>
int num = 20;

int main()
{
    // 向系统申请一块内存空间，空间名位num，存放整型数据
    int num;
    // 内存中存放数据 10
    num = 10;
    // 输出函数，整型类型输出为%d
    // \n代表的时换行
    // 运行printf时 会访问 num的内存空间 读取空间中的值 让后输出
    printf("%d\n", num);
    return 0;
}
