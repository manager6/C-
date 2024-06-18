#include <stdio.h>

void drawCustomRectangle(int width, int height)
{
    int i, j;
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            if (i == 0 || i == height - 1 || j == 0 || j == width - 1)
            {
                printf("🥚");
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
    drawCustomRectangle(10, 5); // 自定义宽度和高度
    return 0;
}
