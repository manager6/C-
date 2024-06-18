#include <stdio.h>
#include <sys/time.h>
/*
    公鸡 设为x 1值5钱  母鸡 设为y 1值3钱 雏鸡 设为z 3值1钱
    一百钱买一百只鸡
    各买几只

    公式1 5x+3y+z/3=100  公式2 x+y+z=100
    1. x= 100-y-z
    2. 代入1 5(100-y-z)+3y+z/3=100
    3. 500-5y-5z+3y+z/3=100 --> 1200-6y-14z=0
*/
void CalculatedQuantity_1()
{
    for (int x = 0; x < 100; x++)
    {
        for (int y = 0; y < 100; y++)
        {
            for (int z = 0; z < 100; z++)
            {
                if (x + y + z == 100 && 5 * x + 3 * y + z / 3 == 100 && z % 3 == 0)
                {
                    printf("公鸡%d 母鸡%d 雏鸡%d\n", x, y, z);
                }
            }
        }
    }
}
void CalculatedQuantity_2()
{
    for (int x = 1; x < 20; x++)
    {
        for (int y = 1; y < 33; y++)
        {
            int z = 100 - x - y;
            if (x + y + z == 100 && 5 * x + 3 * y + z / 3 == 100 && z % 3 == 0)
            {
                printf("公鸡%d 母鸡%d 雏鸡%d\n", x, y, z);
            }
        }
    }
}
int main()
{
    struct timeval start, end;
    long seconds, useconds;
    double mtime;

    gettimeofday(&start, NULL);

    CalculatedQuantity_2();

    gettimeofday(&end, NULL);

    seconds = end.tv_sec - start.tv_sec;
    useconds = end.tv_usec - start.tv_usec;
    mtime = ((seconds) * 1000 + useconds / 1000.0);

    printf("程序运行时间: %f 毫秒\n", mtime);

    return 0;
}
