#include <stdio.h>
void swap(int **a, int **b)
{
    int temp = **a;
    **a = **b;
    **b = temp;
}
int main()
{

    int a = 10;
    int b = 20;
    int *p = &a;
    int *q = &b;
    int **m = &p;
    int **n = &q;
    swap(m, n);
    printf("a=%d b=%d ", a, b);
    return 0;
}