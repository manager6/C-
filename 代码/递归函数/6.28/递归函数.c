#include <stdio.h>

int fun(int n);

int fun(int n)
{
    if (n < 2)

        return n;
    return fun(n - 1) + fun(n - 2);
}
int main()
{
    printf("%d \n", fun(10));
    return 0;
}