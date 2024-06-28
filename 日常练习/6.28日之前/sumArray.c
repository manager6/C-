#include <stdio.h>

int sumArray(int arr[], int size)
{
    int sum = 0;
    // 在此处编写你的代码
    for (int i = 0; i < size; i++)
    {
        sum = sum + arr[i];
    }
    return sum;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int result = sumArray(arr, size);
    printf("Sum of array elements: %d\n", result);
    return 0;
}
