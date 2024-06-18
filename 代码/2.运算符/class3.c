#include <stdio.h>
#include <stdbool.h>
int main()
{

    int num;
    bool flag;
    scanf("%d", &num);
    if (num % 2 == 0)
    {
        flag = true;
    }
    else
    {
        flag = false;
    }
    printf("%d", flag);

    return 0;
}