#include <stdio.h>

int main()
{
    int arr[3] = {3 * 0};
    int i;
    for (int i = 0; i < 3; i++)
        scanf("%d", &arr[i]);
    for (int i = 0; i < 3; i++)
        arr[0] = arr[0] + arr[i];
    printf("%d", arr[0]);
    return 0;
}