#include <stdio.h>

int findValue(int *arr, int val, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == val)
        {
            return i;
        }
    }
}
int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(int);
    int *p = arr;
    findValue(p, 2, size);
    return 0;
}