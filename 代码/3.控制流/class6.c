#include <stdio.h>
void function1()
{
    int count = 2;
    do
    {
        int flag = 1;
        for (int i = 2; i < count; i++)
        {
            if (count % i == 0)
            {
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            printf("%d\n", count);
        }
        count++;
    } while (count < 100);
}
void function2(int count)
{
    int flag = 1;
    for (int i = 2; i < count; i++)
    {
        if (count % i == 0)
        {
            flag = 0;
            break;
        }
    }
    if (flag)
    {
        printf("%d\n", count);
        return;
    }
    printf("%d不是质数\n", count);
}
int main()
{
    int num = 0;
    scanf("%d", &num);
    // function1();
    function2(num);
    return 0;
}
