#include <stdio.h>

double averageArray(int arr[], int size)
{
    // 在此处编写你的代码
    int sum = 0;
    // 在此处编写你的代码
    for (int i = 0; i < size; i++)
    {
        sum = sum + arr[i];
    }
    double result = sum / size;
    return result;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    double avg = averageArray(arr, size);
    printf("Average of array elements: %.2f\n", avg);
    return 0;
}
