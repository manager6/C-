#include <stdio.h>
void multiplicationTable(int num)
{
    for (int i = 1; i < num + 1; i++)
    {
        for (int j = 1; j < i + 1; j++)
        {
            printf("%d*%d=%d ", i, j, i * j);
        }
        printf("\n");
    }
}
int main()
{
    multiplicationTable(5);
    return 0;
}