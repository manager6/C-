#include <stdio.h>

int findValue(int arr[], int size, int value)
{
    // 在此处编写你的代码
    for (int i = 0; i < size; i++)
    {
        if (value == arr[i])
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    int value = 5;
    int index = findValue(arr, size, value);
    if (index != -1)
    {
        printf("Value %d found at index %d\n", value, index);
    }
    else
    {
        printf("Value %d not found in the array.\n", value);
    }
    return 0;
}
