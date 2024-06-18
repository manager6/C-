#include <stdio.h>

void Max_number(int num1, int nmb2)
{
    int max = num1 > nmb2 ? num1 : nmb2;
    printf("最大值为:%d\n", max);
}
int main()
{
    int num1, num2;
    scanf("%d %d", &num1, &num2);
    Max_number(num1, num2);
    return 0;
}