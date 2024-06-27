#include <stdio.h>
int b;
void main()
{
    int a[][4] = {{12, 312, 32, 442}, {1, 2, 3, 4}};
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d ", a);
        }
    }
}