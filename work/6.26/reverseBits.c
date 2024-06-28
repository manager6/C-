#include <stdio.h>

// 打印整数的二进制表示
void printBinary(unsigned int num)
{
    int bitSize = sizeof(num) * 8; // 获取 num 的位数（通常是 32 位）

    for (int i = bitSize - 1; i >= 0; i--)
    {
        printf("%u", (num >> i) & 1);
    }
    printf("\n");
}
unsigned int reverseBits(unsigned int num)
{
    unsigned int reversed = 0;
    int bitSize = sizeof(num) * 8; // 获取 num 的位数（通常是 32 位）

    for (int i = 0; i < bitSize; i++)
    {
        reversed = (reversed << 1) | (num & 1); // 将 num 的最低位添加到 reversed 的最低位
        num >>= 1;                              // 将 num 右移一位
    }

    return reversed;
}

int main()
{
    unsigned int num;
    printf("请输入一个整数: ");
    scanf("%u", &num);

    printf("整数的二进制表示: ");
    int result = reverseBits(num);
    printBinary(result);

    return 0;
}
