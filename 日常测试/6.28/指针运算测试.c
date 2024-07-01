#include <stdio.h>

void fun(int arr[10])
{
    int a = sizeof(arr);
    printf("%d\n", a);
}

int main()
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    fun(a);
}