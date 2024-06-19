#include <stdio.h>
#define ARRAY_LENGTH(arr) (sizeof(arr) / sizeof(arr[0]))

int fact(int n)
{
    if (n == 0)
        return 1;
    return n * fact(n - 1);
}
int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    char str[4] = "qwer";
    printf("%ld\n", ARRAY_LENGTH(arr));
    printf("%ld\n", ARRAY_LENGTH(str));

    printf("%d\n", fact(5));

    return 0;
}
