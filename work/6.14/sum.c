#include <stdio.h>

void gitSum()
{
    int num;
    int sum = 0;
    do
    {
        scanf("%d", &num);
        sum += num; // sum一直累加num 直到循环停止
    } while (num != 0); // 输入0停止循环
    printf("%d\n", sum);
}
int main()
{
    gitSum();

    return 0;
}