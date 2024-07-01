#include <stdio.h>

int main()
{
    int arr[10];
    printf("%p\n%p\n%p\n", arr, &arr, &arr[0]);
    return 0;
}