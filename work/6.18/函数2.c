#include <stdio.h>
#include <time.h>

void Hour(time_t t)
{
    long int hour = t / 3600;
    printf("转换为小时:\t%ld 小时\n", hour);
}
void Min(time_t t)
{
    long int min = t / 60;
    printf("转换为分钟:\t%ld 分钟\n", min);
}
void Second(time_t t)
{
    printf("转换成秒:\t%ld 秒\n", t);
}
int main()
{
    time_t t;
    struct tm *tmp;

    t = time(NULL); // 获取当前时间的时间戳

    printf("当前时间戳：\t%ld\n", t);
    Hour(t);
    Min(t);
    Second(t);

    return 0;
}
