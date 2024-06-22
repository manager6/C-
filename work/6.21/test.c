#include <stdio.h>

int main()
{
    int a = 5, *p;
    //*p = a;
    p = &a;
    printf("%d ", *p);

    return 0;
}