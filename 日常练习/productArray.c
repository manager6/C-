#include <stdio.h>

long long productArray(int arr[], int size)
{
    // 在此处编写你的代码
    long long product = 1;
    for (int i = 0; i < size; i++)
    {
        product *= arr[i];
    }
    return product;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    long long product = productArray(arr, size);
    printf("Product of array elements: %lld\n", product);
    return 0;
}
