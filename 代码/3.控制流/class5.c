#include <stdio.h>
#include <math.h>

void drawCustomCircle(int radius)
{
    int i, j;
    for (i = -radius; i <= radius; i++)
    {
        for (j = -radius; j <= radius; j++)
        {
            if (sqrt(i * i + j * j) <= radius)
            {
                printf("o");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main()
{
    drawCustomCircle(15);
    return 0;
}
