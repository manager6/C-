#include <stdio.h>

void printBinary(unsigned int number)
{
    if (number > 1)
    {
        printBinary(number >> 1);
    }
    printf("%d", number & 1);
}
int main()
{
    int number;
    scanf("%d", &number);
    printBinary(number);
    printf("\n");
    return 0;
}