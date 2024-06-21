#include <stdio.h>
#include <string.h>

int YEsNo(int a, int b)
{
    static int m = 0, n = 2;
    n += m + 1;
    m = n + a + b;
    return m;
}
int main()
{
    int a = 1, b = 2;
    int p;
    p = YEsNo(a, b);
    printf("%d\n", p);
    p = YEsNo(a, b);
    printf("%d\n", p);
    return 0;
}