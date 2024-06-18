#include <stdio.h>

void disassemble(int num)
{
    int shi = num / 10;
    int ge = num % 10;
    printf("%d  %d  %d ", num, shi, ge);
}
void disassemblePlus(int number)
{
    int digit;

    // 通过循环和取余操作拆解多位数
    while (number > 0)
    {
        digit = number % 10;   // 取得最低位的数字
        printf("%d\n", digit); // 打印这一位的数字
        number = number / 10;
    }
}

int main()
{
    int num;
    scanf("%d", &num);
    // disassemble(num);
    disassemblePlus(num);
    return 0;
}